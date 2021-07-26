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

// ������surprise���֣��Ǵ����ϸ���������һ�������̻����룩������ÿ��ʱ�Ӽ�ʱ����ʱ
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
	static clock_t oldclock = clock();// ��̬��������¼��һ�� tick


	oldclock += ms * CLOCKS_PER_SEC / 1000;// ���� tick


	if (clock() > oldclock)// ����Ѿ���ʱ��������ʱ
		oldclock = clock();
	else
		while (clock() < oldclock)// ��ʱ
			Sleep(1);// �ͷ� CPU ����Ȩ������ CPU ռ����
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
		initgraph(800, 800); // ���ڴ�С
		clock_background(); // ������
		setwritemode(R2_XORPEN); // ���� XOR ��ͼģʽ
		SYSTEMTIME time; // ʹ��ϵͳʱ�ӵ�ʱ�䣬����Ϊ����time

		HWND hwnd = GetHWnd(); // ��ȡ���ھ��
		SetWindowText(hwnd, "MyClock"); // ���ô��ڱ�������


		//while (1)
		for (i = 0; i < 60*test_last; i++)
		{
			//GetLocalTime(&time); // ��ȡ��ǰʱ��
			//hands(time.wHour, time.wMinute, time.wSecond); // ��������
			hands(h, m, s);
			Sleep(1000);  // ��һ��
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
			//hands(time.wHour, time.wMinute, time.wSecond); // ˢ��������
		}

		surprise(); // ��β��surprise
		closegraph(); // �ر�ͼ�ν���

		cout << "Start a new clock?(Y|N):";
		cin >> con;
	} while (con == 'Y' | con == 'y');
}