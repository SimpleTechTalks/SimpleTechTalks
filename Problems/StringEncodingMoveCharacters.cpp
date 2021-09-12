#include <stdio.h>
#include <string.h>
#include <stdint.h>

void string_encoding (char *input, uint32_t n)
{
	if (n == 0)
		return;
	if (n > 26)
	{
		n = n % 26;
	}
	int size = strlen (input);
	for (int i = 0; i < size; i++)
	{
		input[i] = input[i] + n;
		if (input[i] > 'Z')
		{
			input[i] = input[i] - ('Z' + 1) + 'A';
		}
	}
}

int main ()
{
	char input[100];
	uint32_t n;
	printf ("Enter Input String \n");
	scanf ("%s", input);
	printf ("Enter position \n");
	scanf ("%u", &n);
	printf ("Input String: %s \n", input);
	string_encoding (input, n);
	printf ("Modified String: %s \n", input);
}