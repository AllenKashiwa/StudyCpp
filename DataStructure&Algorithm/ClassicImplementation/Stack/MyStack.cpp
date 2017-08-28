#include <iostream>
#include "MyStack.h"
using namespace std;

MyStack::MyStack(int size):m_iSize(size)
{
    m_pBuffer = new char[m_iSize];
    clearStack();
}

MyStack::~MyStack()
{
    delete[] m_pBuffer;
    m_pBuffer = nullptr;
}

bool MyStack::stackEmpty()
{
    return m_iTop == 0;
}

bool MyStack::stackFull()
{
    return m_iTop == m_iSize;
}

void MyStack::clearStack()
{
    m_iTop = 0;
}

int MyStack::stackLength()
{
    return m_iTop;
}

bool MyStack::push(char elem)
{
    if (stackFull())
    {
        return false;
    }
    m_pBuffer[m_iTop++] = elem;
    return true;
}

bool MyStack::pop(char& elem)
{
    if (stackEmpty())
    {
        return false;
    }
    elem = m_pBuffer[--m_iTop];
    return true;
}

void MyStack::stackTraverse(bool isFromBottom)
{
    if (isFromBottom)
    {
        for (int i = 0; i < stackLength(); i++)
        {
            cout << m_pBuffer[i] << " ";
        }
    }
    else
    {
        for (int i = stackLength()-1; i >= 0; i--)
        {
            cout << m_pBuffer[i] << " ";
        }
    }
    cout << endl;
}