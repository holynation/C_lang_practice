#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	int id, id1;
	int n, i;
	int status;
	
	id = fork();
	id1 = fork();

	printf("child: %d : ", id);
	printf("child 1: %d\n", id1);

	if (id == 0)
	{
		n = 1;
	}
	else
	{
		n = 6;
	}

	if (id != 0)
	{
		wait(&status);
	}

	for (i = n; i < n + 5; i++)
	{
		printf("%d ", i);
		fflush(stdout);
	}

	if (id != 0)
	{
		printf("\n");
	}

	return (0);
}
