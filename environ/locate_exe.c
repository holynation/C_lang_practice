#include "main.h"
#include <stddef.h>
#include <string.h>
#include <stdlib.h>

extern char **environ;
/**
 * locate_path - this is to find a path in the environ variable
 * @name: name of the exec to find in the environment variable
 * Return: return the absolute path of the exec func
 */
char *locate_path(const char *name)
{
	char *path = _getenv("PATH");
	char *dir_path = NULL;
	char *file_path = NULL;

	/* PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin */
	if (file_exist(name))
		return (_strdup(name));

	strtok(path, "="); /* PATH\0/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin */
	dir_path = strtok(NULL, ":"); /* PATH=\0/usr/local/sbin\0/usr/local/bin:/usr/sbin:/usr/bin */
	while (dir_path)
	{
		file_path = combine_path('/', dir_path, name);
		if (file_exist(file_path))
			break;

		free(file_path);
		file_path = NULL;

		dir_path = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
