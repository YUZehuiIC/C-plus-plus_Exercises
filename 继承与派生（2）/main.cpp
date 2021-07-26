#include <iostream>
#include <iomanip>
#include <windows.h>
#include "clock.h"
#include "alarm.h"
using namespace std;
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
