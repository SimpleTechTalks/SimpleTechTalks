#include <iostream>
#include <string>

using namespace std;

string* f1 ()
{
	string* ret = new string ();
	ret->append ("Hello my name is");
	ret->append (" Sandeep");
	(*ret) += " Kumar";
	return ret;
}

int main ()
{
	cout << "Inside main: " << *(f1 ()) << endl;
}
