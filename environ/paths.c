#include "main.h"
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * combine_path - This is to combine path together
 * @sep: the delimiter to combine the paths
 * @path1: the first path to be join
 * @path2: the other paht to follow
 * Return: the absolute combine_path of the two path
 */
char *combine_path(const char sep, const char *path1, const char *path2)
{
	size_t i = 0, k = 0;
	size_t len = 0;
	char *path_join = NULL;

	while (path1[i++] != '\0')
		;
	len += i;

	i = 0;
	while (path2[i++] != '\0')
		;
	len += i;
	len += 1;

	path_join = malloc(sizeof(char *) * (len + 1));
	if(path_join == NULL)
		return (NULL);

	i = 0;
	while (path1[k])
	{
		path_join[i] = path1[k];
		i++;
		k++;
	}

	path_join[i++] = sep;

	k = 0;
	while (path2[k])
	{
		path_join[i] = path2[k];
		i++;
		k++;
	}
	path_join[i] = '\0';
	return (path_join);
}

/**
 * [file_exist - This is to check if a path truly exists
 * @path: the pathname to look for
 * Return: return 1 for success, 0 for otherwise 
 */
int file_exist(const char *path)
{
	struct stat buffer;

	if (stat(path, &buffer) == 0)
	{
		return (1);
	}
	return (0);
}