#include "shell.h"

/**
 * str_dup - duplicates a string
 * @str: string to duplicate
 *
 * Return: pointer to the duplicate
 */

char *str_dup(char *str)
{
	size_t len;
	char *dup = NULL;

	if (str == NULL)
	{
		return (NULL);
	}

	len = str_len(str);
	dup = (char *) malloc((len + 1) * sizeof(char));
	if (dup != NULL)
	{
		str_cpy(dup, str);
	}
	return (dup);
}


/**
 * str_cpy - copies a string
 * @dest: destination pointer
 * @src: source pointer
 *
 * Description: A function that copies string from src to dest
 *
 * Return: dest
 */

char *str_cpy(char *dest, char *src)
{
	int index;

	for (index = 0; src[index] != '\0'; index++)
	{
		dest[index] = src[index];
	}
	dest[index] = '\0';

	return (dest);
}

/**
 * str_len - length of a string
 * @str: string to be counted
 *
 * Desctiption: A function that returns the length of a string
 *
 * Return: len
 */

int str_len(char *str)
{
	int len;

	for (len = 0; str[len] != '\0'; len++)
		;

	return (len);
}


/**
 * str_cat - catenates strings
 * @dest: Desctination string
 * @src: Source string
 *
 * Description: A function that concatenates two strings
 *
 * Return: catenated string
 */

char *str_cat(char *dest, char *src)
{
	int d_index;
	int s_index;

	for (d_index = 0; dest[d_index] != '\0'; d_index++)
		;

	for (s_index = 0; src[s_index] != '\0'; s_index++)
	{
		dest[d_index] = src[s_index];
		d_index++;
	}
	dest[d_index] = '\0';

	return (dest);
}
