//201511210909 �ƴ� ��ҵ9��1��
#include"��ͷ.h"
#include<cstdlib>
int main()
{
	Money c3;
	int i,yuan, jiao, fen, yuan1, jiao1, fen1;
	char  choice, choice1;
	do
	{
		cout << "�빹����������ң�" << endl;
		cout << "�����1��";
		cin >> yuan >> jiao >> fen;
		cout << "�����2��";
		cin >> yuan1 >> jiao1 >> fen1;
		Money c1(yuan, jiao, fen);
		Money c2(yuan1, jiao1, fen1);
		for (i = 1; i <= 6; i++)                           //��word�ĵ�������չʾ��һ������������forѭ����6��
		{
			cout << "��ѡ������(A:+/S:-/Q:++i/H:i++/J:--i/K:i--/): ";
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
				cout << "�����1��" << '(' << c1 << ')' << endl;
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
				cout << "�����1��" << '(' << c1 << ')' << endl;
				break;
			}
		}
		cout << "����Ҫ������(Y / N):";
		cin >> choice1;
	} while (choice1 == 'Y' || choice1 == 'y');
	system("pause");
	return 0;
}