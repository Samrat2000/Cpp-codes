#include <iostream>
using namespace std;

// Given shape class
class Shape {
public:
	virtual ~Shape();
	virtual void draw()=0;
};

// Given Circle Class
class Circle : public Shape {
public:
	virtual ~Circle();
	virtual void draw();
};

// Ellipse class added
class Ellipse : public Shape {
public:
	virtual ~Ellipse();
	virtual void draw();
};

// Destructor of Shape class
Shape::~Shape() {
	cout<<"shape destructor"<<endl;
}

//void Shape::draw() {
//	cout<<" Shape::draw"<<endl;
//}

// Destructor and draw function of circle class
Circle::~Circle() {
	cout<<" circle destructor "<<endl; 
}

void Circle::draw() {
	cout<<" Circle::draw "<<endl;
}

// Destructor and draw function of ellipse class
Ellipse::~Ellipse() {
	cout<<" Ellipse destructor "<<endl; 
}

void Ellipse::draw() {
	cout<<" Ellipse::draw "<<endl;
}

// main function
int main() {
	// 3 heap allocated circle objects
	Shape *shape[] = {new Circle,new Circle,new Circle};
	for(int  i=0;i<(sizeof(shape)/sizeof(Shape*));i++)
      {
        cout<<"Shape "<<i+1<<" : ";
		shape[i]->draw();
      }
      
      // 3 stack allocated circle objects
      Ellipse e1,e2,e3;
      e1.draw();
      e2.draw();
      e3.draw();

	return 0;
}

