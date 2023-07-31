#include "shell.h"

/**
 * execution - Executes a command
 * @argv: argument vector
 * @act: actual command
 *
 * Return: Void
 */

void execution(char **argv, char *act)
{
	pid_t my_pid;
	int status;

	my_pid = fork();

	if (my_pid == -1)
	{
		exit(errno);
	}

	if (my_pid == 0)
	{
		execve(act, argv, environ);
		exit(errno);
	}

	if (my_pid > 0)
	{
		wait(&status);
		if (WIFEXITED(status))
			errno = WEXITSTATUS(status);
	}
}
