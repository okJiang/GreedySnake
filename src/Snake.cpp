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

//��ʼ���ߵ�ͼ��
void Snake::InitSnake()
{
    for(auto point : snake)
        point.Print("��");
}

void Snake::move()
{
    Point head = snake.front();
    head.ChangePosition(head.getx() + m[direction][0], head.gety() + m[direction][1]);
    snake.push_front(head);
    head.Print("��");
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
            //�����ϵ�����������������������ֽڣ���һ���ֽڵ�ʮ���Ʊ�ʾΪ-32
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
        case 27:    //ESC�ļ�ֵ
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
