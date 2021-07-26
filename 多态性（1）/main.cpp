#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
using namespace std;
int main()
{
	int shape_num,a1,a2,a3,a4,a5,a6,r;
	char judge;

	cout << "你打算建立几个形状：";
	cin >> shape_num;
	 Shape *X[shape_num];
	for(int i=0;i<shape_num;i++){
		cout << "请输入形状" << i+1 << "（C--圆、R--矩形、T--三角形）：";
		cin >> judge;

		if(judge == 'C'){
			cout << "请输入圆心的坐标与半径：";
			cin >> a1 >> a2 >> r;
			X[i] = new Circle(a1,a2,r);
			cout << "圆已经建立" << endl;
		}
		else if(judge == 'R'){
			cout << "请输入矩形对角的两个顶点的坐标：";
			cin >> a1 >> a2 >> a3 >> a4;
			X[i] = new Rectangle(a1,a2,a3,a4);
			cout << "矩形已经建立" << endl;
		}
		else if(judge == 'T'){
			cout << "请输入三角形三个顶点的坐标：";
			cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
			X[i] = new Triangle(a1,a2,a3,a4,a5,a6);
			cout << "三角形已经建立" << endl;
		}
	}
	cout << "下面是" << shape_num << "个形状的信息：" << endl;
	for(int i=0;i<shape_num;i++){
		cout << "形状" << i+1 << ":";
		X[i] -> GetInfo();
        delete X[i];
	}

}
