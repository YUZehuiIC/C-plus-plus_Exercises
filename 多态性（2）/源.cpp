//201511210909 唐聪 作业9（1）
#include"标头.h"
#include<cstdlib>
int main()
{
	Money c3;
	int i,yuan, jiao, fen, yuan1, jiao1, fen1;
	char  choice, choice1;
	do
	{
		cout << "请构造两个人民币：" << endl;
		cout << "人民币1：";
		cin >> yuan >> jiao >> fen;
		cout << "人民币2：";
		cin >> yuan1 >> jiao1 >> fen1;
		Money c1(yuan, jiao, fen);
		Money c2(yuan1, jiao1, fen1);
		for (i = 1; i <= 6; i++)                           //如word文档里面所展示的一样，在这里用for循环，6次
		{
			cout << "请选择运算(A:+/S:-/Q:++i/H:i++/J:--i/K:i--/): ";
			cin >> choice;
			switch (choice)
			{
			case 'A': case 'a':
				c3 = c1 + c2;
				cout << '(' << c1 << ')' << '+' << '(' << c2 << ')' << '=' << '(' << c3 << ')' << endl;
				break;
			case 'S': case 's':
				c3 = c1 - c2;
				cout << '(' << c1 << ')' << '-' << '(' << c2 << ')' << '=' << '(' << c3 << ')' << endl;
				break;
			case 'Q': case 'q':
				cout << "++" << '(' << c1 << ')' << '=';
				c3 = ++c1;
				cout << '(' << c3 << ')' << endl;
				break;
			case 'H': case 'h':
				cout << '(' << c1 << ')' << "++" << '=';
				c3 = c1++;
				cout << '(' << c3 << ')' << endl;
				cout << "人民币1：" << '(' << c1 << ')' << endl;
				break;
			case 'J': case 'j':
				cout << "--" << '(' << c1 << ')' << '=';
				c3 = --c1;
				cout << '(' << c3 << ')' << endl;
				break;
			case 'K': case 'k':
				cout << '(' << c1 << ')' << "--" << '=';
				c3 = c1--;
				cout << '(' << c3 << ')' << endl;
				cout << "人民币1：" << '(' << c1 << ')' << endl;
				break;
			}
		}
		cout << "您还要继续吗？(Y / N):";
		cin >> choice1;
	} while (choice1 == 'Y' || choice1 == 'y');
	system("pause");
	return 0;
}