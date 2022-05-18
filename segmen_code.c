#include <stdio.h>

/**
  * main - the main method into the program
  * Return: Always return 0
  */

int main(void)
{
	int x = 5;
	int *ptr; /* a pointer,to hold an address of a location */

	ptr = &x; /* now assigning an address location to the pointer */
	*ptr = 98; 
	printf("%d\n", *ptr);
	return(0);
}
