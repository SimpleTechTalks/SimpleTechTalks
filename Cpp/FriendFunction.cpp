#include <iostream>
class Demo
{
	private:
		int m;
		int y;

	public:
		friend int sum (Demo d);
		void print_val ();
		Demo (int m, int y);
		friend class DoubleDemo;
};

class DoubleDemo
{
	public:
		void invoke ();
};

void DoubleDemo::invoke ()
{
	Demo d (10,20);
	d.print_val ();
	std::cout << "SUM: " << (d.m + d.y) << std::endl;
}

Demo::Demo (int x, int y): m (x), y (y)
{}

int sum (Demo d)
{
	return d.m + d.y;
}

void Demo::print_val ()
{
	std::cout << "Values are, x: " << m << " y: " << y << std::endl;
}

int main ()
{
	DoubleDemo d;
	d.invoke ();
}