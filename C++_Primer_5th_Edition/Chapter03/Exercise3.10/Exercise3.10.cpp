// 1
//#include <iostream>
//#include <string>
//#include <cctype>
//
//using namespace std;
//
//int main()
//{
//    string s;
//    cout << "请输入一个带标点符号的字符串" << endl;
//    getline(cin, s);
//    for (auto c : s)
//    {
//        if (!ispunct(c))
//        {
//            cout << c;
//        }
//    }
//    cout << endl;
//    return 0;
//}

// 2
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string s, result;
    cout << "请输入一个带标点符号的字符串" << endl;
    getline(cin, s);
    for (decltype(s.size()) i = 0;i < s.size();++i)
    {
        if (!ispunct(s[i]))
        {
            result += s[i];
        }
    }
    cout << result << endl;
    return 0;
}