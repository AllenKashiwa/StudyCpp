// 1.23 & 1.24
#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item trans1, trans2;
    int num = 1;
    std::cout << "Enter transition records:" << std::endl;
    if (std::cin >> trans1)
    {
        while (std::cin >> trans2)
        {
            if (trans1.isbn() == trans2.isbn())
            {
                num++;
            }
            else {
                std::cout << trans1.isbn() << " counts " << num << " times." << std::endl;
                trans1 = trans2;
                num = 1;
            }
        }
        std::cout << trans1.isbn() << " counts " << num << " times." << std::endl;
    }
    else
    {
        std::cout << "no data" << std::endl;
        return -1;
    }
    return 0;
}