#include "shell.h"

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
	(void)ac;
	(void)av;

	while (1)
	{
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
			return (0);
		}

		token(space);
	}
	return (0);
}
