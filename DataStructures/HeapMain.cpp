#include "PriorityQueue.h"
#include "MaxHeap.h"

using namespace std;
void testMinHeap ()
{
	PriorityQueue q;
	q.print_content ();
	q.insert (30);
	q.print_content ();
	q.insert (50);
	q.print_content ();
	q.insert (10);
	q.print_content ();
	q.insert (60);
	q.print_content ();
	q.insert (3);
	q.print_content ();
	while (!q.isEmpty ())
	{
		cout << "Minimum value: " << q.find_minimum () << " Size: " << q.get_size () << endl;
		q.delete_minimum ();
	}
}

void testMaxHeap ()
{
	MaxHeap q;
	q.print_content ();
	q.insert (30);
	q.print_content ();
	q.insert (50);
	q.print_content ();
	q.insert (10);
	q.print_content ();
	q.insert (60);
	q.print_content ();
	q.insert (3);
	q.print_content ();
	while (!q.isEmpty ())
	{
		cout << "Maximum value: " << q.find_maximum () << " Size: " << q.get_size () << endl;
		q.delete_maximum ();
	}
}

int main ()
{
	testMinHeap ();
	testMaxHeap ();
}
