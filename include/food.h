#ifndef FOOD_H
#define FOOD_H
#include "Point.h"

class food
{
    public:
        food();
        //void Clear();
        //void Print(std::string s);
        Point getp();
        ~food();

    protected:

    private:
        Point p;

};

#endif // FOOD_H
