// Exercise3.3 
// 1.string的方式: 标准库string的输入运算符自动忽略字符串开头的空白，从第一个真正的字符开始读起，直到遇到下一处空白为止
// 2.getline的方式: getline从给定的输入流中读取数据，直到遇到换行符为止，此时换行符也被读取进来，但是并不存储在最后的字符串中
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word, line;
    cout << "请选择读取字符串的方式：1 表示逐词读取，2 表示整行读取" << endl;
    char ch;
    cin >> ch;
    if (ch == '1')
    {
        cout << "请输入字符串：   Welcome to C++ family!   " << endl;
        cin >> word;
        cout << "系统读取的有效字符串是：" << endl;
        cout << word << endl;
        return 0;
    }
    // 清空输入缓冲区
    cin.clear();
    cin.sync();
    if (ch == '2')
    {
        cout << "请输入字符串 :   Welcome to C++ family!    " << endl;
        getline(cin, line);
        cout << "系统读取的有效字符串是： " << endl;
        cout << line << endl;
        return 0;
    }
    cout << "您的输入有误!";
    return -1;
}