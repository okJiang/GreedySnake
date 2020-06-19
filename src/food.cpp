#include "food.h"
#include "tools.h"
#include <cstdlib>
#include <iostream>

extern int SNAKE[50][50];       //用于记录蛇的位置，在生成食物的时候不要生成到蛇的身上

food::food():p(2 + rand()%28, 2 + rand()%28)
{
    // 如果食物生成到蛇身上的时候，重新设置食物的坐标
    while(SNAKE[p.getx()][p.gety()] == 1)
        p.ChangePosition(2 + rand()%28, 2 + rand()%28);
    p.Print("★");
}

food::~food()
{
    p.Clear();
}

Point food::getp()
{
    return p;
}
