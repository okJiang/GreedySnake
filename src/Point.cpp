#include <iostream>
#include "tools.h"

#include "Point.h"

Point::Point(int x, int y)
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

void Point::Print(char c)
{
    SetCursorPosition(x, y);
    std::cout << c;
}

