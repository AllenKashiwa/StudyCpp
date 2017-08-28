#include <iostream>
#include "stdlib.h"
#include "MyStack.h"
#include "Coordinate.h"
using namespace std;

int main()
{
    // stack for char
    //MyStack* pStack = new MyStack(5);
    //if (pStack->stackEmpty())
    //{
    //    cout << "stack is empty" << endl;
    //}

    //pStack->push('W');
    //pStack->push('o');
    //pStack->push('r');
    //pStack->push('l');
    //pStack->push('d');

    //pStack->stackTraverse(true);
    //pStack->stackTraverse(false);
    //if (pStack->stackFull())
    //{
    //    cout << "stack is full" << endl;
    //}

    //char e;
    //pStack->pop(e);
    //cout << e << endl;

    //delete pStack;
    //pStack = nullptr;

    // stack for coordinate
    Coordinate c1;
    Coordinate c2(3, 7);
    Coordinate c3(6, 9);
    MyStack<Coordinate>* pStack = new MyStack<Coordinate>(5);
    pStack->push(c1);
    pStack->push(c2);
    pStack->push(c3);

    pStack->stackTraverse(true);
    pStack->stackTraverse(false);
    delete pStack;
    pStack = nullptr;
    system("pause");
    return 0;
}