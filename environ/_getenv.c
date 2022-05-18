#include "main.h"
#include <stddef.h>

/**
 * _getenv - This is to get the environment variable
 * @name: the env name to look for in the environ
 * Return: return the env path or null 
 */
char *_getenv(const char *name)
{
	size_t i = 0, j = 0;
	char *env_val = NULL;

	while (environ[i] != NULL)
	{
		env_val = environ[i];
		j = 0;
		while (env_val[j] == name[j]) /* find desired env variable */
			j++;

		if (name[j] == '\0' && env_val[j] == '=')
			return (_strdup(env_val));

		i++;
	}
	return (NULL);
}