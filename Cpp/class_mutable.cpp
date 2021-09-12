#include <iostream>

class MutableClass
{
    public:
        int a;
        mutable bool cache_valid;
        mutable int cache;
        static MutableClass default_obj;

    public:
        MutableClass (int val)
        {
            a = val;
            cache = a;
            cache_valid = true;
        }

        int return_value() const
        {
            if (!cache_valid)
            {
                calculateCache ();
                cache_valid = true;
            }
            return cache;
        }

        void calculateCache () const
        {
            cache = a;
        }

        void incrementVal ()
        {
            ++a;
            cache_valid = false;
        }

        static void set_default (int a);
};

MutableClass MutableClass::default_obj {100};

void MutableClass::set_default (int a)
{
    default_obj.a = a;
    default_obj.cache_valid = true;
    default_obj.cache = a;
}

int main ()
{
    MutableClass m{10};
    const MutableClass mc{11};

    int rt = m.return_value();
    int rt1 = mc.return_value();
    mc.set_default (111);
}
