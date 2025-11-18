#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

#define TYPE_READ 'r'
#define TYPE_WRITE 'w'

#define FAIL -1
#define READ_PIPE 0
#define WRITE_PIPE 1

static	int	is_wrong_type(const char type)
{
	if (type != TYPE_READ && type != TYPE_WRITE)
		return (1);
	return (0);
}

static	void	ft_close_pipe(const int *fildes)
{
	close(fildes[READ_PIPE]);
	close(fildes[WRITE_PIPE]);
}

int	run_parent(const int *fildes, const char type)
{
	if (type == TYPE_READ)
	{
		close(fildes[WRITE_PIPE]);
		return (fildes[READ_PIPE]);
	}
	else
	{
		close(fildes[READ_PIPE]);
		return (fildes[WRITE_PIPE]);
	}
}

void	run_child(const char *file, char *const argv[], int *fildes, char type)
{
	if (type == TYPE_READ)
	{
		if (dup2(fildes[WRITE_PIPE], STDOUT_FILENO) == FAIL)
		{
			ft_close_pipe(fildes);
			exit(EXIT_FAILURE);
		}
		ft_close_pipe(fildes);
	}
	else
	{
		if (dup2(fildes[READ_PIPE], STDIN_FILENO) == FAIL)
		{
			ft_close_pipe(fildes);
			exit(EXIT_FAILURE);
		}
		ft_close_pipe(fildes);
	}
	execvp(file, argv);
	exit(EXIT_FAILURE);
}

int	ft_popen(const char *file, char *const argv[], char type)
{
	int		fildes[2];
	pid_t	pid;

	if (!file || !argv || is_wrong_type(type))
		return (FAIL);
	if (pipe(fildes) == FAIL)
		return (FAIL);
	pid = fork();
	if (pid == FAIL)
	{
		ft_close_pipe(fildes);
		return (FAIL);
	}
	if (pid == 0)
		run_child(file, argv, fildes, type);
	return (run_parent(fildes, type));
}
