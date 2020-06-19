#ifndef POINT_H
#define POINT_H
#include <string>


class Point
{
    public:
        Point();
        Point(int x, int y);

        void Clear() const;
        int getx() const;
        int gety() const;
        void ChangePosition(const int x, const int y);
        void Print(std::string s) const;
        bool operator==(const Point& p) const;
        bool operator<(const Point& p) const;
        virtual ~Point();

    protected:

    private:
        int x, y;

};

#endif // POINT_H
