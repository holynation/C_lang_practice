#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
 * main - This is the entry point to the code
 * Return: Return 0
 */

int main(void)
{	
	char *cmd =  NULL;
	char *args[] = {NULL, NULL};
	size_t size = 0;
	ssize_t n_read = 0;
	char *cmd_path = NULL;

	while (1)
	{
		printf("Enter Command: ");
		n_read = getline(&cmd, &size, stdin);
		cmd[n_read - 1] = '\0';

		cmd_path = locate_path(cmd);
		if(cmd_path)
		{
			args[0] = cmd_path;
			if (fork() == 0) /* CHILD PROCESS */
			{
				execve(*args, args, NULL);
			}
			
			wait(NULL);
			free(cmd_path);
			cmd_path = NULL;
		}
		else
		{
			dprintf(STDERR_FILENO, "%s: Command not found\n", cmd);
		}
	}

	return (0);
}
