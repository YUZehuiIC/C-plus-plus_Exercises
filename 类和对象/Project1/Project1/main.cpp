#include <graphics.h> // ������Ҫ�������ͼ�ο�
#include <conio.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
// Ϊ���������󣬹������������
#include <stdio.h> 
#ifdef __cplusplus
extern "C"
#endif
FILE __iob_func[3] = { __acrt_iob_func(0),__acrt_iob_func(1),__acrt_iob_func(2) };

#define PI 3.141592653

void clock_background()
{
	// �����̵Ĵ�ԲȦ�����ڱ����������ʱ��
	circle(400, 400, 200); // ���������ֱ��ǣ�Բ������x��Բ������y���뾶r
	outtextxy(400, 700, "MyClock"); // ��ָ��λ����ʾ�ַ�����ǰ�������������꣬�������������ַ�������

										  // �����̶�
	int x, y; // �̶ȵ�����
	double a = 2 * PI / 12; // ÿһ���Ļ���
	for (int i = 0;i < 12;i++)
	{
		fillcircle(400 + 200 * sin(i*a), 400 - 200 * cos(i*a), 2);
		// line(400 + 195 * sin(i*a), 400 - 195 * cos(i*a), 400 + 205 * sin(i*a), 400 - 205 * cos(i*a)); // ����line(x1,y1,x2,y2)
		// outtextxy(400 + 205 * sin(i*a), 600 - 205 * cos(i*a),(string) (i + 12) % 12);
		// outtextxy(400 + 190 * sin(i*a), 400 - 190 * cos(i*a), "0");
	}
}
void hands(int hour, int minute, int second)
{
	double a_hour, a_min, a_sec;// ʱ�롢���������Ļ���
	int x_hour, x_min, x_sec, y_hour, y_min, y_sec;// �������ĩ��λ������

	// ����������Ļ���,00��00��00����������Ļ��Ⱦ�Ϊ0
	a_sec = second * 2 * PI / 60;
	a_min = minute * 2 * PI / 60 + a_sec / 60;
	a_hour = hour * 2 * PI / 12 + a_min / 12;

	// �����������ĩ��λ������
	x_sec = 100 * sin(a_sec); // ���볤��Ϊ100
	y_sec = 100 * cos(a_sec);
	x_min = 80 * sin(a_min); // ���볤��Ϊ80
	y_min = 80 * cos(a_min);
	x_hour = 60 * sin(a_hour); // ʱ�볤��Ϊ60
	y_hour = 60 * cos(a_hour);

	// ��������
	setlinestyle(PS_SOLID, 10); // void setlinestyle(int style, int thickness = 1)
	setcolor(BLUE);
	line(400 + x_hour, 400 - y_hour, 400, 400); // ʱ�����ĵ��ǣ�400��400��

	setlinestyle(PS_SOLID, 8);
	setcolor(WHITE);
	line(400 + x_min, 400 - y_min, 400, 400);

	setlinestyle(PS_SOLID, 6);
	setcolor(RED);
	line(400 + x_sec, 400 - y_sec, 400, 400);
}
void main()
{
	initgraph(800, 800); // ���ڴ�С
	clock_background(); // ������
	setwritemode(R2_XORPEN); // ���� XOR ��ͼģʽ
	SYSTEMTIME time; // ʹ��ϵͳʱ�ӵ�ʱ�䣬����Ϊ����time
	
	HWND hwnd = GetHWnd(); // ��ȡ���ھ��
	SetWindowText(hwnd, "MyClock"); // ���ô��ڱ�������
	
	while (1)
	{
		GetLocalTime(&time); // ��ȡ��ǰʱ��
		hands(time.wHour, time.wMinute, time.wSecond); // ��������
		Sleep(1000);  // ��һ��
		hands(time.wHour, time.wMinute, time.wSecond); // ˢ��������
	}

	closegraph(); // �ر�ͼ�ν���
}