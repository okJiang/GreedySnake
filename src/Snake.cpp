#include <conio.h>
#include <iostream>
#include "Snake.h"
#include <cstring>
#include "map.h"
#include "stdlib.h"

int SNAKE[50][50];  //���ڼ�¼�ߵ�λ�ã�������ʳ���ʱ��Ҫ���ɵ��ߵ�����
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

//��ʼ���ߵ�ͼ��
void Snake::InitSnake()
{
    for(auto point : snake)
        point.Print("��");
}

void Snake::move(food* &f)
{

    Point head = snake.front();
    head.ChangePosition(head.getx() + m[direction][0], head.gety() + m[direction][1]);

    // ��ײ��ǽ�����
    // std::cout << '\t' << head.getx() << ' ' << head.gety() << std::endl;
    if(map1.getborder().find(head) == map1.getborder().end()) {
        system("cls");
        std::cout << "GAME OVER";
        exit(10);

    }

    snake.push_front(head);
    SNAKE[head.getx()][head.gety()] = 1;
    // �Ե�ʳ�ͷ��һ����������ʳ��
    if(head == f->getp()){
        delete f;
        f = new food();
        head.Print("��");
    }
    // û�Ե�ʳ�ͷ��һ��β�ͼ�һ
    else {
        head.Print("��");
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
    return false;
}


Snake::~Snake()
{
    //dtor
}
