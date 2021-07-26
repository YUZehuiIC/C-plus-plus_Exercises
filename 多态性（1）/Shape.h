#ifndef SHAPE_H
#define SHAPE_H
class Shape
{
public:
	Shape(){}
	virtual~ Shape(){}
	void GetInfo();
	virtual void Show() = 0;
	virtual double Area() = 0;
	virtual double Perimeter() = 0;
};
#endif
