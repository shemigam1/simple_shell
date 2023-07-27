#include "shell.h"

/**
 * get_loc - an alias-like call
 * @cmd: input command(e.g ls)
 *
 * Description: A function that gets the location of a command
 *
 * Return: full_path
 */

char *get_loc(char *cmd)
{
	char *full_path = NULL, *path = getenv("PATH"), *path_tok;

	path_tok = strtok(path, ":");

	while (path_tok)
	{
		full_path = malloc(sizeof(char) * (str_len(path_tok) + 2 + str_len(cmd)));
		/*full_path[0] = '\0';*/
		if (full_path == NULL)
		{
			return (NULL);
		}
		str_cpy(full_path, path_tok);
		str_cat(full_path, "/");
		str_cat(full_path, cmd);
		str_cat(full_path, "\0");

		if (access(full_path, X_OK) == 0)
		{
			return (full_path);
		}
		path_tok = strtok(NULL, ":");
		free(full_path);
	}
	exitcode = 127;

	return (NULL);
}
