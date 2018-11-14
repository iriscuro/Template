#ifndef POINTARRAY_H
#define POINTARRAY_H

#include "Point.h"

template <class R >

class ArrPoint
{
    public:
        ArrPoint();
        ArrPoint(const Point<int> pts[], const int size);
        ArrPoint(ArrPoint &o);
        ~ArrPoint();//destructor

        void print();
        int getSize();
        void clear();
        void push_back(const Point<int> &p);
        void insert(const R, const Point<int> &p);
        void remove(const R);

    private:
        R size;//size  debe ser entero
        Point<int> *points;
        void resize(R newSize);//newSize debe ser entero
};

#endif // POINTARRAY_H
