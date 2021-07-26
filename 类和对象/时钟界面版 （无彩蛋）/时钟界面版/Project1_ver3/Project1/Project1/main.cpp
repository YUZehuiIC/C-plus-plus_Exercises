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

// 以下是surprise部分（是从网上复制下来的一个爱心烟花代码），加在每次时钟计时结束时
struct fpoint {
	int x0;
	int y0;
	double x;
	double y;
	double vx;
	double vy;
	int l;
	void InitP(
		int x0,
		int y0,
		double vx,
		double vy,
		int l) {
		x = this->x0 = x0;
		y = this->y0 = y0;
		this->vx = vx;
		this->vy = vy;
		this->l = l;
	}
	bool Move(
		const double &t,
		const double &k,
		const double &g
	) {
		if (l <= 0) return false;
		x = x0 + vx / k*(1 - exp(-k*t));
		double a = (g - vy*k) / k / k;
		y = y0 + g / k*t + a*exp(-k*t) - a;
		l--;
		return true;
	}
};
/*Data Of Love*/
int love[20] = {
	324, 318, 288, 211, 180, 211, 288, 318, 324, 304,
	262, 223, 213, 229, 279, 229, 213, 223, 262, 304
};

double lambda = 0.6f;

void Gauss(DWORD *pMem) {
	unsigned char R, G, B;
	for (int i = 500; i < 500 * 499; i++)
	{
		R = (GetRValue(pMem[i]) +
			GetRValue(pMem[i - 500]) +
			GetRValue(pMem[i + 500]) +
			GetRValue(pMem[i + 1]) +
			GetRValue(pMem[i - 1])) / 5;


		G = (GetGValue(pMem[i]) +
			GetGValue(pMem[i - 500]) +
			GetGValue(pMem[i + 500]) +
			GetGValue(pMem[i - 1]) +
			GetGValue(pMem[i + 1])) / 5;


		B = (GetBValue(pMem[i]) +
			GetBValue(pMem[i + 500]) +
			GetBValue(pMem[i - 500]) +
			GetBValue(pMem[i + 1]) +
			GetBValue(pMem[i - 1])) / 5;
		pMem[i] = RGB(R, G, B);
	}
}

void HpSleep(int ms)
{
	static clock_t oldclock = clock();// 静态变量，记录上一次 tick


	oldclock += ms * CLOCKS_PER_SEC / 1000;// 更新 tick


	if (clock() > oldclock)// 如果已经超时，无需延时
		oldclock = clock();
	else
		while (clock() < oldclock)// 延时
			Sleep(1);// 释放 CPU 控制权，降低 CPU 占用率
}
void surprise() {
	
		initgraph(500, 500, SHOWCONSOLE);
		DWORD *pMem = GetImageBuffer();
		setlinecolor(RGB(155, 50, 255));
		setlinestyle(PS_SOLID | PS_ENDCAP_ROUND, 3);


		fpoint p[20];
		double theta = 0.0f;
		for (int i = 0; i < 20; i++, theta += 3.141592653f / 10)
		{
			double vx = lambda*love[19 - i] * cos(theta);
			double vy = lambda*love[19 - i] * sin(theta);
			p[i].InitP(250, 160, vx, vy, 120);
		}


		double k = 0.5f;
		double g = 80.0f;
		double t = 0.0f;
		int x1, x2, y1, y2, i;
		while(true)
		{
			int c = 0;
			for (i = 0; i < 20; i++)
			{
				if (p[i].l > 0)
				{
					x1 = p[i].x;
					y1 = p[i].y;
					p[i].Move(t, k, g);
					x2 = p[i].x;
					y2 = p[i].y;
					line(x1, y1, x2, y2);
					c++;
				}
			}
			t += 0.02;
			if (c == 0)
			{
				theta = 0.0f;
				for (int i = 0; i < 20; i++, theta += 3.141592653f / 10)
				{
					double vx = lambda*love[19 - i] * cos(theta);
					double vy = lambda*love[19 - i] * sin(theta);
					p[i].InitP(250, 160, vx, vy, 120);
				}
				t = 0.0f;
			}
			Gauss(pMem);
			HpSleep(20);
			FlushBatchDraw();
			if (_kbhit())
			{
				break;
			}
		}
}
void main()
{
	int h(0), m(0), s(0),i(0),test_last(0);
	char con('y');
	
	do
	{
		system("cls");
		cout << "Input H M S:";
		cin >> h >> m >> s;
		cout << "Input how long will test last(in Min.):";
		cin >> test_last;
		initgraph(800, 800); // 窗口大小
		clock_background(); // 画表盘
		setwritemode(R2_XORPEN); // 设置 XOR 绘图模式
		SYSTEMTIME time; // 使用系统时钟的时间，定义为变量time

		HWND hwnd = GetHWnd(); // 获取窗口句柄
		SetWindowText(hwnd, "MyClock"); // 设置窗口标题文字


		//while (1)
		for (i = 0; i < 60*test_last; i++)
		{
			//GetLocalTime(&time); // 获取当前时间
			//hands(time.wHour, time.wMinute, time.wSecond); // 画三根针
			hands(h, m, s);
			Sleep(1000);  // 过一秒
			hands(h, m, s);
			s++;
			if (s >= 60)
			{
				m += s / 60;
				s %= 60;
			}
			if (m >= 60)
			{
				h += m / 60;
				m %= 60;
			}
			if (h >= 12)
				h = 0;
			//hands(time.wHour, time.wMinute, time.wSecond); // 刷新三根针
		}

		surprise(); // 结尾的surprise
		closegraph(); // 关闭图形界面

		cout << "Start a new clock?(Y|N):";
		cin >> con;
	} while (con == 'Y' | con == 'y');
}