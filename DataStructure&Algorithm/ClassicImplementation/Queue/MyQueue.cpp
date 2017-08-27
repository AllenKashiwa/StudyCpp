#include "MyQueue.h"
#include <iostream>

using namespace std;

MyQueue::MyQueue(int queueCapacity) :m_iQueueCapacity(queueCapacity)
{
    ClearQueue();
    m_pQueue = new Customer[m_iQueueCapacity]();
}

MyQueue::~MyQueue()
{
    delete[] m_pQueue;
    m_pQueue = nullptr;
}

void MyQueue::ClearQueue()
{
    m_iHead = 0;
    m_iTail = 0;
    m_iQueueLen = 0;
}

bool MyQueue::QueueEmpty() const
{
    return m_iQueueLen == 0;
}

bool MyQueue::QueueFull() const
{
    return m_iQueueLen == m_iQueueCapacity;
}

int MyQueue::QueueLength() const
{
    return m_iQueueLen;
}

bool MyQueue::EnQueue(Customer element)
{
    if (QueueFull())
    {
        return false;
    }
    m_pQueue[m_iTail] = element;
    m_iTail++;
    m_iTail %= m_iQueueCapacity;
    m_iQueueLen++;
    return true;
}

bool MyQueue::DeQueue(Customer& element)
{
    if (QueueEmpty())
    {
        return false;
    }

    element = m_pQueue[m_iHead];
    m_iHead++;
    m_iHead %= m_iQueueCapacity;
    m_iQueueLen--;
    return true;
}

void MyQueue::QueueTraverse()
{
    cout << "Traverse:" << endl;
    for (size_t i = m_iHead; i < m_iQueueLen + m_iHead; i++)
    {
        m_pQueue[i%m_iQueueCapacity].printInfo();
    }
}