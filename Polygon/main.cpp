#include <iostream>
using namespace std;
template <class Y>
class Polygon {
  protected:
    Y width, height;
  public:
    Polygon (Y a, Y b) : width(a), height(b) {}
    virtual Y area (void) =0;
    void printarea()
      { cout << this->area() << '\n'; }
};

template <class M>
class Rectangle: public Polygon<int>
 {
  public:
    Rectangle(M a,M b) : Polygon(a,b) {}
    M area()
      { return width*height; }
};
template <class S>
class Triangle: public Polygon<float> {
  public:
    Triangle(S a,S b) : Polygon(a,b) {}
    S area()
      {
          return width*height/2;
      }
};

int main () {

  Polygon<int> *rect1= new Rectangle<int>(4,5);
  Polygon<float> *tria2 = new Triangle<float>(4,5);
  cout << "Ela area del rectangulo es: "<<endl;
  rect1->printarea();
  cout << "Ela area del triangulo es: " <<endl;
  tria2->printarea();
  delete rect1;
  delete tria2;
  return 0;
}
