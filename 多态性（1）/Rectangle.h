#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Shape.h"
class Rectangle:public Shape
{
private:
	int x1,y1,x2,y2;
public:
	Rectangle(int a,int b,int c,int d){x1 = a; y1 = b; x2 = c; y2 = d;}
	virtual~ Rectangle(){}
	virtual void Show();
	virtual double Area();
	virtual double Perimeter();

};

#endif