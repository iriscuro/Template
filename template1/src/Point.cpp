#include <iostream>
#include "Point.h"

template <class I>

Point<I>::Point(I xh, I yh){
    x = xh;
    y = yh;
}
template <class I>
Point<I>::Point(){
    x = 0;
    y = 0;
}
template <class I>
Point<I>::Point(Point &o){
    x = o.x;
    y = o.y;
}
template <class I>
void Point<I>::print(){
    std::cout << "(" << x << ", " << y << ")" << std::endl;
}
template <class D>
void Point<D>::offset(D nx, D ny){
    x += nx;
    y += ny;
}
template <class D>

D Point<D>::getX(){
    return x;
}
template <class D>

D Point<D>::getY(){
    return y;
}
template <class I>
void Point<I>::setX(I x){
    this->x = x;
}
template <class I>
void Point<I>::setY(I y){
    this->y = y;
}
