#ifndef POINT_H
#define POINT_H
#include <string>


class Point
{
    public:
        Point();
        Point(int x, int y);

        void Clear();
        int getx();
        int gety();
        void ChangePosition(const int x, const int y);
        void Print(std::string s);


    protected:

    private:
        int x, y;

};

#endif // POINT_H
