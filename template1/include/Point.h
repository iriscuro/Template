#ifndef POINT_H
#define POINT_H

template <class I>

class Point
{
    public:
        Point();
        Point(I, I);
        Point(Point &o);

        void offset(I, I);
        void print();
        I getX();
        I getY();
        void setX(I x);
        void setY(I y);

    private:
        double x, y;
};

#endif // POINT_H
