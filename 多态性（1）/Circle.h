#ifndef CIRCLE_H
#define CIRCLE_H
#define PI 3.1415926
#include "Shape.h"
class Circle:public Shape
{
private:
	int x,y,r;
public:
	Circle(int a,int b,int c){x = a;y = b;r = c;}
	virtual~ Circle(){}
	virtual void Show();
	virtual double Area();
	virtual double Perimeter();

};

#endif