#ifndef ALARM_H
#define ALARM_H
#include <iostream>
#include "clock.h"

using namespace std;
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
#endif
