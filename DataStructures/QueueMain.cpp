#include <iostream>

using namespace std;

#include "QueueDefine.h"

void reverse_queue (Queue* q)
{
    if (q->isEmpty ())
    {
        cout << "Queue is empty" << endl;
    }

    cout << "Queue content intially " << endl;
    q -> print_content ();
    Stack s(q -> maxSize ());

    while (!q -> isEmpty ())
    {
        int data = q -> dequeue ();
        s.push (data);
    }

    while (!s.isEmpty ())
    {
        int data = s.pop ();
        q -> enqueue (data);
    }
    cout << "Queue content finally " << endl;
    q -> print_content ();
}

void reverse_queue_using_queue (Queue* q, Queue* final)
{
    if (q -> isEmpty ())
        return;

    int data = q -> dequeue ();
    reverse_queue_using_queue (q, final);
    final -> enqueue (data);
}

void check_reverse_queue ()
{
    Queue q(10);
    q.enqueue (1);
    q.enqueue (2);
    q.enqueue (3);
    q.enqueue (4);
    q.enqueue (5);
    q.enqueue (6);
    q.enqueue (7);
    reverse_queue (&q);
}

void check_reverse_queue_using_queue ()
{
    Queue q(10);
    Queue final(10);
    q.enqueue (1);
    q.enqueue (2);
    q.enqueue (3);
    q.enqueue (4);
    q.enqueue (5);
    q.enqueue (6);
    q.enqueue (7);
    cout << "Queue content intially " << endl;
    q.print_content ();
    reverse_queue_using_queue (&q, &final);
    cout << "Queue content finally " << endl;
    final.print_content ();
}

void reverse_queue_simple (Queue* q)
{
    if (q -> isEmpty ())
        return;

    int data = q -> dequeue ();
    reverse_queue_simple (q);
    q -> enqueue (data);
}

void check_reverse_queue_simple ()
{
    Queue q(10);
    q.enqueue (1);
    q.enqueue (2);
    q.enqueue (3);
    q.enqueue (4);
    q.enqueue (5);
    q.enqueue (6);
    q.enqueue (7);
    cout << "Queue content intially " << endl;
    q.print_content ();
    reverse_queue_simple (&q);
    cout << "Queue content finally " << endl;
    q.print_content ();
}

void check_queue()
{
    Queue q(6);
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (1) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (2) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (3) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (4) << " Total entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (5) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (6) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (7) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (8) << " Total entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (9) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (10) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (11) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (12) << " Total entries: " << q.size () << endl;
    cout << "Is Queue Empty: " << q.isEmpty () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Is Queue Empty: " << q.isEmpty () << endl;
}

void check_generic_queue()
{
    GenericQueue<int> q(6);
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (1) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (2) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (3) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (4) << " Total entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (5) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (6) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (7) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (8) << " Total entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (9) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (10) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (11) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (12) << " Total entries: " << q.size () << endl;
    cout << "Is Queue Empty: " << q.isEmpty () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Is Queue Empty: " << q.isEmpty () << endl;
}

void check_queue_using_stack ()
{
    QueueUsingStack q(10);
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (1) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (2) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (3) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (4) << " Total entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (5) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (6) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (7) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (8) << " Total entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (9) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (10) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (11) << " Total entries: " << q.size () << endl;
    cout << "Enqueuing value: " << q.enqueue (12) << " Total entries: " << q.size () << endl;
    cout << "Is Queue Empty: " << q.isEmpty () << endl;
    cout << "Front element: " << q.atFront () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Dequeuing value: " << q.dequeue () << " Remaining entries: " << q.size () << endl;
    cout << "Is Queue Empty: " << q.isEmpty () << endl;
}

int main ()
{
    //check_queue ();
    //check_generic_queue ();
    //check_reverse_queue ();
    //check_reverse_queue_using_queue ();
    //check_reverse_queue_simple ();
    check_queue_using_stack ();
}
