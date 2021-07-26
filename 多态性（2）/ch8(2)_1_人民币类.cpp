#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;
class Money
{
	int Yuan, Jiao, Fen;
	char Sign;
public:
	void Format();
	Money(int y, int j, int f)
	{
		Yuan = y; Jiao = j; Fen = f;
		Format();
	}
	Money() {};
	Money operator +(Money m);
	Money operator -(Money m);
	Money& operator ++ ();
	Money operator ++ (int);
	friend Money& operator-- (Money& m);
	friend Money operator-- (Money& m, int i);
	friend ostream& operator<<(ostream& o, Money& mymoney)
	{
		if(mymoney.Yuan>=0)
		return o<< mymoney.Sign<<mymoney.Yuan << "元" << mymoney.Jiao << "角" << mymoney.Fen<<"分";
		else
		return o <<mymoney.Sign<< -mymoney.Yuan << "元" << -mymoney.Jiao << "角" << -mymoney.Fen<<"分";
	}
	friend istream& operator>>(istream& i, Money& mymoney)
	{
		return i >> mymoney.Yuan >> mymoney.Jiao >> mymoney.Fen;
	}
};
void Money::Format()                       //Format 函数
{
	if (Yuan >= 0)
	{
		Sign = '+';
		if (Fen >= 10)
		{
			Jiao = Jiao + (Fen / 10);
			Fen = Fen % 10;
		}
		if (Jiao >= 10)
		{
			Yuan += Jiao / 10;
			Jiao = Jiao % 10;
		}
	}
	else {
		Sign = '-';
		//Yuan = -Yuan;
		Fen = -Fen;
		Jiao = -Jiao;
		if (fabs(Fen) >= 10)
		{
			Jiao = Jiao - (Fen / 10);
			Fen = Fen % 10;
		}
		if (fabs(Jiao) >= 10)
		{
			Yuan -= Jiao / 10;
			Jiao = Jiao % 10;
		}
	}
}
Money Money::operator+(Money m)           //重载运算符“+”
{
	Money temp;
	temp.Yuan = Yuan + m.Yuan;
	temp.Jiao = Jiao + m.Jiao;
	temp.Fen = Fen + m.Fen;
	temp.Format();
	return temp;
}
Money Money::operator - (Money m)         //重载运算符“-”
{
	int nc1, nc2, nc3;            //先把钱都化成“分”，然后构造一个对象temp，将其返回。
	nc1 = Yuan * 100 + Jiao * 10 + Fen;
	nc2 = m.Yuan * 100 + m.Jiao* 10 + m.Fen;
	nc3 = nc1 - nc2;
	Money temp(0, 0, nc3);
	temp.Format();
	return temp;
}

Money& Money::operator ++ ()              //重载前置运算符“++”
{
	Fen++;
	if (Fen >= 10)
	{
		Jiao = Jiao + (Fen / 10);
		Fen = Fen % 10;
	}
	if (Jiao >= 10)
	{
		Yuan += Jiao / 10;
		Jiao = Jiao % 10;
	}
	return *this;
}

Money Money::operator++(int)             //重载后置运算符“++”
{
	Money old(*this);
	++(*this);
	return old;
}
Money& operator-- (Money& m)            //重载前置运算符_友元“--”
{
	m.Fen--;
	m.Format();
	return m;
}
Money operator-- (Money& m, int i)       //重载后置运算符_友元“--”
{
	Money old(m);
	m.Fen--;
	m.Format();
	return old;
}
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
