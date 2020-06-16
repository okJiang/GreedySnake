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

int Point::getx()
{
    return x;
}

int Point::gety()
{
    return y;
}

void Point::Print(std::string s)
{
    SetCursorPosition(x, y);
    std::cout << s;
}

void Point::Clear()
{
    SetCursorPosition(x, y);
    std::cout << "  ";
}
