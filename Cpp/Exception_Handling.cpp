#include <iostream>

void fun ()
{
    try
    {
        try
        {
            throw short(10);
        }
        catch (short x)
        {
            std::cout << "Caught exception here in short: " << x << std:: endl;
            throw 100;
        }
        catch (int x)
        {
            std::cout << "Caught exception here in int: " << x << std:: endl;
            throw 5.2;
        }
        catch (...)
        {
            std::cout << "Caught generic exception here: " << std:: endl;
        }
    }
    catch (...)
    {
        std::cout << "Caught generic exception at outside: " << std:: endl;
    }
}

class Base
{
    public:
        int x;
};

class Derived:public Base
{
    public:
        int y;
};

void fun2 ()
{
    try
    {
        throw Derived ();
    }
    catch (Derived d)
    {
        std::cout << "Caught exception here in Derived class block" << std:: endl;
    }
    catch (Base b)
    {
        std::cout << "Caught exception here in Base class block" << std:: endl;
    }
}

void fun3 ()
{
    try
    {
        throw Derived ();
    }
    catch (Base b)
    {
        std::cout << "Caught exception here in Base class block" << std:: endl;
    }
    catch (Derived d)
    {
        std::cout << "Caught exception here in Derived class block" << std:: endl;
    }
}

int main ()
{
    fun ();
    fun2 ();
    fun3 ();
}
