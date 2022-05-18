#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t child_pid;
    int status, res;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Error:");
        return (1);
    }
    if (child_pid == 0)
    {
        printf("Wait for me, wait for me\n");
        sleep(2);
    }
    else
    {
        res = wait(&status);
        printf("Oh, it's all better now\n");
    }

    if (res == -1)
    {
        printf("No children to wait for\n");
    }
    else
    {
        printf("%d finished execution\n", res);
    }

    return (0);
}