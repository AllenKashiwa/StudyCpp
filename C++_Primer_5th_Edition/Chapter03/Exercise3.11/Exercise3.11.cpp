// ���ԶԳ������ø�ֵ
#include <iostream>
#include <string>

using namespace std;

int main()
{
    const string s = "Hello";
    for (auto &c : s)
    {
        c = 'X';
    }
    return 0;
}