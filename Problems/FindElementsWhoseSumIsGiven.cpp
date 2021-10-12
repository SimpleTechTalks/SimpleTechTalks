/*
 * Given an array of integers and a value, 
 * determine if there are any two integers in the array 
 * whose sum is equal to the given value.
 */ 
/* 
 * Given an array of integers and a value, 
 * determine if there are any three integers in the array 
 * whose sum is equal to the given value.
 */
#include "iostream"
#include "../DataStructures/HashingDoubleHashing.h"

#define ARRAY_MAX_SIZE 50
#define ARRAY_MAX_VALUE 100

using namespace std;

void all_possible_combinations (int *arr, int sum)
{
	/* Create a hash table of big enough size to avoid collision.
	   Although hash definition is capable enough to handle collision.
	   Still we are taking bigger size hash to control hash table load ratio.
	 */
	HashingDoubleHashing hash_table (ARRAY_MAX_VALUE, true);
	for (int i = 0; i < ARRAY_MAX_SIZE; i++) {
		if (hash_table.search_data (sum - arr[i])) {
			cout << " value: " << arr[i] << " value: " << sum - arr[i] << " Sum: " << sum << endl; 
		} else {
			hash_table.insert_data (arr[i]);
		}
	}
}

void all_possible_triplets (int *arr, int sum)
{
	/* Create a hash table of big enough size to avoid collision.
	   Although hash definition is capable enough to handle collision.
	   Still we are taking bigger size hash to control hash table load ratio.
	 */
	for (int j = 0; j < ARRAY_MAX_SIZE; j++) {
		HashingDoubleHashing hash_table (ARRAY_MAX_VALUE, true);
		for (int i = j+1; i < ARRAY_MAX_SIZE; i++) {
			if (hash_table.search_data (sum - arr[i] - arr[j])) {
				cout << "value: " << arr[j] << " value: " << arr[i] << " value: " << sum - arr[i] - arr[j] <<
					    " Sum: " << sum << endl; 
			} else {
				hash_table.insert_data (arr[i]);
			}
		}
	}
}

int main ()
{
	int arr[ARRAY_MAX_SIZE] = {0};

	for (int i = 0; i < ARRAY_MAX_SIZE; i++) {
		arr[i] = rand () % ARRAY_MAX_VALUE;
	}

	for (int i = 0; i < ARRAY_MAX_SIZE; i++) {
		cout << arr[i] << " ";
		if (i % 10 == 0 && i) {
			cout << endl;
		}
	}
	cout << endl;

	int sum = 0;
	cout << "Enter sum " << endl;
	cin >> sum;
	all_possible_combinations (arr, sum);
	all_possible_triplets (arr, sum);
}