#include <iostream>

int main()
{
    int sum = 0, vl = 50;
    while (vl <= 100)
    {
        sum += vl;
        ++vl;
    }
    std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;
    return 0;
}