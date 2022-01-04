/*
 * Given the number of digits N as well as the sum S of all the digits,
 * Find the largest number of N digits that can be possible with given sum S.
 * Input:    Digits = 5   Sum = 12 
 * Output:  93000 
 * 
 */
#include <iostream>

using namespace std;

int main ()
{
	int digit = 0;
	int sum = 0;

	cout << "Enter Digits" << endl;
	cin >> digit;

	cout << "Enter Sum" << endl;
	cin >> sum;

	int number = 0;

	for (int i = 0; i < digit; i++)
	{
		if (sum > 9) {
			number = number * 10 + 9;
			sum -= 9;
		} else {
			number = number * 10 + sum;
			sum -= sum;
		}
	}
	cout << "Highest number with Digits: " << digit << " and sum: " << sum << " is: " << number << endl;
}