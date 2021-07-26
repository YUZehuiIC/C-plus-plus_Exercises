#include <iostream>
#include <math.h>
#include "Rectangle.h"
using namespace std;
void Rectangle::Show(){
	cout << "矩形";
}
double Rectangle::Area(){
	return fabs((x1-x2)*(y1-y2));
}
double Rectangle::Perimeter(){
	return 2*(fabs(x1-x2)+fabs(y1-y2));
}