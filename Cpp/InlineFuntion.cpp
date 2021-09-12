#include <chrono>
#include <iostream>
 
using namespace std;
using namespace std::chrono;

int normal_function (int n)
{
	// Doing some random stuff
	int x = 20;
	int y = 55;
	int z = (x + y) * (y - x) * (x/y) * x * y;
	return z;
}

static inline int inline_function (int n)
{
	// Doing some random stuff
	int x = 20;
	int y = 55;
	int z = (x + y) * (y - x) * (x/y) * x * y;
	return z;
}

class InlineExample
{
	private:
		int m;
		// automatic inline
		InlineExample (int x): m(x)
		{}
		int get_value ()
		{
			return m;
		}
};

int main ()
{
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		long long unsigned int fact = inline_function (20);
	}
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	high_resolution_clock::time_point t3 = high_resolution_clock::now();
	for (int i = 0; i < 1000000; i++) {
		long long unsigned int inline_fact = normal_function (20);
	}
	high_resolution_clock::time_point t4 = high_resolution_clock::now();
	// Calculating execution time in both the approaches
    auto inlineDuration = duration_cast<microseconds>( t2 - t1 ).count();
    auto normalDuration = duration_cast<microseconds>( t4 - t3 ).count();
 
    cout<<"Calculation of random took "<<normalDuration<<" microseconds using normal function call"<<endl;
    cout<<"Calculation of random took "<<inlineDuration<<" microseconds using inline function call"<<endl;

}