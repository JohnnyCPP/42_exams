#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

#define CODE_TIMEOUT 142

#define FAIL -1

#define GOOD_FUNCTION 1
#define BAD_FUNCTION 0
#define ERROR_OCCURS -1

#define MSG_GOOD_FUNCTION "Nice function!\n"
#define MSG_EXIT_CODE "Bad function: exited with code %d\n"
#define MSG_EXIT_DESC "Bad function: %s\n"
#define MSG_TIME_OUT "Bad function: timed out after %d seconds\n"

static	void	timeout_handler(int sig)
{
	(void) sig;
}

static	void	set_timeout_handler(void)
{
	struct	sigaction	sa;

	sa.sa_handler = timeout_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGALRM, &sa, NULL);
}

static	int	get_term_signal(int wstatus, bool verbose, unsigned int timeout)
{
	int		term_signal;
	char	*description;

	if (verbose)
	{
		term_signal = WTERMSIG(wstatus);
		description = strsignal(term_signal);
		if (term_signal == SIGALRM)
			printf(MSG_TIME_OUT, timeout);
		else
			printf(MSG_EXIT_DESC, description);
	}
	return (BAD_FUNCTION);
}

static	int	get_stop_signal(int wstatus, bool verbose)
{
	int		stop_signal;
	char	*description;

	if (verbose)
	{
		stop_signal = WSTOPSIG(wstatus);
		description = strsignal(stop_signal);
		if (description)
			printf(MSG_EXIT_DESC, description);
	}
	return (BAD_FUNCTION);
}

static	int	get_exit_status(int wstatus, bool verbose)
{
	int	exit_status;

	exit_status = WEXITSTATUS(wstatus);
	if (exit_status == 0)
	{
		if (verbose)
			printf(MSG_GOOD_FUNCTION);
		return (GOOD_FUNCTION);
	}
	else
	{
		if (verbose)
			printf(MSG_EXIT_CODE, exit_status);
		return (BAD_FUNCTION);
	}
}

static	int	kill_child(pid_t pid, bool verbose, unsigned int timeout)
{
	kill(pid, SIGKILL);
	waitpid(pid, NULL, 0);
	if (verbose)
		printf(MSG_TIME_OUT, timeout);
	return (BAD_FUNCTION);
}

static	int	run_parent(pid_t pid, bool verbose, unsigned int timeout)
{
	int	wstatus;

	wstatus = 0;
	if (waitpid(pid, &wstatus, WUNTRACED) == FAIL)
	{
		if (errno == EINTR)
			return (kill_child(pid, verbose, timeout));
		return (ERROR_OCCURS);
	}
	if (WIFEXITED(wstatus))
		return (get_exit_status(wstatus, verbose));
	if (WIFSTOPPED(wstatus))
		return (get_stop_signal(wstatus, verbose));
	if (WIFSIGNALED(wstatus))
		return (get_term_signal(wstatus, verbose, timeout));
}

static	void	run_child(void (*f)(void))
{
	f();
	exit(0);
}

int	sandbox(void (*f)(void), unsigned int timeout, bool verbose)
{
	pid_t	pid;
	int		ecode;

	if (!f)
		return (-1);
	set_timeout_handler();
	alarm(timeout);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
		run_child(f);
	ecode = run_parent(pid, verbose, timeout);
	return (ecode);
}
