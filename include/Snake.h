#ifndef SNAKE_H
#define SNAKE_H
#include <deque>
#include "Point.h"

class Snake
{
    public:
        enum Direction{UP, DOWN, LEFT, RIGHT};
        int m[4][2] = {{0,-1}, {0,1}, {-1, 0}, {1, 0}};

        Snake();

        void InitSnake();
        void move();
        bool ChangeDirection();

        virtual ~Snake();

    protected:

    private:
        std::deque<Point> snake;
        Direction direction;
};

#endif // SNAKE_H
