#include <iostream>
#include <math.h>
#include "Triangle.h"
using namespace std;
void Triangle::Show(){
	cout << "三角形";
}
double Triangle::Area(){
	double p = Perimeter()/2;
	double a,b,c;
	a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
double Triangle::Perimeter(){
	double a,b,c;
	a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	b = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
	c = sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
	return a+b+c;
}
