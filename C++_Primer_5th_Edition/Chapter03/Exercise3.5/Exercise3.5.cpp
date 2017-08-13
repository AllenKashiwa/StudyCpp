// 连接多个字符串
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    char cont;
//    string s, result;
//    cout << "请输入第一个字符串: " << endl;
//    while (cin >> s)
//    {
//        result += s;
//        cout << "是否继续(y or no)?" << endl;
//        cin >> cont;
//        if (cont == 'Y' || cont == 'y')
//        {
//            cout << "请输入下一个字符:" << endl;
//        }
//        else
//        {
//            break;
//        }
//    }
//    cout << "结果字符串为:" << result << endl;
//    return 0;
//}

// 连接字符串并以空格符分隔
#include <iostream>
#include <string>

using namespace std;

int main()
{
    char cont;
    string s, result;
    cout << "请输入第一个字符串：" << endl;
    while (cin >> s)
    {
        if (result.size())
        {
            s = " " + s;
        }
        result += s;
        cout << "是否继续(y or n)?" << endl;
        cin >> cont;
        if (cont == 'Y' || cont == 'y')
        {
            cout << "请输入下一个字符串：" << endl;
        }
        else
        {
            break;
        }
    }
    cout << "拼接后的字符串是：" << result << endl;
    return 0;

}