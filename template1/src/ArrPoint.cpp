#include "ArrPoint.h"
template <class R >

ArrPoint<R>::ArrPoint()
{
    this->size = 0;
    this->points = new Point<int>[size];
}
template <class R>
ArrPoint<R>::ArrPoint(const Point<int> pts[], const int size) {
    this->size = size;
    this->points = new Point<int>[size];
    for(int i = 0; i < size; i++)
        points[i] = pts[i];
}
template <class R>
ArrPoint<R>::ArrPoint(ArrPoint &o){
    this->size = o.size;
    this->points = new Point<int>[size];
    for(int i = 0; i < size; i++)
        points[i] = o.points[i];
}
template <class R>
void ArrPoint<R>::resize(R newSize) {//cambiar el tamañode arreglo
	Point<int> *pts = new Point<int>[newSize];
	int minsize = (newSize > size) ? size : newSize;
    for(int i = 0; i < minsize; i++)
        pts[i] = points[i];
	delete[] points;
	size = newSize;
	points = pts;
}

template <class R>
void ArrPoint<R>::print() {
	for(int i = 0; i < size; i++)
		points[i].print();
}

template <class R>
void ArrPoint<R>::push_back(const Point<int> &p){
	resize(size+1);
	points[size-1] = p;
}
template <class R>
void ArrPoint<R>::insert(const R pos, const Point<int> &p) {
	resize(size+1);
    for(int i = size-1; i < pos; i--)
        points[i] = points[i-1];
	points[pos] = p;
}
template <class R >
void ArrPoint<R>::remove(const R pos) {

}
template <class R>
void ArrPoint<R>::clear() {
	resize(0);
}
template <class R>
int ArrPoint<R>::getSize(){
    return size;
}
template <class R>
ArrPoint<R>::~ArrPoint()
{
    delete[] points;
}
