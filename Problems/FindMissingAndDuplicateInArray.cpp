/*
 * Given an unsorted array of size n. Array elements are in range from 1 to n. 
 * One number from set {1, 2, …n} is missing and one number occurs twice in array. 
 * Find these two numbers.
 */
#include <iostream>
using namespace std;

#define MAX_ARRAY_SIZE 500
void print_missing_and_duplicate (int missing, int duplicate)
{
    int arr[MAX_ARRAY_SIZE] = {0};

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        if (i == missing)
            arr[i] = duplicate;
        else
            arr[i] = i;
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        if (arr[i] < 0)
        {
            cout << "Duplicate item in the list is: " << i << endl;
        }
        else
        {
            arr[arr[i]] = -1;
        }
    }
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        if (arr[i] >= 0)
            cout << "Missing Number in the list is: " << i << endl;
    }
}

void print_missing_and_duplicate_version2 (int missing, int duplicate)
{
    int arr[MAX_ARRAY_SIZE] = {0};

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        if (i == missing)
            arr[i] = duplicate;
        else
            arr[i] = i;
    }

    int count[MAX_ARRAY_SIZE] = {0};
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        count[arr[i]] += 1;
    }
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        if (count[i] == 0)
            cout << "Missing Number in the list is: " << i << endl;
        else if (count[i] == 2)
            cout << "Duplicate item in the list is: " << i << endl;
    }
}

void check_missing ()
{
    print_missing_and_duplicate (30, 60);
    print_missing_and_duplicate (15, 60);
    print_missing_and_duplicate (10, 30);
    print_missing_and_duplicate (33, 77);
    print_missing_and_duplicate_version2 (33, 77);
    print_missing_and_duplicate_version2 (10, 30);
}

/*
 * Given an array of sizen, the array contains numbers in range from 0 to k-1 wherekis a positive integer and k <= n.
 * Find the maximum repeating number in this array.
 * 
 */
void find_max_repeating_number_in_array ()
{
    int arr[MAX_ARRAY_SIZE] = {0};

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        arr[i] = rand() % MAX_ARRAY_SIZE;
    }

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        arr[arr[i] % MAX_ARRAY_SIZE] += MAX_ARRAY_SIZE;
    }

    int max = 0;
    int repeating_item = 0;

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            repeating_item = i;
        }
    }
    cout << "Maximum Repeating Element is " << repeating_item << " and instances are " << max / MAX_ARRAY_SIZE << endl;
}

void find_max_repeating_number_in_array_method2 ()
{
    int arr[MAX_ARRAY_SIZE] = {0};

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        arr[i] = rand() % MAX_ARRAY_SIZE;
    }

    int count[MAX_ARRAY_SIZE] = {0};
    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        count[arr[i]] += 1;
    }

    int max = 0;
    int repeating_item = 0;

    for (int i = 0; i < MAX_ARRAY_SIZE; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
            repeating_item = i;
        }
    }
    cout << "Maximum Repeating Element is " << repeating_item << " and instances are " << max << endl;
}

void check_repeating ()
{
    find_max_repeating_number_in_array ();
    find_max_repeating_number_in_array_method2 ();
}

int main ()
{
    check_missing ();
    check_repeating ();
}