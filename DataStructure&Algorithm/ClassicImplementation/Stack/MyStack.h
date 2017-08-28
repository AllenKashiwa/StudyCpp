#pragma once
#include <iostream>
using namespace std;

template <typename T>
class MyStack
{
public:
    MyStack(int size);
    ~MyStack();
    bool stackEmpty();
    bool stackFull();
    void clearStack();
    int stackLength() const;
    bool push(T elem);
    bool pop(T &elem);
    void stackTraverse(bool isFromBottom) const;
private:
    T *m_pBuffer;
    int m_iSize;
    int m_iTop;
};

template <typename T>
MyStack<T>::MyStack(int size) :m_iSize(size)
{
    m_pBuffer = new T[m_iSize];
    clearStack();
}

template <typename T>
MyStack<T>::~MyStack()
{
    delete[] m_pBuffer;
    m_pBuffer = nullptr;
}

template <typename T>
bool MyStack<T>::stackEmpty()
{
    return m_iTop == 0;
}

template <typename T>
bool MyStack<T>::stackFull()
{
    return m_iTop == m_iSize;
}

template <typename T>
void MyStack<T>::clearStack()
{
    m_iTop = 0;
}

template <typename T>
int MyStack<T>::stackLength() const
{
    return m_iTop;
}

template <typename T>
bool MyStack<T>::push(T elem)
{
    if (stackFull())
    {
        return false;
    }
    m_pBuffer[m_iTop++] = elem;
    return true;
}

template <typename T>
bool MyStack<T>::pop(T& elem)
{
    if (stackEmpty())
    {
        return false;
    }
    elem = m_pBuffer[--m_iTop];
    return true;
}

template <typename T>
void MyStack<T>::stackTraverse(bool isFromBottom) const
{
    if (isFromBottom)
    {
        for (int i = 0; i < stackLength(); i++)
        {
            cout << m_pBuffer[i];
            //m_pBuffer[i].printCoordinate();
        }
    }
    else
    {
        for (int i = stackLength() - 1; i >= 0; i--)
        {
            cout << m_pBuffer[i];
            //m_pBuffer[i].printCoordinate();
        }
    }
    cout << endl;
}
