#include "shell.h"

/**
 * main - interactive shell
 * @ac: int
 * @av: arr of str
 * Return: 0
 */

int main(void)
{
	char *prompt = "#cisfun$";
	int status;
	pid_t child_pid;
	size_t i = 0;
	int a = 0;
	ssize_t cmd_count;
	char *line = NULL;
	char *token;
	char **argv;

	while (1)
	{
		printf("%s ", prompt);
		cmd_count = getline(&line, &i, stdin);

		if ((strcmp(line, "exit\n") == 0) || (cmd_count == -1))
		{
			printf("Exiting shell...\n");
			free(line);
			break;
		}
		line[strcspn(line, "\n")] = '\0';
		argv = tokenize(line, cmd_count);
		/*while (argv[a] != NULL)
		{
			printf("%s\n", argv[a]);
			a++;
		}*/
		if (argv != NULL)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error: ");
			}
			else if (child_pid == 0)
			{
				exec(argv);
			}
			else
			{
				wait(&status);
			}
		}
	}
	free(line);
	
	for (a = 0; argv != NULL && argv[a]; a++)
	{
		free(argv[a]);
	}
	free(argv);
	return (0);
}
