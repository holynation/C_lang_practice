#include <stdio.h>
#include "main.h"

/**
 * [main description]
 * Return  [description]
 */
int main(void)
{	
	char *file_path = locate_path("bin");
	if (file_path)
		printf("%s\n", file_path);
	else
		printf("Command not found");

	return (0);
}
