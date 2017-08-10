// 1.9
//#include <iostream>
//using std::cout;
//using std::endl;
//
//int main()
//{
//    int sum = 0;
//    int i = 50;
//    while (i <= 100)
//    {
//        sum += i;
//        i++;
//    }
//    cout << "The sum of 50 to 100 is " << sum << endl;
//    return 0;
//}

// 1.10
//#include <iostream>
//using std::cout;
//using std::endl;
//
//int main()
//{
//    int i = 10;
//    while (i >= 0)
//    {
//        cout << i << " ";
//        i--;
//    }
//    cout << endl;
//    return 0;
//}

// 1.11
//#include <iostream>
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main()
//{
//    cout << "Enter two numbers:" << endl;
//    int v1, v2;
//    cin >> v1 >> v2;
//    if (v1 > v2)
//    {
//        while (v1 >= v2)
//        {
//            cout << v1 << " ";
//            v1--;
//        }
//    }
//    else
//    {
//        while (v1 <= v2)
//        {
//            cout << v1 << " ";
//            v1++;
//        }
//    }
//    cout << endl;
//    return 0;
//}

// 2.41
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

class Sales_data {
    friend istream& operator >> (istream&, Sales_data&);
    friend ostream& operator << (ostream&, const Sales_data&);
    friend bool operator < (const Sales_data&, const Sales_data&);
    friend bool operator == (const Sales_data&, const Sales_data&);
public:
    Sales_data() = default;
    Sales_data(const string &book):bookNo(book){}
    Sales_data(istream &is) { is >> *this; }
public:
    Sales_data& operator += (const Sales_data&);
    string isbn() const { return bookNo; }
private:
    string bookNo;
    unsigned units_sold = 0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0;
};

inline bool compareIsbn(const Sales_data &lhs,const Sales_data &rhs)
{
    return lhs.isbn() == rhs.isbn();
}

Sales_data operator + (const Sales_data&, const Sales_data&);

inline bool operator == (const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.units_sold == rhs.units_sold &&
        lhs.sellingprice == rhs.sellingprice &&
        lhs.saleprice == rhs.saleprice &&
        lhs.isbn() == rhs.isbn();
}

inline bool operator != (const Sales_data &lhs, const Sales_data &rhs)
{
    return !(lhs == rhs);
}

Sales_data& Sales_data::operator+=(const Sales_data& rhs)
{
    units_sold += rhs.units_sold;
    saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);
    if (sellingprice != 0)
    {
        discount = saleprice / sellingprice;
    }
    return *this;
}

Sales_data operator + (const Sales_data& lhs, const Sales_data& rhs)
{
    Sales_data ret(lhs);
    ret += rhs;
    return ret;
}

istream& operator >> (istream& in, Sales_data& s)
{
    in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
    if (in && s.sellingprice != 0)
    {
        s.discount = s.saleprice / s.sellingprice;
    }
    else
    {
        s = Sales_data();
    }
    return in;
}

ostream& operator << (ostream& out, const Sales_data& s)
{
    cout << s.isbn() << " " << s.units_sold << " "
        << s.sellingprice << " " << s.saleprice << " " << s.discount;
    return out;
}

int main()
{
    Sales_data book;
    cout << "Enter sales data: " << endl;
    while (cin >> book)
    {
        cout << "ISBN, units_sold, saleprice, sellingprice, discount:"
            << book << endl;
    }
    Sales_data trans1, trans2;
    cout << "Enter two same sales data:" << endl;
    cin >> trans1 >> trans2;
    if (compareIsbn(trans1, trans2))
    {
        cout << "Info:ISBN, units_sold, selling price, discout:"
            << trans1 + trans2 << endl;
    }
    else
    {
        cout << "Different Sales data" << endl;
    }
    Sales_data total, trans;
    cout << "Enter some sales data have same isbn" << endl;
    if (cin >> total)
    {
        while (cin >> trans)
        {
            if (compareIsbn(total,trans))
            {
                total = total + trans;
            }
            else
            {
                cout << "Different isbn" << endl;
                break;
            }
        }
        cout << "Info:ISBN, units_sold, selling price, discout:"
            << total << endl;
    }
    else
    {
        cout << "No data" << endl;
        return -1;
    }

    int num = 1;
    cout << "Enter some sales data:" << endl;
    if (cin >> trans1)
    {
        while (cin >> trans2)
        {
            if (compareIsbn(trans1, trans2))
            {
                num++;
            }
            else
            {
                cout << trans1.isbn() << " count " << num << " items" << endl;
            }
        }
    }
    else
    {
        cout << "No data" << endl;
        return -1;
    }
    return 0;
}