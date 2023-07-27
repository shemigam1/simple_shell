#include "shell.h"

void execution(char **argv, char *act);
int exitcode = 0;

/**
 * main - Entry point
 * @ac: argument count
 * @av: Argumenr vector(array)
 *
 * Description: A program that prints its arguments
 *
 * Return: Always 0(Success)
 */

int main(int ac, char **av)
{
	char *space = NULL;
	size_t buff = 0;
	int count = 0;
	(void)ac;

	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "$ ", str_len("$ "));
		}
		if (getline(&space, &buff, stdin) == -1)
		{
			free(space);
			if (isatty(STDIN_FILENO) == 1)
			{
				write(STDOUT_FILENO, "\n", str_len("\n"));
			}
			return (exitcode);
		}
		if (space[0] == 'e' && space[1] == 'x' &&
			space[2] == 'i' && space[3] == 't')
		{
			free(space);
			exit(exitcode);
		}
		token(space, av[0], count);
	}
	return (exitcode);
}
