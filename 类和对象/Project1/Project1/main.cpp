#include <graphics.h> // 就是需要引用这个图形库
#include <conio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
// 为解决编译错误，故添加以下命令
#include <stdio.h> 
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };

#define PI 3.141592653

void clock_background()
{
	// 画表盘的大圆圈，并在表盘上面标明时间
	circle(400, 400, 200); // 三个参数分别是：圆心坐标x，圆心坐标y，半径r
	outtextxy(400, 700, "MyClock"); // 在指定位置显示字符串，前两个参数是坐标，第三个参数是字符串内容

										  // 画出刻度
	int x, y; // 刻度的坐标
	double a = 2 * PI / 12; // 每一大格的弧度
	for (int i = 0;i < 12;i++)
	{
		fillcircle(400 + 200 * sin(i*a), 400 - 200 * cos(i*a), 2);
		// line(400 + 195 * sin(i*a), 400 - 195 * cos(i*a), 400 + 205 * sin(i*a), 400 - 205 * cos(i*a)); // 划线line(x1,y1,x2,y2)
		// outtextxy(400 + 205 * sin(i*a), 600 - 205 * cos(i*a),(string) (i + 12) % 12);
		// outtextxy(400 + 190 * sin(i*a), 400 - 190 * cos(i*a), "0");
	}
}
void hands(int hour, int minute, int second)
{
	double a_hour, a_min, a_sec;// 时针、分针和秒针的弧度
	int x_hour, x_min, x_sec, y_hour, y_min, y_sec;// 三根针的末端位置坐标

	// 计算三根针的弧度,00：00：00记作三根针的弧度均为0
	a_sec = second * 2 * PI / 60;
	a_min = minute * 2 * PI / 60 + a_sec / 60;
	a_hour = hour * 2 * PI / 12 + a_min / 12;

	// 计算三根针的末端位置坐标
	x_sec = 100 * sin(a_sec); // 秒针长度为100
	y_sec = 100 * cos(a_sec);
	x_min = 80 * sin(a_min); // 分针长度为80
	y_min = 80 * cos(a_min);
	x_hour = 60 * sin(a_hour); // 时针长度为60
	y_hour = 60 * cos(a_hour);

	// 画三根针
	setlinestyle(PS_SOLID, 10); // void setlinestyle(int style, int thickness = 1)
	setcolor(BLUE);
	line(400 + x_hour, 400 - y_hour, 400, 400); // 时钟中心点是（400，400）

	setlinestyle(PS_SOLID, 8);
	setcolor(WHITE);
	line(400 + x_min, 400 - y_min, 400, 400);

	setlinestyle(PS_SOLID, 6);
	setcolor(RED);
	line(400 + x_sec, 400 - y_sec, 400, 400);
}
void main()
{
	initgraph(800, 800); // 窗口大小
	clock_background(); // 画表盘
	setwritemode(R2_XORPEN); // 设置 XOR 绘图模式
	SYSTEMTIME time; // 使用系统时钟的时间，定义为变量time
	
	HWND hwnd = GetHWnd(); // 获取窗口句柄
	SetWindowText(hwnd, "MyClock"); // 设置窗口标题文字
	
	while (1)
	{
		GetLocalTime(&time); // 获取当前时间
		hands(time.wHour, time.wMinute, time.wSecond); // 画三根针
		Sleep(1000);  // 过一秒
		hands(time.wHour, time.wMinute, time.wSecond); // 刷新三根针
	}

	closegraph(); // 关闭图形界面
}