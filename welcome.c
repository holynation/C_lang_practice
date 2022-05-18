#include <stdio.h>

/**
 * main - this is a welcome message
 *
 * Return: Always return success (0)
 */

int main(void)
{
	char x, y, z;
	int num1, num2;
	float myFloat = 3.14;
	x = 'A';
	y = 'f';
	z = '7';
	num1 = 12;
	num2 = 12345;

	printf("Welcome to doing hard things. \n");
	printf("Character data type \n");
	printf("x - %c : y - %c : z - %c \n", x, y, z);
	printf("%f is a float data type \n", myFloat);
	printf("%d\n", num1);
	printf("%d\n", num2);
	printf("%5d\n", num1);
	printf("%05d\n", num1);
	printf("%2d\n", num2);

	return (0);
}
