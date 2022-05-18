#include <stdio.h>

/**
 * main - here is the main file
 */

void increment(int **p);

int main(void)
{
	int x = 5;
	int *p = &x;
	int **q;
	int ***r;

	*p = 6;
	q = &p;
	**q = 7;
	r = &q;

	printf("%d\n", *p); /* value */
	printf("%d\n", *(*q)); /* the value of pointer */
	printf("%d\n", *(*(*r))); /* the value at that pointer */

	increment(q);
	printf("%d\n", *(*q));
	increment(&p); /* passing the addr of pointer p */

	printf("%d\n", *p);

	return(0);
}

void increment(int **p)
{
	**p = (**p) + 1; /* to evaluate pointer here, they have to be in braces */
}