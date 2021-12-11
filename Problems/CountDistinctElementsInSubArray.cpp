/*
 * Given an array of size n and an integer k,
 * return the count of distinct numbers in all windows of size k.
 */
#include "iostream"
#include <unordered_map>

using namespace std;
#define ARRAY_MAX_VALUE 200

void count_distinct_number (int* arr, int size, int k)
{
	unordered_map <int, int> hash_map;
	int distinct = 0;
	for (int i = 0; i < size; i++) {
		if (hash_map[arr[i]] == 0)
			distinct++;
		hash_map[arr[i]] = hash_map[arr[i]] + 1;
		if (i >= k-1) {
			if (hash_map[arr[i-k]] == 1)
				distinct--;
			if (hash_map[arr[i-k]] > 0)
				hash_map[arr[i-k]]--;
			cout << "K indexes: " << i-k+1 << " and " << i << " distinct entries: " << distinct << endl;
		}
	}
}

int main ()
{
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = rand () % 10;
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
	count_distinct_number (arr, 10, 4);
	count_distinct_number (arr, 10, 6);
}