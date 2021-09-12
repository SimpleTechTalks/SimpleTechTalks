#include <iostream>

using namespace std;

#include "SortingDefine.h"

int main () {
    int arr[] = {10, 15, 17, 32, 6, 8, 21, 98, 11};
    Sorting s(arr, (sizeof (arr) / sizeof (arr[0])));
    s.print_array ();
    s.bubble_sort ();
    s.print_array ();
}
