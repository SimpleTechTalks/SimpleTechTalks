// header.h

template <typename T>
void DemoTemplateFunction ()
{
    // Body
}

template <class T>
class NUM
{
	// Body
}

// source1.cpp

#include "header.h"
void demo1 ()
{
    DemoTemplateFunction <int> ();
	template class NUM <int>;
}

// source2.cpp

#include "header.h"
void demo2 ()
{
    DemoTemplateFunction <int> ();
	template class NUM <int>;
}