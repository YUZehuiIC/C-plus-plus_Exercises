// 1.定义、实现并测试Number类。
// 定义类的私有数据成员n1和n2为两个数字。
// 定义缺省形参值（0）的有参构造函数，赋予n1和n2初始值。
// 定义加addition、减subtration、乘multiplication、除division等
// 公有成员函数分别对两个成员变量执行加、减、乘、除的运算。
// 在主程序中创建Number类的对象调用各个方法并显示计算结果。
#include <iostream>
#include <iomanip>
using namespace std;
class Number{
	private:
		double n1,n2;
	public:
		Number(double a=0,double b=0){n1 = a; n2 = b;}
		double addition(){return n1+n2;}
		double subtration(){return n1-n2;}
		double multiplication(){return n1*n2;}
		double division(){return n1/n2;}
};
int main(){
    double x,y;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
	Number mynumber(x,y);
	cout << "addtion:" << mynumber.addition() << endl;
	cout << "subtration:" << mynumber.subtration() << endl;
	cout << "multiplication:" << mynumber.multiplication() << endl;
	cout << "division:" << mynumber.division() << endl;
	return 0;
}
