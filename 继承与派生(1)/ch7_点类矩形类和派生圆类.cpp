/*设计点类（Point），派生圆类（Circle）和矩形类（Rectangle）。如下图：
		（点类派生出圆类和矩形类）

	点类中：私有数据成员int x 和 int y ，分别表示横坐标和纵坐标；
 			构造函数Point()，将x和y都初始化为0 ；
			构造函数Point(int xx,int yy)，将x和y分别初始化为xx和yy的值 ；
			析构函数~Point() ；
移动函数void Move(int xOff,int yOff)， 将x沿横轴移动xOff个位置，将y沿纵轴移动yOff个位置 ；
写数据函数void Set(int xx,int yy)，将x和y分别赋值为xx和yy的值 ；
输出函数void Display()， 以形式“Point(x,y)”输出点的信息 ；
矩形类公有继承点类：
		增加了：
		私有数据成员int w 和int h ，表示宽和高 ；
构造函数Rectangle()，将宽和高都初始化为0	 ；（思考：将左下角顶点初始化为了哪个点？如何实现的）
构造函数Rectangle(int xx,int yy,int ww,int hh)，将左下角顶点初始化为Point(xx,yy)，将宽初始化为ww，将高初始化为hh ;
析构函数~Rectangle () ；
写数据函数void Set(int xx,int yy,int ww,int hh)，将x和y分别赋值为xx和yy的值，将w和h分别赋值为ww和hh的值 ；
面积函数float Area()， 计算并返回矩形的面积 ；
周长函数float Circum()， 计算并返回矩形的周长 ；
输出函数void Display()， 以形式“Rectangle((x,y),w,h)，面积，周长”输出矩形的信息 ；
圆类公有继承点类：
		增加了：
		私有数据成员int r ，表示半径 ；
构造函数Circle()，将半径初始化为0	 ；（思考：将圆心初始化为了哪个点？如何实现的）
构造函数Circle(int xx,int yy,int rr)，将圆心初始化为Pint(xx,yy)，将半径初始化为rr ;
析构函数~Point() ；
写数据函数void Set(int xx,int yy,int rr)，将x和y分别赋值为xx和yy的值，将r赋值为rr的值 ；
面积函数float Area()， 计算并返回圆的面积 ；
周长函数float Circum()， 计算并返回圆的周长 ；
输出函数void Display()， 以形式“Circle((x,y),r)，面积，周长”输出点的信息 ；

main()函数中：
创建矩形R1： 左下角顶点（2，2），宽3，高4；输出其所有的信息：左下角顶点、宽、高、面积、周长 ;
将R1向右移动3个单位，向上移动4个单位， 再次输出其所有的信息；
创建圆C1：圆心（1，2），半径3；输出其所有的信息：圆心、半径、面积、周长 ;
           将C1向右移动3个单位，向上移动4个单位， 再次输出其所有的信息；
创建圆的数组C2[3]， 将三个圆分别设置为：圆心(0,0),半径1；圆心(1,1),半径2；圆心(5,5),半径5；输出这3个圆的信息 。
*/
#include <iostream>
#include <iomanip>
using namespace std;
#define PI 3.1415926
class Point
{
private:
	int x,y; // 横坐标x和纵坐标y
public:
	Point(){x = 0; y = 0;} // 默认初始化x和y为0
	Point(int xx,int yy){x = xx;y = yy;}
	~Point(){};
	void Move(int xOff,int yOff){ x += xOff; y += yOff; } // 移动函数
	void Set(int xx, int yy){x = xx; y = yy; } // 写数据函数
	void Display(){ cout << "Point(" << x << "," << y << ")" << endl; } // 输出函数
    void GetPoint(){ cout << "(" << x << "," << y << ")";}
};
class Rectangle: public Point
{
private:
	int w,h; // 宽和高
public:
	Rectangle(){ w = 0; h = 0; }
	Rectangle(int xx,int yy,int ww,int hh){ Point(xx,yy); w = ww; h = hh; }
	~Rectangle(){};
	void Set(int xx, int yy, int ww, int hh){ Point::Set(xx,yy); w = ww; h = hh; }
	float Area(){ return w*h; }
	float Circum(){ return 2*(w+h); }
	void Display(){ cout << "Rectangle("; Point::GetPoint(); cout << "," << w << "," << h << ")," << setprecision(3) << Area() << "," << setprecision(3) << Circum() << endl; }
};
class Circle:public Point
{
private:
	int r;
public:
	Circle(){ r = 0; }
	Circle(int xx, int yy, int rr){ Point(xx,yy); r = rr; }
	~Circle(){};
	void Set(int xx, int yy, int rr){  Point::Set(xx,yy); r = rr; }
	float Area(){ return PI*r*r; }
	float Circum(){ return 2*PI*r; }
	void Display(){cout << "Circle("; Point::GetPoint(); cout << "," << r << ")," << setprecision(3) << Area() << "," << setprecision(3) << Circum() << endl; }
};
int main(){
	Rectangle R1(2,2,3,4);
	R1.Display();
	R1.Move(3,4);
	R1.Display();

	Circle C1(1,2,3);
	C1.Display();
	C1.Move(3,4);
	C1.Display();

	Circle C2[3];
	C2[0].Set(0,0,1);
	C2[1].Set(1,1,2);
	C2[2].Set(5,5,5);
	for(int i=0; i<2 ; i++){
		C2[i].Display();
	}
}
