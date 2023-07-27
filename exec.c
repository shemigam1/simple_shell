#include "shell.h"

/**
 * execmd - executes a command
 * @argv: argument vector
 * @program_name: The name for the shell
 * @count: The number of commands executed
 *
 * Return: Always 0.
 */

void execmd(char **argv, char *program_name, int count)
{
	char *act_cmd = argv[0];

	if (argv != NULL)
	{
		if (argv[0][0] == '.' || act_cmd[0] == '/')
		{
			if (access(act_cmd, F_OK) != 0)
			{
				fprintf(stderr, "%s: %d: %s: not found\n", program_name, count, argv[0]);
				exitcode = 127;
				return;
			}
			if (access(act_cmd, F_OK) != 0 || access(act_cmd, X_OK) != 0)
			{
				fprintf(stderr, "%s: %d: %s: not found\n", program_name, count, argv[0]);
				exitcode = 127;
				return;
			}
		}
		else
		{
			act_cmd = get_loc(argv[0]);
			if (act_cmd == NULL)
			{
				fprintf(stderr, "%s: %d: %s: not found\n", program_name, count, argv[0]);
				exitcode = 127;
				return;
			}
		}
		execution(argv, act_cmd);
		free(act_cmd);
	}
}
