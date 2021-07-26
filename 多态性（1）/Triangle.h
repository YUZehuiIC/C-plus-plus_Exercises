#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
class Triangle:public Shape
{
private:
	int x1,y1,x2,y2,x3,y3;
public:
	Triangle(int a1,int b1,int a2,int b2,int a3,int b3){x1 = a1;y1 = b1;x2 = a2;y2 = b2;x3 = a3;y3 = b3;}
	virtual~ Triangle(){}
	virtual void Show();
	virtual double Area();
	virtual double Perimeter();

};

#endif