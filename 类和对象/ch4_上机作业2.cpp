// Clock类设计如下，请添加所有的成员函数。
// 并编写主程序。
// 使得程序的输入输出符合”输入输出样例”。
//  class  Clock
// { private:
//    int Hour, Minute, Second;
//  public:
//    void SetTime (int NewH, int NewM, int NewS);
//    void ShowTime();
//    int GetHour();
//    int GetMinute();
//    int GetSecond();
//  };
//
// 输入输出样例：
// 请输入时间（时 分 秒）：23 59 45（回车）
// 时间是  23:59:45
// 还要继续测试吗（Y/N）？Y（回车）
// 请输入时间（时 分 秒）：2 5 3（回车）
// 时间是   02:05:03
// 还要继续测试吗（Y/N）？Y（回车）
// ……..					//（以上过程重复）
// 还要继续测试吗（Y/N）？N（回车）
// 程序结束了，再见！
// Press any key to continue
#include<iostream>
#include<iomanip>
using namespace std;
class  Clock{
	private:
   		int Hour, Minute, Second;
 	public:
   		void SetTime (int NewH, int NewM, int NewS);
   		void ShowTime();
   		int GetHour(){int n; cin >> n; return n;}
   		int GetMinute(){int n; cin >> n; return n;}
   		int GetSecond(){int n; cin >> n; return n;}
 };
void Clock::SetTime(int NewH,int NewM,int NewS){
	Hour = NewH;
	Minute = NewM;
	Second = NewS;
}
void Clock::ShowTime(){
    cout.fill('0'); // 补0
	cout << "时间是 " << setw(2) << Second << ":" << setw(2) << Minute << ":" << setw(2) << Hour << endl;
}
int main(){

	Clock my_clock;
	char judge;
	while(1){
		cout << "请输入时间（时 分 秒）：";
		my_clock.SetTime(my_clock.GetHour(),my_clock.GetMinute(),my_clock.GetSecond());
		my_clock.ShowTime();
		cout << "还要继续测试吗（Y/N）？";
		cin >> judge;
		if(judge == 'N') break;
	}
	cout << "程序结束了，再见！";

}
