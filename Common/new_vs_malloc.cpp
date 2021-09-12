#include <iostream>
#include <unistd.h>

class Base
{
    public:
        int a;
        char b;
        Base (int a, char c);
        ~Base ();
};

Base::Base (int a, char c): a(a), b(c)
{
    std::cout << "Inside Constructor" << std::endl;
}

Base::~Base ()
{
    std::cout << "Inside Destructor " << std::endl;
}

void fun ()
{
    std::cout << "Calling New" << std::endl;
    Base* using_new = new Base(4,'n');
    std::cout << "Calling Malloc" << std::endl;
    Base* using_malloc = (Base*) malloc (sizeof (Base));

    std::cout << "Calling Delete" << std::endl;
    delete using_new;
    std::cout << "Calling free" << std::endl;
    free (using_malloc);
}

void fun2 ()
{
    std::cout << "Calling New" << std::endl;
    Base* using_new = new Base(4,'n');
    std::cout << "Calling Malloc" << std::endl;
    Base* using_malloc = (Base*) malloc (sizeof (Base));

    std::cout << "Calling Delete" << std::endl;
    delete using_malloc;
    std::cout << "Calling free" << std::endl;
    free (using_new);
}

int main ()
{
    fun ();
    fun2 ();
}
