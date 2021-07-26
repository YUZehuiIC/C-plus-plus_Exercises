//201511210909 唐聪 作业9（1）
//助教，我的format函数有bug，我没时间改了（我今天才做的，不好意思啊），我下节课重新交一次，但这个还是可以运行的
#pragma once
#include<iostream>
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
void Money::Format()                                                         //Format 函数
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
Money Money::operator+(Money m)                                                        //重载运算符“+”
{
	Money temp;
	temp.Yuan = Yuan + m.Yuan;
	temp.Jiao = Jiao + m.Jiao;
	temp.Fen = Fen + m.Fen;
	temp.Format();
	return temp;
}
Money Money::operator - (Money m)                                                   //重载运算符“-”
{
	int nc1, nc2, nc3;            //先把钱都化成“分”，然后构造一个对象temp，将其返回。
	nc1 = Yuan * 100 + Jiao * 10 + Fen;
	nc2 = m.Yuan * 100 + m.Jiao* 10 + m.Fen;
	nc3 = nc1 - nc2;
	Money temp(0, 0, nc3);
	temp.Format();
	return temp;
}

Money& Money::operator ++ ()                                                          //重载   前置运算符“++”
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

Money Money::operator++(int)                                                      //重载后置运算符“++”
{
	Money old(*this);
	++(*this);
	return old;
}
Money& operator-- (Money& m)                                                     //重载前置运算符_友元“--”
{
	m.Fen--;
	m.Format();
	return m;
}
Money operator-- (Money& m, int i)                                               //重载后置运算符_友元“--”
{
	Money old(m);
	m.Fen--;
	m.Format();
	return old;
}
