// 5.编写数值交换函数Swap，在同一个程序中针对整数，浮点数，字符串实现多个重载的函数。
// 在主程序中调用Swap函数实现输入/输出，
// 分别输入两个整数，输出交换后的结果；
// 输入两个小数，输出交换后的结果;
// 输入两个字符串，输出交换后的结果。
#include<iostream>
#include<string>
using namespace std;
void swap(int& a,int& b);
void swap(double& a,double& b);
void swap(string& a,string& b);
int main(){
	int int_x,int_y;
	double dou_x,dou_y;
	string str_x,str_y;

	cout << "请输入要交换的两个整数：";
	cin >> int_x >> int_y;
	swap(int_x,int_y);
	cout << "交换后的结果为：" << int_x << " " << int_y << endl;

	cout << "请输入要交换的两个浮点数：";
	cin >> dou_x >> dou_y;
	swap(dou_x,dou_y);
	cout << "交换后的结果为：" << dou_x << " " << dou_y<< endl;

	cout << "请输入要交换的两个字符串：";
	cin >> str_x >> str_y;
	swap(str_x,str_y);
	cout << "交换后的结果为：" << str_x << " " << str_y<< endl;

}
void swap(int& a,int& b){
	int t;
	t = a;
	a = b;
	b = t;
}
void swap(double& a,double& b){
	double t;
	t = a;
	a = b;
	b = t;
}
void swap(string& a,string& b){
	string t;
	t = a;
	a = b;
	b = t;
}

// 学习小结：
// 1. 接收多个输入值：cin >> a >> b;
// 2. 重载函数的定义一定要分别定义。
