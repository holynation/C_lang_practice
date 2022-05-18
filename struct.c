#include <stdio.h>
#include <string.h>

struct Person
{
	char name[50];
	float salary;
} person1;

typedef struct Animals
{	char name[50];
	int weight;

} animals;

int main(void)
{
	animals *animalPtr,animal;
	animalPtr = &animal;

	strcpy(person1.name, "Oluwaseun Alatise"); /* = operator assigning doesn't work on string */
	person1.salary = 250000;

	strcpy(animalPtr->name, "Cat");
	animalPtr->weight = 80;


	printf("Name: %s\n", person1.name);
	printf("Salary: %.2f\n", person1.salary);

	printf("Animal name: %s\n", animalPtr->name);
	printf("Animal weight:%d\n", animalPtr->weight);

	return (0);
}