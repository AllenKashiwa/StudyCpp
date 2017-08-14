// 尝试对常量引用赋值
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