#include <conio.h>
#include <iostream>
#include "Snake.h"
#include <cstring>
#include "map.h"
#include "stdlib.h"

int SNAKE[50][50];  //用于记录蛇的位置，在生成食物的时候不要生成到蛇的身上
extern map map1;

Snake::Snake()
{
    snake.push_front(Point(3, 3));
    snake.push_front(Point(3, 4));
    snake.push_front(Point(3, 5));
    std::memset(SNAKE, 0, sizeof(SNAKE));
    for(auto p: snake){

        SNAKE[p.getx()][p.gety()] = 1;
    }
    direction = Direction::RIGHT;
}

//初始化蛇的图案
void Snake::InitSnake()
{
    for(auto point : snake)
        point.Print("●");
}

void Snake::move(food* &f)
{

    Point head = snake.front();
    head.ChangePosition(head.getx() + m[direction][0], head.gety() + m[direction][1]);

    // 蛇撞到墙的情况
    // std::cout << '\t' << head.getx() << ' ' << head.gety() << std::endl;
    if(map1.getborder().find(head) == map1.getborder().end()) {
        system("cls");
        std::cout << "GAME OVER";
        exit(10);

    }

    snake.push_front(head);
    SNAKE[head.getx()][head.gety()] = 1;
    // 吃到食物，头加一，重新生成食物
    if(head == f->getp()){
        delete f;
        f = new food();
        head.Print("●");
    }
    // 没吃到食物，头加一，尾巴减一
    else {
        head.Print("●");
        SNAKE[snake.back().getx()][snake.back().gety()] = 0;
        snake.back().Clear();
        snake.pop_back();

    }
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
    return false;
}


Snake::~Snake()
{
    //dtor
}
