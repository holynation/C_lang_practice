#include <stdio.h>
#include "main.h"

/**
 * [main description]
 * Return  [description]
 */
extern char **environ;

int main(void)
{	
	char *file_path = locate_path("ls");
	if (file_path)
		printf("%s\n", file_path);
	else
		printf("Command not found\n");

	return (0);
}
