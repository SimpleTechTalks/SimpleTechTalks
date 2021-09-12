#include <iostream>

using namespace std;
class BaseWithoutVirtual
{
	public:
		~BaseWithoutVirtual ()
		{
			cout << "Inside BaseWithoutVirtual Destructor." << endl;
		}

		void print ()
		{
			cout << "BaseWithoutVirtual version called." << endl;
		}

		void pure_virtual_fun ()
		{}
};

class Base
{
	public:
		virtual ~Base ()
		{
			cout << "Inside Base Destructor." << endl;
		}

		virtual void print ()
		{
			cout << "Base version called." << endl;
		}

		virtual void pure_virtual_fun () = 0;
};

class Derived:public Base
{
	public:
		virtual ~Derived ()
		{
			cout << "Inside Derived Destructor." << endl;
		}

		void print () /* virtual keyword not needed */
		{
			cout << "Derived version called." << endl;
		}

		void pure_virtual_fun ()
		{
			cout << "Derived class version for pure_virtual_fun" << endl;
		}
};

int main ()
{
	Base *p = new Derived ();
	p -> print ();
	p -> pure_virtual_fun ();
	delete p;
	/* Not allowed to create Base class object as it has pure virtual function. */
	/*
	p = new Base ();
	p -> print ();
	p -> pure_virtual_fun ();
	delete p;*/

	cout << "Derived class object size: " << sizeof (Derived) << endl;
	cout << "Base Without Virtual class object size: " << sizeof (BaseWithoutVirtual) << endl;
}

