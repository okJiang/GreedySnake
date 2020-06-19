#include "map.h"

map::map()
{
    for(int i = 0; i < 116; i ++)
        border.insert(Point(Border[i][0], Border[i][1]));
}

map::~map()
{
    for(auto& p: border)
        p.Clear();
}

void map::show() const
{
    for(auto& p: border)
        p.Print("¡ö");
}

std::set<Point> map::getborder() const
{
    return border;
}
