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
	int line;
	int count = 0;
	(void)ac;

	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO) == 1)
		{
			write(STDOUT_FILENO, "$ ", str_len("$ "));
		}
		line = getline(&space, &buff, stdin);
		if (line == -1)
		{
			/*free(space);*/
			if (isatty(STDIN_FILENO) == 1)
			{
				write(STDOUT_FILENO, "\n", str_len("\n"));
			}
			free(space);
			return (exitcode);
		}
		if (strcmp(space, "exit\n") == 0)
		{
			free(space);
			return (exitcode);
		}

		token(space, av[0], count);
	}
	return (exitcode);
}
