#include <iostream>
#include <iomanip>
#include <windows.h>
#include "clock.h"
using namespace std;
Clock::Clock(int hour, int minute, int second)
{
    Hour = hour; Minute = minute; Second = second;
}
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
