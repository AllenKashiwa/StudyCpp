// while

//#include <iostream>
//#include <string>
//
//using namespace std;
//
//int main()
//{
//    string s;
//    cout << "������һ���ַ��������԰����ո�" << endl;
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
    cout << "������һ���ַ��������԰����ո�" << endl;
    getline(cin, s);
    for (unsigned int i = 0; i < s.size(); i++)
    {
        s[i] = 'X';
    }

    cout << s << endl;
    return 0;
}