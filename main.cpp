#include <iostream>
#include "Point.h"
#include "ArrPoint.h"

using namespace std;
template <class I>

 class Point
{
    public:
        Point();
        Point(int xh, int yh);
        Point(Point &o);

        void offset(I, I);
        void print();
        I getX();
        I getY();
        void setX(I x);
        void setY(I y);

    private:
        I x, y;
};

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

template <class I>

Point<I>::Point(int xh, int yh){
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
template <class I>
void Point<I>::offset(I nx, I ny){
    x += nx;
    y += ny;
}
template <class I>

I Point<I>::getX(){
    return x;
}
template <class I>

I Point<I>::getY(){
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
int main()
{
    Point<int> p( 1, 3);
    Point<int> q(4 , 8);
    Point<int> r(7 , 2);
    Point<int> s(4 ,5);
    Point<int> arr[] = {p, q , r};
    int size = sizeof(arr)/sizeof(arr[0]);

    ArrPoint<int> pa2(arr, size);

    ArrPoint<int> pa = pa2;

    pa.getSize();
    //cout << pa.getSize() << endl;
    pa.push_back(p);
    cout<< "pa"<<endl;
    pa.print();
    cout<<endl;

    pa.insert(1, q);
    pa.print();
    pa.clear();
    cout << pa.getSize() << "\n "<<endl;

    cout<< " pa2 "<<endl<<endl;
    pa2.print();
    cout <<endl;
    //PointArray pa=pa2;
    pa2.push_back(p);
    cout<<"pa2 :"<<endl<<endl;
    pa2.print();
    //pa.print();
    cout <<"\n";
    cout <<pa.getSize()<<endl;
    pa2.insert(4,s);
    cout <<"pa2 ;"<<endl<<endl;
    pa2.print();


    return 0;
}
