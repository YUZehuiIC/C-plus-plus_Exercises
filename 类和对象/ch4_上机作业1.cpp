// 1.定义并实现一个矩形类Rect，
// 有length（长）、width（宽）两个属性，
// 由成员函数Set(int l, int w)置矩形的长和宽，
// 成员函数Area()计算矩形的面积。
// 在main函数中创建一个矩形对象，输入其长、宽的数值，
// 输出其面积。
#include<iostream>
using namespace std;
class Rect{
	private:
		double length,width;
	public:
		void Set(int l,int w){ length = l;width = w; }
		double Area(){ return length*width; }
};
int main(){
	Rect r;
	double length,width;
	cout << "请输入矩形的长：";
	cin >> length;
	cout << "请输入矩形的宽：";
	cin >> width;
	r.Set(length,width);
	cout << "矩形的面积是：" << r.Area();
}
