#include "food.h"
#include "tools.h"
#include <cstdlib>
#include <iostream>

extern int SNAKE[50][50];       //���ڼ�¼�ߵ�λ�ã�������ʳ���ʱ��Ҫ���ɵ��ߵ�����

food::food():p(2 + rand()%28, 2 + rand()%28)
{
    // ���ʳ�����ɵ������ϵ�ʱ����������ʳ�������
    while(SNAKE[p.getx()][p.gety()] == 1)
        p.ChangePosition(2 + rand()%28, 2 + rand()%28);
    p.Print("��");
}

food::~food()
{
    p.Clear();
}

Point food::getp()
{
    return p;
}
