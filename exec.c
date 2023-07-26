#include "shell.h"

/**
 * main - execve example
 *
 * Return: Always 0.
 */

void execmd(char **argv)
{
	char *act_cmd = argv[0];

	if (argv != NULL)
	{
		/*printf("%d\n",argv[0][0]);*/

		if (argv[0][0] == '.'|| act_cmd[0] == '/')
		{
			if (access(act_cmd, F_OK) != 0)
			{
				perror("File Not Found\n");
			}
			if (access(act_cmd, F_OK) != 0 || access(act_cmd, X_OK) != 0)
			{
				perror("Permission Denied");
			}
		}
		else
		{
			act_cmd = get_loc(argv[0]);
			if (act_cmd == NULL)
			{
				perror("Command Not found\n");
			}
		}
		execution(argv, act_cmd);
	}
}
