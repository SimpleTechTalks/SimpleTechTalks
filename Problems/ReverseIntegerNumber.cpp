/*
 * Reverse an integer.
 * Make it work for negative integers as well.
 * Example: 123 -> 321,  -123 -> -321 
 */
#include <iostream>
using namespace std;

int main ()
{
	int num = 0;
	cout << "Enter Number" << endl;
	cin >> num;

	int remainder = 0;
	int rev = 0;

	while (num != 0)
	{
		remainder = num % 10;
		rev = rev * 10 + remainder;
		num = num / 10;
		cout << remainder << endl;
	}

	cout << "Reversed Number: " << rev << endl; 
}