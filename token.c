#include "shell.h"

/**
 * token - creates tokens
 * @str: pointer to string
 *
 * Description: A function that tokenizes an array
 *
 * Return: ...
 */

int **token(char *str)
{
	char **argv, *copy, *segment, *separat = " \n\t\r";
	int num_seg = 0, ind = 0;

	copy = str_dup(str);
	if (copy == NULL)
	{
		exit(0);
	}

	segment = strtok(copy, separat);
	while (segment)
	{
		num_seg++;
		segment = strtok(NULL, separat);
	}
	num_seg++;

	argv = malloc(sizeof(char *) * num_seg);
	segment = strtok(str, separat);

	while (segment)
	{
		argv[ind++] = strdup(segment);
		segment = strtok(NULL, separat);
	}
	argv[ind] = NULL;

	execmd(argv);
	/*printf("segment\n");*/
	for (ind = 0; argv[ind]; ind++)
	{
		free(argv[ind]);
	}
	free(copy);
	free(argv);
	return (0);
}
