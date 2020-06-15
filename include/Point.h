#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point(int x, int y);

        int getx();
        int gety();
        void Print(char c);


    protected:

    private:
        int x, y;

};

#endif // POINT_H
