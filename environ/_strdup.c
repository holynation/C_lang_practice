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

	if (str == NULL) /* validate str input */
		return (NULL);

	while (str[i++])
		;
	len += i;
	len++; /* add null terminator to length */

	new_str = malloc(sizeof(char *) * (len + 1));
	if (new_str == NULL)
		return (NULL);

	i = 0;
	while (i <= len)
	{
		new_str[i] = str[i];
		i++;
	}

	return (new_str);
}