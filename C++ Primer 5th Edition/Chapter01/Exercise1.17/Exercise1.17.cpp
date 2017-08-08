// 1.17 & 1.18
#include <iostream>

int main()
{
    int curVal = 0, val = 0;
    if (std::cin >> curVal)
    {
        int cnt = 1;
        while (std::cin >> val)
        {
            if (curVal == val)
            {
                cnt++;
            }
            else
            {
                std::cout << curVal << " occurs " << cnt << " times" << std::endl;
                curVal = val;
                cnt = 1;
            }
        }
        std::cout << curVal << " occurs " << cnt << " times" << std::endl;
    }
    return 0;
}