#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cout << "������һ���ַ��������԰����ո�" << endl;
    getline(cin, s);
    for (auto &c : s)
    {
        c = 'X';
    }
    cout << s << endl;
    return 0;
}