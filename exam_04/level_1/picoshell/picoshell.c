#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

#define NO_FD -1
#define FAIL -1
#define READ_PIPE 0
#define WRITE_PIPE 1
#define RET_OK 0
#define RET_ERROR 1

static	void	move_pipe(int src[2], int dest[2])
{
	src[READ_PIPE] = dest[READ_PIPE];
	src[WRITE_PIPE] = dest[WRITE_PIPE];
	dest[READ_PIPE] = NO_FD;
	dest[WRITE_PIPE] = NO_FD;
}

static	void	close_pipe(int fildes[2])
{
	if (fildes[READ_PIPE] != NO_FD)
	{
		close(fildes[READ_PIPE]);
		fildes[READ_PIPE] = NO_FD;
	}
	if (fildes[WRITE_PIPE] != NO_FD)
	{
		close(fildes[WRITE_PIPE]);
		fildes[WRITE_PIPE] = NO_FD;
	}
}

void	dup_fildes(int i, char ***cmds, int *prev_fildes, int *next_fildes)
{
	if (i > 0 && prev_fildes[READ_PIPE] != NO_FD)
	{
		if (dup2(prev_fildes[READ_PIPE], STDIN_FILENO) == FAIL)
		{
			close_pipe(prev_fildes);
			close_pipe(next_fildes);
			exit(EXIT_FAILURE);
		}
	}
	if (cmds[i + 1] && next_fildes[WRITE_PIPE] != NO_FD)
	{
		if (dup2(next_fildes[WRITE_PIPE], STDOUT_FILENO) == FAIL)
		{
			close_pipe(prev_fildes);
			close_pipe(next_fildes);
			exit(EXIT_FAILURE);
		}
	}
}

void	run_children(int i, char ***cmds, int *prev_fildes, int *next_fildes)
{
	char	**argv;

	argv = cmds[i];
	dup_fildes(i, cmds, prev_fildes, next_fildes);
	close_pipe(prev_fildes);
	close_pipe(next_fildes);
	execvp(argv[0], argv);
	exit(EXIT_FAILURE);
}

void	run_parent(int i, char ***cmds, int prev_fildes[2], int next_fildes[2])
{
	close_pipe(prev_fildes);
	if (cmds[i + 1])
		move_pipe(prev_fildes, next_fildes);
}

int	picoshell(char **cmds[])
{
	int		i;
	int		prev_fildes[2] = {NO_FD, NO_FD};
	int		next_fildes[2] = {NO_FD, NO_FD};
	pid_t	pid;

	if (!cmds || !cmds[0])
		return (RET_ERROR);
	i = 0;
	while (cmds[i])
	{
		if (cmds[i + 1] && pipe(next_fildes) == FAIL)
		{
			close_pipe(prev_fildes);
			return (RET_ERROR);
		}
		pid = fork();
		if (pid == FAIL)
		{
			close_pipe(prev_fildes);
			if (cmds[i + 1])
				close_pipe(next_fildes);
			return (RET_ERROR);
		}
		if (pid == 0)
			run_children(i, cmds, prev_fildes, next_fildes);
		run_parent(i, cmds, prev_fildes, next_fildes);
		i ++;
	}
	while (wait(NULL) > 0)
		continue ;
	return (RET_OK);
}
