#include <iostream>

using namespace std;
class Base
{
	public:
		int m;

		Base (int x): m (x)
		{
			cout << "Inside Base::Base ()" << endl;
		}

		virtual int get ()
		{
			cout << "Inside Base::get ()" << endl;
			return m;
		}
		virtual void set (int a)
		{
			cout << "Inside Base::set ()" << endl;
			m = a;
		}
};

class Derived: public Base
{
	public:
		Derived (int m): Base (m)
		{
			cout << "Inside Derived::Derived ()" << endl;
		}

		int get ()
		{
			cout << "Inside Derived::get ()" << endl;
			return m;
		}
		void set (int a)
		{
			cout << "Inside Derived::set ()" << endl;
			m = a;
		}
};

template <class T>
class NUM
{
	public:
		void demo ()
		{
			cout << "Inside NUM" << endl;
		}
};

template <class T>
class SQR_NUM: public NUM <T>
{
	public:
		void demo ()
		{
			cout << "Inside SQR_NUM" << endl;
		}
};

void demo_const_cast_pointer (const int *val)
{
	int *p;

	p = const_cast <int *> (val);
	*p = *val * 10;
}

void demo_const_cast_reference (const int &val)
{
	int &p = const_cast <int &> (val);

	p = p * 20;
}

void fun ()
{
	int i = 70;
	char *x = (char *)&i; /* No compile error */
	/* Below line will throw compile error */
	//cout << "Initial value: " << i << " After casting as char: " << static_cast <char *> (i) << endl;
	cout << "Initial value: " << i << " After casting as char: " << static_cast <char> (i) << endl;
}

void reinterprate_fun ()
{
	int i = 70;
	int *p = reinterpret_cast <int *> (i);
	cout << "Initial value: " << i << " converted address: " << p << endl;

	int *a = &i;
	NUM<int> *b = reinterpret_cast <NUM <int > *> (a);
	int *c = reinterpret_cast <int *> (b);
	cout << "Initial value: " << *a << " Coming back value: " << *c << endl;
}

int main ()
{
	Base *bp;
	Derived *dp;

	bp = new Derived (10);
	bp -> get ();
	dp = dynamic_cast <Derived *> (bp);
	if (dp)
	{
		cout << "dynamic_cast Type casting works !!!" << endl;
		dp -> get ();
	}
	delete bp;

	SQR_NUM <int> *sq;
	NUM <int> *num;
	SQR_NUM <int> x;
	NUM <int> y;
	SQR_NUM <double> z;
	/* Note here that dynamic_case is not applicable for one type of template pointer to another*/
	num = dynamic_cast <SQR_NUM <int> *> (&x);

	if (num) {
		cout << "Cast from SQR_NUM to NUM is OK!!" << endl;
		num -> demo ();
	} else {
		cout << "Cast from SQR_NUM to NUM is NOT OK!!" << endl;
	}

	/* Check for const_cast */
	int val = 5;
	cout << "Initial value: " << val << endl;
	demo_const_cast_pointer (&val);
	cout << "After using const_cast_pointer: " << val << endl;
	demo_const_cast_reference (val);
	cout << "After using const_cast_reference: " << val << endl;
	fun ();
	reinterprate_fun ();
}