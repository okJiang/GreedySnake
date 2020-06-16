#include <iostream>
#include <windows.h>
#include "Snake.h"
#include "tools.h"

using namespace std;

int main()
{
    SetWindowsSize(20, 20);
    Snake s;
    while(1){
        Sleep(1000);
        s.ChangeDiretion();
        s.move();
    }
    return 0;
}
