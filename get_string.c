#include <stdio.h>

/**
  * main - the entry code to the program
  * Return: always return 0
  */

int count_letters(int *text);

int main(void)
{
	int text;
	printf("Text: ");
	scanf("%d", &text); 
	int letters = count_letters(&text);
	printf("%d\n", letters);

	return (0);
}

int count_letters(int *text)
{
	printf("%d\n", (*text));

	return (0);
}
