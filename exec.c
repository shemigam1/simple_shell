#include "shell.h"

/**
 * exec - executes a binary exec file
 * @argv: arr of str
 * Return: void
 */

void exec(char **argv)
{
	char *cmd = NULL;

	if (argv != NULL)
	{
		cmd = argv[0];

		if (execve(cmd, argv, NULL) == -1)
		{
			perror("Exec error");
			exit(EXIT_FAILURE);
		}
	}
}
