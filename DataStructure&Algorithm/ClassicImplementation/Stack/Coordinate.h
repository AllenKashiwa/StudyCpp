#pragma once
#include <ostream>
using namespace std;

class Coordinate
{
    friend ostream &operator<<(ostream &out, Coordinate& coor);
public:
    Coordinate(int x = 0, int y = 0);
    ~Coordinate();
    void printCoordinate();
private:
    int m_iX;
    int m_iY;
};

