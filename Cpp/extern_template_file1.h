#include <iostream>

using namespace std;
template <class T>
void fun (T val)
{
	cout << "Inside function" << endl;
}

template <class T>
class NUM
{
	public:
		void print ()
		{
			cout << "Inside NUM::print ()" << endl;
		}
};