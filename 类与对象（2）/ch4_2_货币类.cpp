// 2.设计货币类CMoney，用来描述生活中的货币。
// 数据成员（私有）包括元、角、分。
// 成员函数（公有）包括设置值函数SetValue、显示函数Show、
// 		获得元值GetYuan、获得角值GetJiao、获得分值GetFen等函数
// 		和以下构造函数、拷贝构造函数和析构函数：
// （a）无参构造函数，该函数把元角分的初值都设成0，并输出“无参构造函数被调用”；
// （b）带有3个参数的构造函数，该函数把元角分的初值设成用户输入的初始值；
// 		请做进位操作（比如：“1元22角33分”经过进位操作后，转化成3元5角3分）；
// 		在函数结束前输出“有参构造函数被调用”
// （c）拷贝构造函数，完成拷贝构造的功能，并输出“拷贝构造函数被调用”
// （d）析构函数，并输出“析构函数被调用”
// 主程序中，请用以下3种方式创建对象：
// （1） 普通变量的方式。（如：CMoney m; ）
// （2） 指针的方式。（如：CMoney * pm = new CMoney;）
// （3） 数组的方式。（如：CMoney money[10]; ）
#include <iostream>
using namespace std;
class CMoney{
private:
	int yuan,jiao,fen;
public:
	void SetValue(int y,int j,int f){yuan = y;jiao = j;fen = f;}
	void Show(){cout << yuan << "元" << jiao << "角" << fen << "分" << endl;}
	void GetYuan(){yuan = yuan + jiao / 10 + fen / 100;}
	void GetJiao(){jiao = (jiao + fen / 10) % 10;}
	void GetFen(){fen = fen % 10;}
	CMoney();
	CMoney(int a,int b,int c);
	CMoney(const CMoney& p);
	~CMoney(){cout << "析构函数被调用" << endl;}
};
CMoney::CMoney(){
	yuan = jiao = fen = 0;
	cout << "无参构造函数被调用" << endl;
}
CMoney::CMoney(int a,int b,int c){
	yuan = a;jiao = b;fen = c;
	yuan = yuan + jiao / 10 + fen / 100;
	jiao = (jiao + fen / 10) % 10;
	fen = fen % 10;
	cout << "有参构造函数被调用" << endl;
}
CMoney::CMoney(const CMoney& p){
	yuan = p.yuan;
	jiao = p.jiao;
	fen = p.fen;
	cout << "拷贝构造函数被调用" << endl;
}
int main(){
    int y,j,f;
	CMoney m;
	cout << "初始数据(元 角 分，以空格分隔)：";
	cin >> y >> j >> f;
	m.SetValue(y,j,f);
	m.GetYuan();
	m.GetJiao();
	m.GetFen();
	cout << "处理结果：";
	m.Show();

	CMoney* pm = new CMoney;
	pm = &m;
	cout << "拷贝数据：";
	pm->Show();

	CMoney money[2] = {m,*pm};
	return 0;
}

// 代码反思：
// 1. class X(){};这里的分号不要忘记
// 2. 对象指针定义：CMoney* pm = new CMoney
// 3. 对象指针调用成员函数: pm->Show();
//      不能写成：pm.Show();
