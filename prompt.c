#include "shell.h"

/**
 * main - interactive shell
 * @ac: int
 * @av: arr of str
 * Return: 0
 */

int main(void)
{
	char *prompt;
	/*int status;
	pid_t child_pid;*/
	size_t i = 0;
	int a;
	ssize_t cmd_count;
	char *line = NULL;
	char *token;

	while (1)
	{
		prompt = "#cisfun$";
		printf("%s ", prompt);
		cmd_count = getline(&line, &i, stdin);

		if ((strcmp(line, "exit\n") == 0) || (cmd_count == -1))
		{
			printf("Exiting shell...\n");
			return (-1);
		}
		line[strcspn(line, "\n")] = '\0';
                char *argv[] = {line, NULL};
		printf("%s", line);

		free(line);
	}
	return (0);
}
