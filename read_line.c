#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char *read_line(void);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);

int main(void)
{
	
	char *buffer_str;

	buffer_str = read_line();
	printf("%s\n", buffer_str);

	free(buffer_str);
	return (0);
}

char *read_line(void)
{
	char *buffer = NULL;
	size_t size = 0;
	ssize_t i = 0;
	char *buff;
	int j = 0, k = 0;

	buff = malloc(sizeof( char *) * 1024);
	if(buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	while ((i = getline(&buffer, &size, stdin)) != -1)
	{
		if (i == -1)
		{
			return (NULL);
		}

		if (buff){
			j = _strlen(buffer);
			buffer[j - 1] = ' ';
			if (!k)
				_strcpy(buff,buffer);
			else
				_strcat(buff, buffer);
			k = 1;
		}
	}

	free(buffer);
	return (buff);
}

int _strlen(char *s)
{
	int a = 0;

	while (*(s + a))
		a++;

	return (a);
}

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; i <= _strlen(src); i++)
		dest[i] = src[i];

	return (dest);
}

char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;
	/* to count the str len without the null byte*/
	while (dest[i] != '\0')
	{
		i++;
	}

	while (src[j] != '\0')
	{
		/* appending src to the last index of dest */
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';

	return (dest);
}