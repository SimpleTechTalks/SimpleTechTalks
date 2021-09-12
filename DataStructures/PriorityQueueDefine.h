#ifndef _PRACTICE_PRIORITY_QUEUE_H_
#define _PRACTICE_PRIORITY_QUEUE_H_

#include <iostream>

typedef struct queue_node
{
    int m_data;
    int m_priority;
    struct queue_node* m_next;
} QueueNode;

class PriorityQueue
{
    public:
        QueueNode* m_start;
        PriorityQueue ();
        ~PriorityQueue ();
};

PriorityQueue::PriorityQueue ()
{
    m_start = NULL;
}

PriorityQueue::~PriorityQueue ()
{
    QueueNode* temp = NULL;
    while (m_start)
    {
        temp = m_start -> m_next;
        delete m_start;
        m_start = temp;
    }
}

#endif /* _PRACTICE_PRIORITY_QUEUE_H_ */