#pragma once
class MyStack
{
public:
    MyStack(int size);
    ~MyStack();
    bool stackEmpty();
    bool stackFull();
    void clearStack();
    int stackLength();
    bool push(char elem);
    bool pop(char &elem);
    void stackTraverse(bool isFromBottom);
private:
    char *m_pBuffer;
    int m_iSize;
    int m_iTop;
};

