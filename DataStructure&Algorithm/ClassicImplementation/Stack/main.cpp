#include <iostream>
#include "stdlib.h"
#include "MyStack.h"
using namespace std;

int main()
{
    MyStack* pStack = new MyStack(5);
    if (pStack->stackEmpty())
    {
        cout << "stack is empty" << endl;
    }

    pStack->push('W');
    pStack->push('o');
    pStack->push('r');
    pStack->push('l');
    pStack->push('d');

    pStack->stackTraverse(true);
    pStack->stackTraverse(false);
    if (pStack->stackFull())
    {
        cout << "stack is full" << endl;
    }

    char e;
    pStack->pop(e);
    cout << e << endl;

    delete pStack;
    pStack = nullptr;
    system("pause");
    return 0;
}