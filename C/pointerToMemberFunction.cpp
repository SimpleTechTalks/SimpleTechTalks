#include <iostream>

using namespace std;
class FooAbstract
{
	public:
		virtual int temp (int x)
		{
			cout << "Inside FooAbstract function temp with x: " << x << endl;
		}
};

class Foo1: public FooAbstract
{
	public:
		int temp (int x)
		{
			cout << "Inside Foo1 function temp with x: " << x << endl;
		}
};

class Foo2: public FooAbstract
{
	public:
		int temp (int x)
		{
			cout << "Inside Foo2 function temp with x: " << x << endl;
		}
};

typedef int (FooAbstract::* FooFnPtr) (int);

int main ()
{
	cout << "inside main" << endl;
	FooAbstract f3;
	Foo1 f1;
	Foo2 f2;
	FooFnPtr fptr1 = &FooAbstract::temp;

	(f3.*fptr1) (10);
	(f1.*fptr1) (10);
	(f2.*fptr1) (10);
}
