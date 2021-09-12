#ifndef _PRACTICE_QUEUE_DEFINITION_H_
#define _PRACTICE_QUEUE_DEFINITION_H_

#include "StackDefine.h"

class Queue
{
    private:
        int m_front;
        int m_rear;
        int m_entries;
        int m_max_size;

        int* m_queue;

    public:
        Queue (int max);
        ~Queue ();
        int size ();
        int maxSize ();
        int enqueue (int entry);
        int dequeue ();
        bool isEmpty ();
        int atFront ();

        void print_content ()
        {
            int temp = m_rear;
            while (temp != m_front)
            {
                cout << m_queue[temp] << " ";
                temp = (temp + 1) % m_max_size;
            }
            cout << endl;
        }
};

Queue::Queue (int max): m_front(0),
                        m_rear (0),
                        m_entries (0),
                        m_max_size (max)
{
    m_queue = new int[max];

    if (!m_queue)
    {
        cout << "Queue initialization failed" << endl;
        return;
    }
}

Queue::~Queue ()
{
    if (!m_queue)
    {
        cout << "Queue is not initializaed" << endl;
        return;
    }
    delete [] m_queue;
}

int Queue::size ()
{
    return m_entries;
}

int Queue::maxSize ()
{
    return m_max_size;
}

int Queue::atFront ()
{
    if (!m_queue)
    {
        cout << "Queue is not initializaed" << endl;
        return -1;
    }

    if (m_entries == 0)
    {
        cout << "Queue is empty !!!" << endl;
        return -1;
    }
    return m_queue[m_rear];
}

int Queue::enqueue (int entry)
{
    if (!m_queue)
    {
        cout << "Queue is not initializaed" << endl;
        return -1;
    }

    if (m_entries == m_max_size)
    {
        cout << "Queue is full... can't take more entries!!" << endl;
        return -1;
    }

    m_queue[m_front] = entry;
    m_front = (m_front + 1) % m_max_size;
    m_entries++;
    return entry;
}

int Queue::dequeue ()
{
    if (!m_queue)
    {
        cout << "Queue is not initializaed" << endl;
        return -1;
    }

    if (m_entries == 0)
    {
        cout << "Queue is empty !!!" << endl;
        return -1;
    }

    int temp = m_queue[m_rear];
    --m_entries;
    m_rear = (m_rear + 1) % m_max_size;
    return temp;
}

bool Queue::isEmpty ()
{
    return !m_entries;
}

template <typename T>
class GenericQueue
{
    private:
        int m_front;
        int m_rear;
        int m_entries;
        int m_max_size;

        T* m_queue;

    public:
        GenericQueue (int max);
        ~GenericQueue ();
        int size ();
        T enqueue (T entry);
        T dequeue ();
        bool isEmpty ();
        T atFront ();
};

template <typename T>
GenericQueue<T>::GenericQueue (int max): m_front(0),
                                      m_rear (0),
                                      m_entries (0),
                                      m_max_size (max)
{
    m_queue = new T[max];

    if (!m_queue)
    {
        cout << "Queue initialization failed" << endl;
        return;
    }
}

template <typename T>
GenericQueue<T>::~GenericQueue ()
{
    if (!m_queue)
    {
        cout << "Queue is not initializaed" << endl;
        return;
    }
    delete [] m_queue;
}

template <typename T>
int GenericQueue<T>::size ()
{
    return m_entries;
}

template <typename T>
T GenericQueue<T>::atFront ()
{
    if (!m_queue)
    {
        cout << "Queue is not initializaed" << endl;
        return -1;
    }

    if (m_entries == 0)
    {
        cout << "Queue is empty !!!" << endl;
        return -1;
    }
    return m_queue[m_rear];
}

template <typename T>
T GenericQueue<T>::enqueue (T entry)
{
    if (!m_queue)
    {
        cout << "Queue is not initializaed" << endl;
        return entry;
    }

    if (m_entries == m_max_size)
    {
        cout << "Queue is full... can't take more entries!!" << endl;
        return entry;
    }

    m_queue[m_front] = entry;
    m_front = (m_front + 1) % m_max_size;
    m_entries++;
    return entry;
}

template <typename T>
T GenericQueue<T>::dequeue ()
{
    if (!m_queue)
    {
        cout << "Queue is not initializaed" << endl;
        return -1;
    }

    if (m_entries == 0)
    {
        cout << "Queue is empty !!!" << endl;
        return -1;
    }

    int temp = m_queue[m_rear];
    --m_entries;
    m_rear = (m_rear + 1) % m_max_size;
    return temp;
}

template <typename T>
bool GenericQueue<T>::isEmpty ()
{
    return !m_entries;
}

/* Programs to write
 * 1. Generic Queue -- done
 * 3. Reversing a Queue -- done
 * 4. Implement Queue using Two Stack -- done
 */
class QueueUsingStack
{
    private:
        Stack* m_enqueue_stack;
        Stack* m_dequeue_stack;

    public:
        QueueUsingStack (int max);
        ~QueueUsingStack ();
        int size ();
        int maxSize ();
        int enqueue (int entry);
        int dequeue ();
        bool isEmpty ();
        int atFront ();
};

QueueUsingStack::QueueUsingStack (int max)
{
    m_enqueue_stack = new Stack(max);
    m_dequeue_stack = new Stack(max);
}

QueueUsingStack::~QueueUsingStack ()
{
    delete m_dequeue_stack;
    delete m_enqueue_stack;
}

int QueueUsingStack::size ()
{
    if (m_enqueue_stack -> entries ())
    {
        return m_enqueue_stack -> entries ();
    }
    else if (m_dequeue_stack -> entries ())
    {
        return m_dequeue_stack -> entries ();
    }
    return 0;
}

int QueueUsingStack::maxSize ()
{
    return m_enqueue_stack -> maxSize ();
}

bool QueueUsingStack::isEmpty ()
{
    return m_enqueue_stack -> isEmpty () || m_dequeue_stack -> isEmpty ();
}

int QueueUsingStack::enqueue (int entry)
{
    while (!m_dequeue_stack -> isEmpty ())
    {
        int data = m_dequeue_stack -> pop ();
        m_enqueue_stack -> push (data);
    }
    m_enqueue_stack -> push (entry);
    return entry;
}

int QueueUsingStack::dequeue ()
{
    while (!m_enqueue_stack -> isEmpty ())
    {
        int data = m_enqueue_stack -> pop ();
        m_dequeue_stack -> push (data);
    }
    if (m_dequeue_stack -> isEmpty ())
    {
        return -1;
    }
    return m_dequeue_stack -> pop ();
}

int QueueUsingStack::atFront ()
{
    while (!m_enqueue_stack -> isEmpty ())
    {
        int data = m_enqueue_stack -> pop ();
        m_dequeue_stack -> push (data);
    }
    if (m_dequeue_stack -> isEmpty ())
    {
        return -1;
    }
    return m_dequeue_stack -> atTop ();
}

#endif /* _PRACTICE_QUEUE_DEFINITION_H_ */