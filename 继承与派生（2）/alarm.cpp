#include <iostream>
#include <iomanip>
#include <windows.h>
#include "clock.h"
#include "alarm.h"
using namespace std;
void AlarmClock::Tick(){	// 函数重载
    Clock::Tick();
	if(AlarmHour==GetHour() && AlarmMinute==GetMinute())
		Alarm();
}
