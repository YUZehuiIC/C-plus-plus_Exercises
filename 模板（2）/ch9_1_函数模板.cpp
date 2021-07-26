// step1. 编写函数模板cmpValue，返回2个数值中较小者。
// step2. 在主函数中分别测试以下类型：int、float、string、char [](字符数组).
// 这些类型都能使用模板函数cmpValue正确返回较小者吗？如果不能，应该如何改进程序？
#include <iostream>
#include <string.h>
#include <typeinfo>
using namespace std;
template <typename T>
T cmpValue(T a,T b){
	if(typeid(a)==typeid(int) && typeid(b)==typeid(int)){ // int型比较大小
		if(a > b)	return b;
		else return a;
	}
	else if(typeid(a)==typeid(float) && typeid(b)==typeid(float)){  // float型比较大小
		if(a > b)	return b;
		else return a;
	}
	else if(typeid(a)==typeid(string) && typeid(b)==typeid(string)){  // string型比较大小
		if(a > b)	return b;
		else return a;
	}
	else if(typeid(a)==typeid(char*) && typeid(b)==typeid(char*)){  // char*型比较大小
		return (strcmp(a,b)>0)?b:a;
	}
}
int main(){
	int i1,i2,len;
	float f1,f2;
	string s1,s2,str1,str2;
	char *c1,*c2;
	char temp;

	cout << "请输入要测试的两个整数:"<< endl;
	cout << "第一个整数：";
	cin >> i1;
	cout << "第二个整数：";
	cin >> i2;
	cout << "结果求得较小者为" << cmpValue(i1,i2) << endl;

	cout << "请输入要测试的两个浮点数:"<< endl;
	cout << "第一个浮点数：";
	cin >> f1;
	cout << "第二个浮点数：";
	cin >> f2;
	cout << "结果求得较小者为" << cmpValue(f1,f2) << endl;

	cout << "请输入要测试的两个字符串:"<< endl;
	cout << "第一个字符串：";
	cin >> s1;
	cout << "第二个字符串：";
	cin >> s2;
	cout << "结果求得较小者为" << cmpValue(s1,s2) << endl;

	cout << "请输入要测试的两个字符数组:"<< endl;
	cout << "第一个字符数组：";
	while((temp = cin.get())!='\n'){
        str1 += temp;
	}
	len = str1.length();
	c1 = new char[len];
	for(int i=0;i<len;i++){
		c1[i] = str1[i];
	}
	c1[len] = '\0';

	cout << "第二个字符数组：";
	while((temp = cin.get())!='\n'){
        str2 += temp;
	}
	len = str2.length();
    c2 = new char[len];
	for(int i=0;i<len;i++){
		c2[i] = str2[i];
	}
	c2[len] = '\0';
	cout << "结果求得较小者为" << cmpValue(c1,c2) << endl;

}
