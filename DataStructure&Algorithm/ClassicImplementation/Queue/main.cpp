#include <iostream>
#include <stdlib.h>
#include "MyQueue.h"

using namespace std;
// 环形队列的实现

int main()
{
    MyQueue *p = new MyQueue(4);
    Customer c1("zhangesan", 20);
    Customer c2("lisi", 21);
    Customer c3("wangwu", 22);
    Customer c4("sunli", 23);

    p->EnQueue(c1);
    p->EnQueue(c2);
    p->EnQueue(c3);
    p->EnQueue(c4);
    p->QueueTraverse();

    cout << endl;
    cout << endl;

    Customer c5("", 0);
    p->DeQueue(c5);
    c5.printInfo();

    cout << endl;
    cout << endl;

    p->QueueTraverse();
    //p->DeQueue(e);
    //cout << e << endl;

    //cout << endl;
    //cout << endl;

    //p->QueueTraverse();

    //cout << endl;
    //cout << endl;

    //p->ClearQueue();
    //p->QueueTraverse();

    //p->EnQueue(30);
    //p->EnQueue(40);
    //p->QueueTraverse();

    delete p;
    p = nullptr;
    system("pause");
    return 0;
}
