#include <iostream>
#include <memory>

using namespace std;

int main ()
{
	int* x = new int(10);
	int* y = new int(20);
	unique_ptr<int> p = (unique_ptr<int>)(x);
	cout << x << "   " << *p << endl;
	unique_ptr<int> q = move (p);
	cout << x << "   " << "   " << *q << " " << q.release () << endl;
	if (q)
		cout << x << "   " << "   " << *q << " " << q.release () << endl;
	shared_ptr<int> s1 = shared_ptr<int> (y);
	cout << s1.use_count () << endl;
	shared_ptr<int> s2 = s1;
	cout << s1.use_count () << "  " << s2.use_count () << endl;
	s1.reset ();
	cout << s1.use_count () << "  " << s2.use_count () << endl;
	weak_ptr<int> w1 = s2;
	cout << s1.use_count () << "  " << s2.use_count () << "  " << w1.use_count () << endl;
}