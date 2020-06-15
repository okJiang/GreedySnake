#include <windows.h>
#include <stdio.h>
#include "tools.h"

void SetWindowsSize(int cols, int lines)
{
    system("title GreedySnake");
    char cmd[30];
    sprintf(cmd, "mode con cols = %d, lines = %d", cols*2, lines);
    system(cmd);
}

void SetCursorPosition(const int x, const int y)
{
    COORD position;
    position.X = x*2;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}
