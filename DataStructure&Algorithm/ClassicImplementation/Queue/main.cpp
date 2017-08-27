#include <iostream>
#include <stdlib.h>
#include "MyQueue.h"

using namespace std;
// 环形队列的实现

int main()
{
    MyQueue *p = new MyQueue(4);

    p->EnQueue(10);
    p->EnQueue(12);
    p->EnQueue(16);
    p->EnQueue(17);
    p->EnQueue(29);
    p->QueueTraverse();

    cout << endl;
    cout << endl;

    int e = 0;
    p->DeQueue(e);
    cout << e << endl;

    p->DeQueue(e);
    cout << e << endl;

    cout << endl;
    cout << endl;

    p->QueueTraverse();

    cout << endl;
    cout << endl;

    p->ClearQueue();
    p->QueueTraverse();

    p->EnQueue(30);
    p->EnQueue(40);
    p->QueueTraverse();

    delete p;
    p = nullptr;
    system("pause");
    return 0;
}
