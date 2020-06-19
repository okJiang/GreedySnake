#include <iostream>
#include <windows.h>
#include "Snake.h"
#include "tools.h"
#include "food.h"
#include "map.h"

using namespace std;

map map1;

int main()
{
    SetWindowsSize(40, 40);

    map1.show();

    Snake s;
    food *f = new food();
    while(1){

        Sleep(500);
        s.ChangeDirection();
        s.move(f);
    }
    return 0;
}
