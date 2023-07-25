#include "shell.h"

/**
 * tokenize - splits cmd line args into an arr of strs
 * @line: str
 * @line_count: int
 * Return: arr of strings
 */

char **tokenize(char *line, int line_count)
{
	char *line_copy = NULL;
	char *token;
	char *delim = " \n";
	char **token_arr;
	int i, token_count = 0;

	line_copy = malloc(sizeof(char) * line_count);
	if (line_copy == NULL)
	{
		perror("memory error");
		exit(98);
	}
	strcpy(line_copy, line);

	token = strtok(line, delim);
	while (token != NULL)
	{
		token_count++;
		token = strtok(NULL, delim);
	}
	token_count++;

	token_arr = malloc(sizeof(char *) * token_count);

	token = strtok(line_copy, delim);
	for (i = 0; token != NULL; i++)
	{
		token_arr[i] = malloc(sizeof(char) * strlen(token));
		strcpy(token_arr[i], token);
		printf(">>>>> %s \n", token_arr[i]);
		token = strtok(NULL, delim);
	}
	token_arr[i] = NULL;

	return (token_arr);
}
