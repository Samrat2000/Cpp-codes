#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

// abstract base class
class Shape
{
	public:
		virtual ~Shape(){}
		virtual void area() = 0;
};

// derived class level 1
class ClosedConics : public Shape 
{
	public:
		virtual ~ClosedConics(){}
		virtual void area(){
		}
};

//derived class level1
class Polygon : public Shape 
{
	public:
		virtual ~Polygon(){}
		virtual void area(){
		}
};

// derived class level 2
class Circle : public ClosedConics 
{
	public:
		int cx,cy, r;
		Circle( int a, int b, int rad): cx(a), cy(b), r(rad){}
		virtual ~Circle(){}
		// area function defined as required
		virtual void area()
		{
			cout << "Area of circle: " << (3.14*r*r) << endl;
		}
};

// derived class level 2
class Ellipse : public ClosedConics  
{
	public:
		int f1x,f1y,f2x,f2y,a,b;
		Ellipse( int x1, int y1, int x2, int y2, int maj, int min): 
								f1x(x1), f1y(y1), f2x(x2), f2y(y2), a(maj), b(min){}
		virtual ~Ellipse(){}
		// area function defined as required
		virtual void area()
		{
			cout << "Area of Ellipse: " << (3.14*a*b) << endl;
		}
};

// derived class level 2
class Triangle : public Polygon  
{
	public:
		int ax,ay,bx,by,cx,cy;
		Triangle( int x1, int y1, int x2, int y2, int x3, int y3): 
								ax(x1), ay(y1), bx(x2), by(y2), cx(x3), cy(y3){}
		virtual ~Triangle(){}
		// area function defined as required
		virtual void area()
		{
			cout << "Area of Triangle: " << abs(ax*(by-cy)+bx*(cy-ay)+cx*(ay-by))/2.0 << endl;
		}
};

// derived class level 2
class Quadrilateral : public Polygon   // only rectangle
{
	public:
		int ax,ay,bx,by,cx,cy,dx,dy;
		Quadrilateral( int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4): 
								ax(x1), ay(y1), bx(x2), by(y2), cx(x3), cy(y3), dx(x4), dy(y4){}
		virtual ~Quadrilateral(){}
		// area function defined as required
		virtual void area()
		{
			cout << "Area of Rectangle: " << (sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by)))*(sqrt((cx-bx)*(cx-bx)+(cy-by)*(cy-by)))<< endl;
		}
};

int  main(void)
{  

	// Allocated from heap
    Shape *arr[] = {new Circle(2,3,5), new Circle(5,7,3), new Ellipse(1,2,1,4,3,2), new Ellipse(1,2,1,5,4,3),
		new Triangle(1,1,2,2,3,4), new Triangle(1,0,0,2,5,4),  new Quadrilateral(0,0,0,3,3,3,3,0), new Quadrilateral(0,0,0,5,5,5,5,0)}; 
  
  
    for(int  i=0;i<(sizeof(arr)/sizeof(Shape*));i++)
      {
        cout<<"Shape "<<i+1<<" : ";
		arr[i]->area();
      }
}

