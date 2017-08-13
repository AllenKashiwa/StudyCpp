#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string s;
    /*while (getline(cin,s))
    {
        cout << s << endl;
    }*/

    while (cin >> s)
    {
        cout << s << endl;
    }
    return 0;
}