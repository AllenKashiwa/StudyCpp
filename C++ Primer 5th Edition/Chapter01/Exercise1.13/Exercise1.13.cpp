#include <iostream>

// 1.9
//int main()
//{
//    int sum = 0;
//    for (int val = 50; val <= 100; val++)
//    {
//        sum += val;
//    }
//    std::cout << "The sum of 50 to 100 inclusive is " << sum << std::endl;
//    return 0;
//}

// 1.10
//int main()
//{
//    for (int val = 10; val >= 0; --val)
//    {
//        std::cout << val << std::endl;
//    }
//    return 0;
//}

// 1.11
void print_range(int low, int high)
{
    if (low > high)
    {
        print_range(high, low);
        return;
    }
    for (; low <= high; low++)
    {
        std::cout << low << std::endl;
    }
}
int main()
{
    std::cout << "Enter two numbers:" << std::endl;
    int low = 0, high = 0;
    std::cin >> low >> high;
    print_range(low, high);
    return 0;
}