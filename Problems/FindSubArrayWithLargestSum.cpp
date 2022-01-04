/*
 * Find the subarray which has the largest sum.
 * int arr[] = {3,-1,-4,4,-1,2,1,-5,4}
 *   Largest subarray sum - {4,-1,2,1} = 6
 * 
 */

#include <iostream>

using namespace std;

void find_sub_array_with_max_sum (int* arr, int size)
{
	int high = 0;
	int sum = 0;
	int start_index = 0;
	int high_index = 0;
	int len = 0;

	for (int i = 0; i < size; i++)
	{
		sum += arr[i];
		if (sum < 0)
		{
			sum = 0;
			start_index = i+1;
		}
		if (sum > high)
		{
			high = sum;
			high_index = start_index;
			len = i - high_index + 1;
		}
	}
	cout << "Largest sum: " << high << endl;
	cout << "starting index: " << high_index << endl;
	cout << "Length: " << len << endl;
}

int main ()
{
	int arr[] = {3,-1,-4,4,-1,2,1,-5,6};
	find_sub_array_with_max_sum (arr, sizeof(arr)/sizeof(arr[0]));
}