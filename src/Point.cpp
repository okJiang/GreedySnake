#include <iostream>
#include "tools.h"

#include "Point.h"



Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

void Point::ChangePosition(const int x, const int y)
{
    this->x = x;
    this->y = y;
}

int Point::getx() const
{
    return x;
}

int Point::gety() const
{
    return y;
}

void Point::Print(std::string s) const
{
    //std::cout << "\t\t" << x << ' ' << y << std::endl;
    SetCursorPosition(x, y);
    std::cout << s;
}

void Point::Clear() const
{
    //std::cout << "\t\t" << x << ' ' << y << std::endl;
    SetCursorPosition(x, y);

    std::cout << "  ";
}

bool Point::operator==(const Point& p) const
{
    return (p.getx() == x)&&(p.gety() == y);
}

// 因为set容器中需要用到运算符<，但是库中没有Point的<，所以这里要重载一个
bool Point::operator<(const Point& p) const
{
    if(x < p.getx()) return true;
    else if(x == p.getx())
        if(y < p.gety()) return true;
        else return false;
    else return false;
}

Point::Point()
{

}

Point::~Point()
{

}
