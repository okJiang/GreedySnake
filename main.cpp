#include <iostream>
#include "Point.h"

using namespace std;

int main()
{
    Point *p = new Point(1, 2);
    p->Print('2');
    return 0;
}
