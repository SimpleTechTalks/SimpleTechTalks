#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define INITIAL_ARRAY_SIZE 20
#define REALLOC_ARRAY_SIZE 40

int main ()
{
	int *p1 = (int *) malloc (sizeof (int)); /* allocate one int */
	if (!p1)
	{
		printf ("Dynamic memory allocation using malloc failed. \n");
	}

	int *p2 = (int *) malloc (sizeof (int) * INITIAL_ARRAY_SIZE); /* allocate array of int of size 20 */
	if (!p2)
	{
		printf ("Dynamic memory allocation using malloc failed.");
	}

	int *p3 = (int *) calloc (1, sizeof (int)); /* allocate one int */
	if (!p3)
	{
		printf ("Dynamic memory allocation using calloc failed. \n");
	}
	printf ("calloc memory is always intialized with 0, checking p3 value [%d]\n", *p3);

	for (int i = 0; i < INITIAL_ARRAY_SIZE; i++)
	{
		p2[i] = i;
	}
	printf ("Inital array value \n");
	for (int i = 0; i < INITIAL_ARRAY_SIZE; i++)
	{
		printf ("%d ", p2[i]);
	}
	printf ("\n");
	p2 = realloc (p2, REALLOC_ARRAY_SIZE * sizeof (int));
	if (!p2)
	{
		printf ("Dynamic memory allocation using realloc failed.");
	}
	printf ("After realloc array value \n");
	for (int i = 0; i < REALLOC_ARRAY_SIZE; i++)
	{
		printf ("%d ", p2[i]);
	}
	printf ("\n");
	free (p1);
	free (p2);
	free (p3);
}