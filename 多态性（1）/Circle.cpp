#include <iostream>
#include <math.h>
#include "Circle.h"
using namespace std;
void Circle::Show(){
	cout << "圆";
}
double Circle::Area(){
	return PI*r*r;
}
double Circle::Perimeter(){
	return 2*PI*r;
}