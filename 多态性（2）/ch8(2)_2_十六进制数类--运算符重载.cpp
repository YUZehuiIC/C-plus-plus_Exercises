 //设计1~4位的无符号十六进制数据类class HEX. 
 //可以创建如 ABCD、1234、DF09、AB、26之类的1~4位的十六进制的正整数。
 //可以输入输出十六进制数据，可以实现十六进制数据和十进制数据的互换，
 //可以实现2个十六进制数据的+、-、*、/、%操作，各操作的要求请看程序注释。
#include <iostream.h>
#include <string>
#include <cmath>
#include <process.h>
using namespace std;

char Hex_num[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
class HEX
{   
	char m_num[10];	//可以存放10位十六进制数据，这样可以确保2个4位十六进制数据+和*的结果不会溢出
public:
	HEX();							//构造函数，初始化成全‘0’
	HEX(unsigned n);				//用无符号整数创建十六进制数据，（即无符号整数转换成十六进制数据）
	unsigned GetBit(int i);				//获得每一位数据的十进制数值
	operator unsigned();				//把十六进制数据转换成无符号的十进制数据
	int length();						//获得数据的长度
	HEX operator+(HEX n);				//加法
	HEX operator-(HEX n);				//减法运算要求被减数不小于减数
	HEX operator*(HEX n);				//乘法
	HEX operator/(HEX n);				//整除，即只要得到商
	HEX operator%(HEX n);				//取模，即只要得到余数
	HEX& operator++();					//前置++
	HEX operator++(int); 				//后置++
	friend istream& operator>>(istream& i, HEX& n);		// 输入十六进制数
	friend ostream& operator<<(ostream& o, HEX n);		//  输出十六进制数
};
HEX::HEX(){ m_num[10] = {'0'}; }
HEX::HEX(unsigned n){  // 从前往后存，m_num[0]是最后一位（个位）
	temp = n;
	for(int i=0;i<4;i++){
		m_num[i] = temp%16;
		temp = temp/16;
	}
}
unsigned HEX::GetBit(int i){	//获得每一位数据的十进制数值
	int num;
	for(int j=0;j<16;j++){
		if(m_num[i] == Hex_num[j])
			return j*power(16,i);
	}
}
operator HEX::unsigned(){	//把十六进制数据转换成无符号的十进制数据
	unsigned sum=0;
	for(int i=0;i<this.length();i++){
		sum += this.GetBit(i);
	}
	return sum;
}
int HEX::length(){
	for(int i=0;i<10;i++){
		if(m_num[i] == '0')
			return i+1;
	}
}
HEX HEX::operator+(HEX n){				//加法
	return HEX(this.unsigned() + n.unsigned());
}
HEX HEX::operator-(HEX n){				//减法运算要求被减数不小于减数

}
HEX HEX::operator*(HEX n){				//乘法

}
HEX HEX::operator/(HEX n){				//整除，即只要得到商

}
HEX HEX::operator%(HEX n){				//取模，即只要得到余数

}
HEX& HEX::operator++(){				//前置++

}
HEX HEX::operator++(int){ 				//后置++

}
istream& operator>>(istream& i, HEX& n){		// 输入十六进制数
	return cin >> 
}
ostream& operator<<(ostream& o, HEX n){		//  输出十六进制数
	for(int i=0;i<n.length();i++){
		
	}
}
int main()
{	HEX n1,n2,n3;
	char repeat('Y');
	do
	{	n1 = 0; n2 = 0; n3 =0;
		cin>>n1>>n2;
		n3 = n1+n2;
		cout<<n1<<'+'<<n2<<'='<<n3<<endl;
		n3 = n1-n2;
		cout<<n1<<'-'<<n2<<'='<<n3<<endl;
		n3 = n1*n2;
		cout<<n1<<'*'<<n2<<'='<<n3<<endl;
		n3 = n1/n2;
		cout<<n1<<'/'<<n2<<'='<<n3<<endl;
		n3 = n1%n2;
		cout<<n1<<'%'<<n2<<'='<<n3<<endl;
		cout<<"Repeat?(Y/N)";
		cin>>repeat;
	}while(repeat=='Y'||repeat=='y');
	return 0;
}