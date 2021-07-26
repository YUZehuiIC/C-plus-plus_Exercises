// 1.超市经销大米，成袋购入，成袋售出。
// 每袋大米的质量有2.5公斤的、有5公斤、有10公斤的等，超市记录所有大米的总质量。
// 设计Rice类，包含私有数据成员: 质量Weight和产地Place；
// 还包含私有静态数据成员: 总质量TotalWeight .
// Rice类的公有成员函数：
// (1)构造函数 Rice(double weight=0, string place=”XXX”);
// 		构造新对象的同时总质量要增加；
// (2)拷贝构造函数 Rice(const Rice&);
// 		拷贝构造新对象的同时总质量要增加；
// (3)析构函数~Rice();
// 		析构对象的同时总质量要减少；
// (4)静态函数static double GetTotal();
// 在main函数中，以不同的方式创建至少3袋大米，在每次创建大米对象后都输出总质量。
#include <iostream>
using namespace std;
class Rice{
private:
	double weight;
	string place;
	static double TotalWeight;
public:
	Rice(double w=0,string p="XXX"){weight = w;place = p; TotalWeight += weight;}
	Rice(const Rice& r){weight = r.weight; place = r.place; TotalWeight += r.weight;}
	~Rice(){TotalWeight -= weight;}
	static double GetTotal(){return TotalWeight;}
	void Set(double w,string p){weight = w;place = p;double temp = weight;TotalWeight += temp;}

};
double Rice::TotalWeight=0;
int main(){
    cout << Rice::GetTotal() << endl;
	Rice r1(2.5,"东北");
	cout << Rice::GetTotal() << endl;
	Rice r2(r1);
	cout << Rice::GetTotal() << endl;
	Rice r3;
	r3.Set(5,"泰国");
	cout << Rice::GetTotal() << endl;
	return 0;
}
// 小结：
// 1. 静态成员函数没有this指针，作为类的成员函数调用，而不是某个特定对象的成员函数
// 2. 实参和形参的名字不要取一样的，不然容易错
