#include "main.h"
#include <stddef.h>

/**
 * _getenv - This is to get the environment variable
 * @name: the env name to look for in the environ
 * Return: return the env path or null 
 */
char *_getenv(const char *name)
{
	size_t i = 0, k = 0;
	char *env_val = NULL;


	while (environ[i] != NULL)
	{
		env_val = environ[i];
		k = 0;
		while (env_val[k] == name[k] && env_val[k] != '=' && 
			env_val[k] && name[k])
		{
			k++;
		}

		if (name[k] == '\0')
		{
			return (_strdup(env_val));
		}

		i++;
	}
	return (NULL);
}