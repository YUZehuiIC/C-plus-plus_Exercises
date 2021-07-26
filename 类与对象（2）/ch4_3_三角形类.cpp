// 3.定义、实现并测试一个三角形类。
// 定义三角形类的私有数据成员a、b、c三个数代表边长。
// 定义下列成员函数：
// （a）定义缺省形参值（1，1，1）的有参构造函数，赋予a、b、c初始值。.
// （b）对成员变量赋值函数
// （c）判断三角形是否满足三角形定义（任意两边之和大于第三边）；
// （d）判断三角形是等腰三角形；
// （e）判断三角形是否为等边三角形；
// （f）判断三角形是否为直角三角形；
// （g）判断三角形是否为等腰直角三角形；
// （h）判断三角形属于前面哪类三角形；
// （i）计算三角形的周长；
// （j）计算三角形的面积。
// 编写主程序：
// 	用户输入三角形三边长，输出三角形是否为正确的三角形，
// 	如果是接着输出三角形是哪种类型的三角形，接着输出三角形的周长和面积。
#include <iostream>
#include <math.h>
using namespace std;
class triangle{
private:
	double a,b,c;
public:
	triangle(double x=1,double y=1,double z=1){a = x;b = y;c = z;}
	void setA(int n){a = n;}
	void setB(int n){b = n;}
	void setC(int n){c = n;}
	int triangle_judge(); // 三角形定义判断
	int dengyao_triangle_judge(); // 等腰三角形判断
	int dengbian_triangle_judge(); // 等边三角形判断
	int zhijiao_triangle_judge(); // 直角三角形判断
	int dengyaozhijiao_judge(); // 等腰直角三角形判断
	int kind_judge(); // 判断是前面哪类三角形
	double sum(){return a+b+c;}
	double area();
};
int triangle::triangle_judge(){
	if(a+b>c && b+c>a && a+c>b)
		return 1;
	else
		return 0;
}
int triangle::dengyao_triangle_judge(){
	if(a==b || b==c || a==c)
		return 1;
	else
		return 0;
}
int triangle::dengbian_triangle_judge(){
	if(a==b && b==c)
		return 1;
	else
		return 0;
}
int triangle::zhijiao_triangle_judge(){
	if(a*a+b*b==c*c || b*b+c*c==a*a || a*a+c*c==b*b)
		return 1;
	else
		return 0;
}
int triangle::dengyaozhijiao_judge(){
	if(dengyao_triangle_judge()==1 && zhijiao_triangle_judge()==1)
		return 1;
	else
		return 0;
}
int triangle::kind_judge(){
	if(dengyao_triangle_judge()==1)
	{
		if(dengyaozhijiao_judge()==1)
			cout << "这个三角形是等腰直角三角形。" << endl;
		else if(dengbian_triangle_judge()==1)
			cout << "这个三角形是等边三角形。" << endl;
		else
			cout << "这个三角形是等腰三角形。" << endl;
	}
	else if(zhijiao_triangle_judge()==1)
		cout << "这个三角形是直角三角形。" << endl;
}
double triangle::area(){
	double p;
	p = sum()/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}
int main(){
	double a,b,c;
	cout << "a = ";
	cin >> a;
	cout << "b = ";
	cin >> b;
	cout << "c = ";
	cin >> c;
	triangle my_triangle(a,b,c);
	if(my_triangle.triangle_judge()==1){
		cout << "三角形正确！" << endl;
		my_triangle.kind_judge();
		cout << "三角形的周长是 " << my_triangle.sum() << endl;
		cout << "三角形的面积是 " << my_triangle.area() << endl;
	}
	else
		cout << "三角形错误！" << endl;
}


// 代码反思：
// 1. 构造函数不能有返回类型，void也不行
