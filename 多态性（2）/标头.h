//201511210909 �ƴ� ��ҵ9��1��
//���̣��ҵ�format������bug����ûʱ����ˣ��ҽ�������ģ�������˼���������½ڿ����½�һ�Σ���������ǿ������е�
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
		return o<< mymoney.Sign<<mymoney.Yuan << "Ԫ" << mymoney.Jiao << "��" << mymoney.Fen<<"��";
		else
		return o <<mymoney.Sign<< -mymoney.Yuan << "Ԫ" << -mymoney.Jiao << "��" << -mymoney.Fen<<"��";
	}
	friend istream& operator>>(istream& i, Money& mymoney)
	{
		return i >> mymoney.Yuan >> mymoney.Jiao >> mymoney.Fen;
	}
};
void Money::Format()                                                         //Format ����
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
Money Money::operator+(Money m)                                                        //�����������+��
{
	Money temp;
	temp.Yuan = Yuan + m.Yuan;
	temp.Jiao = Jiao + m.Jiao;
	temp.Fen = Fen + m.Fen;
	temp.Format();
	return temp;
}
Money Money::operator - (Money m)                                                   //�����������-��
{
	int nc1, nc2, nc3;            //�Ȱ�Ǯ�����ɡ��֡���Ȼ����һ������temp�����䷵�ء�
	nc1 = Yuan * 100 + Jiao * 10 + Fen;
	nc2 = m.Yuan * 100 + m.Jiao* 10 + m.Fen;
	nc3 = nc1 - nc2;
	Money temp(0, 0, nc3);
	temp.Format();
	return temp;
}

Money& Money::operator ++ ()                                                          //����   ǰ���������++��
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

Money Money::operator++(int)                                                      //���غ����������++��
{
	Money old(*this);
	++(*this);
	return old;
}
Money& operator-- (Money& m)                                                     //����ǰ�������_��Ԫ��--��
{
	m.Fen--;
	m.Format();
	return m;
}
Money operator-- (Money& m, int i)                                               //���غ��������_��Ԫ��--��
{
	Money old(m);
	m.Fen--;
	m.Format();
	return old;
}
