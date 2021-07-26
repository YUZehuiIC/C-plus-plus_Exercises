// 7. 设计3个小程序，都实现：为用户随机输入的3个整数按照从小到大的顺序排序
// 	输入输出：
// 请输入3个整数：100 90 80
// 按照从小到大输出是：80 90 100
// （带下划线的部分表示用户的输入）
// （1）按照传值的方式设计子函数
// （2）按照传引用的方式设计子函数
// （3）按照传指针的方式设计子函数
#include <iostream>
using namespace std;
void sorting(int a,int b,int c);
int main(){
	int a,b,c;
	cout << "请输入3个整数:";
	cin >> a >> b >> c;
	cout << "按照从小到大输出是:";
	sorting(a,b,c);

}
void sorting(int a,int b,int c){
	if(b < a){
		if(c < b) cout << c << " " << b << " " << a;
		else{
			if(c < a) cout << b << " " << c << " " << a;
			else cout << b << " " << a << " " << c;
		}
	}
	else{
		if(b < c) cout << a << " " << b << " " << c;
		else{
			if(a < c) cout << a << " " << c << " " << b;
			else cout << c << " " << a << " " << b;
		}
	}
}
