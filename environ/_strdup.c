#include <stdlib.h>
#include <stddef.h>

/**
 * _strdup - this is to duplicate the string
 * @str - the string to be duplicated
 * Return: the new duplicated string
 */
char *_strdup(const char *str)
{
	size_t i = 0;
	size_t len = 0;
	char *new_str = NULL;

	while (str[i++])
		;
	len += i;

	new_str = malloc(sizeof(char *) * (len + 1));

	i = 0;
	while (i <= len)
	{
		new_str[i] = str[i];
		i++;
	}

	return (new_str);
}