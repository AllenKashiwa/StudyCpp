// 比较字符串大小
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    string s1, s2;
//    cout << "请输入两个字符串： " << endl;
//    cin >> s1 >> s2;
//    if (s1 == s2)
//    {
//        cout << "两个字符串相等" << endl;
//    }
//    else if (s1 > s2)
//    {
//        cout << s1 << " 大于 " << s2 << endl;
//    }
//    else
//    {
//        cout << s1 << " 小于 " << s2 << endl;
//    }
//    return 0;
//}

// 比较字符串长度
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    cout << "请输入两个字符串: " << endl;
    cin >> s1 >> s2;
    auto len1 = s1.size();
    auto len2 = s2.size();
    if (len1 == len2)
    {
        cout << s1 << " 和 " << s2 << " 的长度都是 " << len1 << endl;
    }
    else if(len1 > len2)
    {
        cout << s1 << " 比 " << s2 << " 的长度多 " << len1 - len2 << endl;
    }
    else
    {
        cout << s1 << " 比 " << s2 << " 的长度小 " << len2 - len1 << endl;
    }
    return 0;
}