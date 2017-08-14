// while

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    string s;
//    cout << "请输入一个字符串，可以包含空格：" << endl;
//    getline(cin, s);
//    int i = 0;
//    while (s[i] != '\0')
//    {
//        s[i] = 'X';
//        ++i;
//    }
//    cout << s << endl;
//    return 0;
//}

// for

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cout << "请输入一个字符串，可以包含空格：" << endl;
    getline(cin, s);
    for (unsigned int i = 0; i < s.size(); i++)
    {
        s[i] = 'X';
    }

    cout << s << endl;
    return 0;
}