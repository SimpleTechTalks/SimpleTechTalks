/*
 * Given an array of 0's and 1's, find the largest subarray with equal number of 0s and 1s
 */

#include <iostream>

using namespace std;

void find_same_number_index (int* arr, int size)
{
	int* num = new int[size*2 + 1];

	if (!num) {
		cout << "Memory allocation failed.\n";
		return;
	}
	int pivot = size;

	for (int i = size-1; i >= 0; i--)
	{
		if (num[pivot + arr[i]] < i) {
			num[pivot + arr[i]] = i;
		}
	}

	for (int i = 0; i < (size*2 + 1); i++) {
		cout << num[i] << "  ";
	}
	cout << "\n";

	int left_index = 0;
	int right_index = 0;
	int len = 0;
	for (int i = 0; i < size; i++) {
		if (len < (num[pivot + arr[i]] - i)) {
			len = num[pivot + arr[i]] - i + 1;
			left_index = i;
			right_index = num[pivot + arr[i]];
		}
	}
	cout << "left_index: " << left_index << " right_index: " << right_index << " length: " << len << endl;
}

void find_largest_subarray (int* arr, int size)
{
	int* temp_arr = new int[size];
	if (!temp_arr) {
		cout << "Memory allocation failed.\n";
		return;
	}
	/* save difference between number of 1's - 0's*/
	int prev = arr[0];
	temp_arr[0] = prev ? 1 : -1;
	for (int i = 1; i < size; i++) {
		switch (arr[i]) {
			case 0:
				temp_arr[i] = temp_arr[i-1] - 1;
				break;
			case 1:
				temp_arr[i] = temp_arr[i-1] + 1;
				break;
			default:
				cout << "Unknown value\n";
		}
	}
	for (int i = 0; i < size; i++) {
		cout << temp_arr[i] << "  ";
	}
	cout << "\n";
	find_same_number_index (temp_arr, size);
}

int main ()
{
	int arr[] = {0,1,1,0,0,0,1,1,1,0,0,1,1,0,1,1,0,0,1};

	cout << "Size of array: " << sizeof(arr)/sizeof(arr[0]) << endl;
	find_largest_subarray (arr, sizeof(arr)/sizeof(arr[0]));

	srand (11);
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		arr[i] = rand() & 0x1;
	}
	find_largest_subarray (arr, sizeof(arr)/sizeof(arr[0]));
}