#include<iostream>

constexpr int product (int x)
{
    return (x * x);
}

int main()
{
	std::cout << "Inside Main\a \n";
	int i = 10;
	// int j {5.6}; // This should throw error as j is int. Float to Int conversion is not allowed in case of initializer list.
    int k = product (i);
    std::cout << "Product of square of i:" << i << " is \"" << k << "\""<< std::endl;

}
