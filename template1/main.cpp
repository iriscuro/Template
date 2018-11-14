#include <iostream>
#include "Point.h"
#include "ArrPoint.h"

using namespace std;

int main()
{


    Point <int>p( 1, 3);
    Point <int>q(4, 8);
    Point <int>r(7, 2);
    Point <int>s(4,5);
    Point <int>arr[] = {p, q , r};
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
