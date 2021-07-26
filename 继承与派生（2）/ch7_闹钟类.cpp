#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
class Clock
{
private:
   	int Hour, Minute, Second;		// 24小时制的时间数据
   	int TickMinute,TickSecond,TickTime;		// 计时时长
public:
	Clock(){Hour = Minute = Second = 0; }//默认时钟时间是00:00:00
   	Clock(int hour, int minute, int second){Hour = hour; Minute = minute; Second = second;}
   	void ShowTime(); //显示时间功能
	void Tick();	//计时功能，每一次Tick，时间向前走1秒
	void SetTime(int NewH, int NewM, int NewS){Hour = NewH; Minute = NewM; Second = NewS;  }		//重新设定时间值
	int SetTickTime(int tm,int ts){TickMinute = tm; TickSecond = ts; TickTime = 60*TickMinute + TickSecond;return TickTime; }
	int GetHour(){return Hour;}
	int GetMinute(){return Minute;}
};
void Clock::ShowTime(){
	cout.fill(0);
	cout << setw(2) << Hour << ":" << setw(2) << Minute << ":" << setw(2) << Second << endl;
}
void Clock::Tick(){

		if(++Second==60){
			Second = 0;
			if(++Minute==60){
				Minute = 0;
				if(++Hour==24)
					Hour = 0;
			}
		}
		// 输出格式设置
    cout.fill('0'); // 处理个位数补0成为两位数的情况
	cout << "时间是 ";
	cout << setw(2) << Hour << ":"
	<< setw(2) << Minute << ":"
	<< setw(2) << Second;
    Sleep(1000); // 定时1s
    cout << '\r'; // 输出位置不变


}
class AlarmClock:public Clock
{
private:
	int AlarmHour,AlarmMinute;
public:
	AlarmClock(){AlarmHour = 23; AlarmMinute = 59;}//默认闹钟时间是23：59
	AlarmClock(int AH,int AM){AlarmHour = AH; AlarmMinute = AM;}
	void Alarm(){ cout << '\7' << '\7' << '\7'; }
	void SetAlarmTime(int AH,int AM){AlarmHour = AH;AlarmMinute = AM;}
	void Tick();
};
void AlarmClock::Tick(){	// 函数重载
    Clock::Tick();
	if(AlarmHour==GetHour() && AlarmMinute==GetMinute())
		Alarm();
}
int main(){
	AlarmClock AC;
	int h,m,s,ah,am,tm,ts;
	char judge;
	while(1){
		cout << "请输入初始时间（时 分 秒）：";
		cin >> h >> m >> s;
		AC.SetTime(h,m,s);
		cout << "请输入闹铃时间（时 分）";
		cin >> ah >> am;
		AC.SetAlarmTime(ah,am);
		cout << "请输入计时时长（分 秒）";
		cin >> tm >> ts;
		for(int i=0;i<AC.SetTickTime(tm,ts);i++){
            AC.Tick();}

		cout << "计时结束，还要继续吗（Y/N）？";
		cin >> judge;
		if(judge=='N')
			break;
	}
	cout << "Press any key to continue";

	return 0;
}
