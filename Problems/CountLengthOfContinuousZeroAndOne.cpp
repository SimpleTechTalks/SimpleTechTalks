/*
 *  Given a binary string of 0s and 1s return True, if the length of longest contig. 
 	zeros is strictly greater than length of  ones else False
	Input: 011100
	Output: False

 */
#include <iostream>

using namespace std;

#define MAX_ARRAY_ITEM 20

void check_length (int* arr, int size)
{
	int max_0_length = 0;
	int max_1_length = 0;
	int length_0 = 0;
	int length_1 = 0;

	int prev = -1;
	for (int i = 0; i < size; i++) {
		switch (arr[i]) {
			case 0:
				if (prev == arr[i]) {
					length_0++;
					if (max_0_length < length_0) {
						max_0_length = length_0;
					}
				} else {
					length_0 = 1;
					length_1 = 0;
					prev = 0;
				}
				break;
			case 1:
				if (prev == arr[i]) {
					length_1++;
					if (max_1_length < length_1) {
						max_1_length = length_1;
					}
				} else {
					length_1 = 1;
					length_0 = 0;
					prev = 1;
				}
				break;
		}
	}
	cout << "Length_0: " << max_0_length << " Length_1: " << max_1_length << endl;
}

int main ()
{
	int arr[MAX_ARRAY_ITEM];

	srand (21);
	for (int i = 0; i < MAX_ARRAY_ITEM; i++) {
		arr[i] = rand() & 0x1;
	}

	for (int i = 0; i < MAX_ARRAY_ITEM; i++) {
		cout << arr[i] << " " ;
	}
	cout << "\n";
	check_length (arr, MAX_ARRAY_ITEM);
}