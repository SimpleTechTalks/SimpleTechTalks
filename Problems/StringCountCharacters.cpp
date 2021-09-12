#include <unistd.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

void string_count_occurance (char *in, char *out)
{
	int size = strlen (in);
	int index = 0;
	int count = 1;
	char c = in[0];
	for (int i = 1; i < size; i++)
	{
		if (in[i] != c) {
			out[index++] = c;
			out[index++] = '0' + count;
			count = 1;
			c = in[i];
		}
		else
		{
			count++;
		}
	}
	out[index++] = c;
	out[index++] = '0' + count;
	out[index] = '\0';
}

int main ()
{
	char in[100];
	char out[100];
	printf ("Enter the String \n");
	scanf ("%s", in);
	string_count_occurance (in, out);
	printf ("Input String: %s \n", in);
	printf ("Output String: %s \n", out);
}