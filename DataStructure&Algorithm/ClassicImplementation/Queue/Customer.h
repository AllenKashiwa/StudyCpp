#pragma once
#include <string>
using namespace std;

class Customer
{
public:
    Customer(string name = "", int age = 0);
    void printInfo() const;
private:
    string m_strName;
    int m_iAge;
};

