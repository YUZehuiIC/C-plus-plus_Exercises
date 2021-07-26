// 可走秒的时钟类Clock

// 在题目2的基础上实现一个能够“走秒”的时钟模拟程序。
// 编写主程序，使得程序的输入输出符合下面的“输入输出样例”。
// class  Clock
// { private:
//    int Hour, Minute, Second;
//  public:
//    void SetTime (int NewH, int NewM, int NewS);
//    void Tick();		//走秒
//    void ShowTime();
//    int GetHour();
//    int GetMinute();
//    int GetSecond();
//  };
//  输入输出样例：
// 请输入时间（时 分 秒）：23 59 45（回车）
// 请输入测试时长（分）：3（回车）
// 时间是  23:59:45		//（这里在相同的位置//显示从23时59分45秒到00时02分45秒）
// 还要继续测试吗（Y/N）？Y（回车）
// 请输入时间（时 分 秒）：2 5 3（回车）
// 请输入测试时长（分）：2（回车）
// 时间是  02:05:03		//（这里在相同的位置//显示从02时05分03秒到02时07分03秒）
// 还要继续测试吗（Y/N）？N（回车）
// 程序结束了，再见！
// Press any key to continue
// 编程提示：
// （1）字符’\r’ （只回车不换行）可以控制输出的内容在同样的位置
// 函数“Sleep（）”可以让程序暂停，参见以下代码
// #include<windows.h>
// #include <iostream>
// using namespace std;
// int main()
// {	for(int i=0;i<10;i++)
// 	{	cout<<i<<"              \r";
// 		Sleep(1000);
// 	}
// 	return 0;
// }
// （2）设置输出格式的相关操作:
// setw(int)可以设置输出内容的宽度;
// setfill(char)可以设置前导符号;
// 这些格式设置操作的使用要求包含头文件<iomanip>
// 例：
// char s[5]=”abc”;
// cout<<setw(10)<<setfill('%')<<s<<endl;
// 将输出：
// %%%%%%%abc
#include<iostream>
#include<iomanip>
#include<windows.h>
using namespace std;
class  Clock{
	private:
   		int Hour, Minute, Second;
 	public:
   		void SetTime (int NewH, int NewM, int NewS);	//设置初始时间
   		void Tick(int TestMinute);	//走秒
   		void ShowTime();	// 显示初始时间
   		int GetHour(){int n; cin >> n; return n;}	// 获取初始小时数
   		int GetMinute(){int n; cin >> n; return n;}	// 获取初始分钟数
   		int GetSecond(){int n; cin >> n; return n;}	// 获取初始秒数
   		int GetTestMinute(){int n;cin >> n;return n;} // 获取测试时长
 };
void Clock::SetTime(int NewH,int NewM,int NewS){
    // 这里读入的第一个参数一定是Second,第二个是Minute,第三个是Hour，不知道为什么
	Hour = NewS;
	Minute = NewM;
	Second = NewH;
}
void Clock::Tick(int TestMinute){
	int TestSecond,i;
	TestSecond = TestMinute * 60;
	for(i=0;i<TestSecond;i++){
        // 设置走秒
		if(!(Second = ++Second%60))
			if(!(Minute = ++Minute%60))
				Hour = ++Hour%24;
        // 输出格式设置
        cout.fill('0'); // 处理个位数补0成为两位数的情况
		cout << "时间是 ";
		cout << setw(2) << Hour << ":"
		<< setw(2) << Minute << ":"
		<< setw(2) << Second;
        Sleep(1000); // 定时1s
        cout << '\r'; // 输出位置不变
	}
}
void Clock::ShowTime(){	//显示初始时间
    cout.fill('0'); // 补0
	cout << "初始时间是 " << setw(2) << Hour << ":" << setw(2) << Minute << ":" << setw(2) << Second << endl;
}
int main(){
	Clock my_clock;
	char judge;
	while(1){
		cout << "请输入时间（时 分 秒）：";
		my_clock.SetTime(my_clock.GetHour(),my_clock.GetMinute(),my_clock.GetSecond());
		my_clock.ShowTime();
		cout << "请输入测试时长（分）：";
		my_clock.Tick(my_clock.GetTestMinute());
		cout << "还要继续测试吗（Y/N）？";
		cin >> judge;
		if(judge == 'N') break;
	}
	cout << "程序结束了，再见！";

}