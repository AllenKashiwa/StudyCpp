// 1.11 & 1.19
#include <iostream>

void print_range(int low, int high)
{
    if (low > high)
    {
        print_range(high, low);
        return;
    }
    while (low <= high)
    {
        std::cout << low << std::endl;
        ++low;
    }
}

int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int low, high;
    std::cin >> low >> high;
    print_range(low, high);
    return 0;
}