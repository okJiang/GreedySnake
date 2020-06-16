#include <conio.h>
#include <iostream>
#include "Snake.h"

Snake::Snake()
{
    snake.push_front(Point(3, 3));
    snake.push_front(Point(3, 4));
    snake.push_front(Point(3, 5));
    direction = Direction::RIGHT;
}

//初始化蛇的图案
void Snake::InitSnake()
{
    for(auto point : snake)
        point.Print("●");
}

void Snake::move()
{
    Point head = snake.front();
    head.ChangePosition(head.getx() + m[direction][0], head.gety() + m[direction][1]);
    snake.push_front(head);
    head.Print("●");
    snake.back().Clear();
    snake.pop_back();

}

bool Snake::ChangeDirection()
{
    char c;
    if(kbhit()){
        c = getch();
        switch(c){
        case -32:{
            //键盘上的上下左右输入进来有两个字节，第一个字节的十进制表示为-32
            c = getch();
            switch(c){
            case 72:
                if(direction != Direction::DOWN)
                    direction = Direction::UP;
                break;
            case 80:
                if(direction != Direction::UP)
                    direction = Direction::DOWN;
                break;
            case 75:
                if(direction != Direction::RIGHT)
                    direction = Direction::LEFT;
                break;
            case 77:
                if(direction != Direction::LEFT)
                    direction = Direction::RIGHT;
                break;
            default:
                break;
            }
            return true;
        }
        case 27:    //ESC的键值
            return false;
        default:
            return true;
        }
    }
}


Snake::~Snake()
{
    //dtor
}
