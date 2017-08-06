#include <iostream>

int main()
{
    int val = 10;
    while (val >= 1)
    {
        std::cout << val << " ";
        --val;
    }
    std::cout << std::endl;
    return 0;
}