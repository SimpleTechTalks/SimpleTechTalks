#include <iostream>
#include <stdio.h>
#include <sstream>

using namespace std;

template <typename T>
string ToString (T val)
{
	stringstream stream;
	stream << val;
	return stream.str ();
}

typedef struct name
{
	int id;
	string n;
}name_t;

#define DEF(x,y) x##y

int main ()
{
	name_t arr[] = {{0, "Id"},
					{1, "Name"},
					{2, "Class"}};

	char buf[100];
	snprintf (buf, sizeof (buf), "Hello %d", 10);
	char buf2[5];
	snprintf (buf2, sizeof (buf2), "Hello %d", 10);
	cout << "Inside main" << endl;
	cout << buf << endl;
	cout << buf2 << endl;
	cout << DEF ("SANDEEP", "FIRST NAME") << endl;
}
