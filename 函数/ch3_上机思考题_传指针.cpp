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
void sorting(int* a,int* b,int* c);
int main(){
	int a,b,c;
	cout << "请输入3个整数:";
	cin >> a >> b >> c;
	cout << "按照从小到大输出是:";
	sorting(&a,&b,&c);
	cout << a << " " << b << " " << c;

}
void sorting(int* a,int* b,int* c){
	int temp1,temp2;
	if(*b < *a){
//          c<b<a
		if(*c < *b){
			temp1 = *a;
			temp2 = *b;
			*a = *c;
			*b = temp2;
			*c = temp1;
		}
	 	else{
//	 	    b<c<a;
	 		if(*c < *a){
	 			temp1 = *a;
	 			temp2 = *b;
	 			*a = *b;
	 			*b = temp2;
	 			*c = temp1;
	 		}
//	 		b<a<c
	 		else{
                temp1 = *a;
	 			temp2 = *b;
	 			*a = *b;
	 			*b = temp1;
	 			*c = *c;
	 		}
	 	}
	 }
	 else{
//      a<b<c
	 	if(*b < *c) {
            *a = *a;
            *b = *b;
            *c = *c;
	 	}
	 	else{
//            a<c<b
	 		if(*a < *c) {
                temp1 = *b;
	 			*a = *a;
	 			*b = *c;
	 			*c = temp1;
	 		}
//	 		c<a<b
	 		else{
                temp1 = *a;
	 			temp2 = *b;
	 			*a = *c;
	 			*b = temp1;
	 			*c = temp2;
	 		}
	 	}
	 }
}
