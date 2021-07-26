#ifndef CLOCK_H
#define CLOCK_H
class Clock
{
private:
   	int Hour, Minute, Second;		// 24小时制的时间数据
   	int TickMinute,TickSecond,TickTime;		// 计时时长
public:
	Clock(){Hour = Minute = Second = 0; }//默认时钟时间是00:00:00
   	Clock(int hour, int minute, int second);
   	void ShowTime(); //显示时间功能
	void Tick();	//计时功能，每一次Tick，时间向前走1秒
	void SetTime(int NewH, int NewM, int NewS){Hour = NewH; Minute = NewM; Second = NewS; }		//重新设定时间值
	int SetTickTime(int tm,int ts){TickMinute = tm; TickSecond = ts; TickTime = 60*TickMinute + TickSecond;return TickTime; }
	int GetHour(){return Hour;}
	int GetMinute(){return Minute;}
};
#endif
