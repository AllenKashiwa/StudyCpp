#include <iostream>
#include "Customer.h"
using namespace std;

Customer::Customer(string name, int age):m_strName(name),m_iAge(age)
{
}


void Customer::printInfo() const
{
    cout << "Name: " << m_strName
        << " Age: " << m_iAge << endl;
}
