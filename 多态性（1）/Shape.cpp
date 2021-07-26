#include <iostream>
#include <iomanip>
#include "Shape.h"
using namespace std;
void Shape::GetInfo()
{
	cout << "这是一个";
	Show();
	cout << endl << "它的面积是" << setprecision(2) << Area();
	cout << endl << "它的周长是" << setprecision(2) << Perimeter() << endl;
}
