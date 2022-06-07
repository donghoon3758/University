/*
Remove the virtual keyword from each location individually, recompiling and
running each time to see how the output changes.
*/

#include <iostream>

using namespace std;
class Shape {
public:
	virtual ~Shape();
	virtual void draw() = 0;
};

class Circle : public Shape {
public:
	 virtual ~Circle();
	 virtual void draw();
};

Shape::~Shape() {
	cout << "shape destructor" << endl;
}

Circle::~Circle() {
	cout << "circle destructor" << endl;
}

void Circle::draw() {
	cout << "Circle::draw" << endl;
}

int main() {
	//Shape* shape = new Circle;
	//shape->draw();
	//delete shape;
	Circle  circle;
	circle.draw();

	return 0;
}