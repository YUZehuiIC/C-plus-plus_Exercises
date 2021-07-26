// 输出2017-9月的月历:
//    (1) 按照月历格式化进行输出。
//    (2) 定义周一到周日的枚举类型，根据用户输入月历中的日期，
//    	判断是星期几并输出。
#include <iostream>
#include <iomanip>
using namespace std;
int main(void){
	int date = 1; 
	int usr_date,day;

	// 首先按照期望的格式打印日历标题
	cout << setw(37) << "2017年9月" << endl;
	cout << setw(10) << "周日" << setw(10) << "周一" << setw(10) << "周二" 
	<< setw(10) << "周三" << setw(10) << "周四" << setw(10) << "周五" << setw(10) << "周六" << endl;

	// 打印9月份的具体日期
	cout << setw(48) << date; // 9月1日是周五，从周五开始，经过测试，域宽为48（为什么不是60？）
	while(date < 30){
		date ++;
		cout << setw(8) << date;
		if((date-2) % 7 == 0)
			cout << endl;	// 每7天换行
	}

	// 记录用户输入的日期，命名为usr_date
	cout << "请输入要查询的日期：";
	cin >> usr_date;

	// 根据日期与星期之间的关系，计算出usr_date对应的星期 day
	day = (usr_date + 4) % 7 ;	

	// 输出查询结果
	cout << usr_date << "对应的是星期" << day;
}

// 学习小结：
// 1. 输出格式控制：
// 		·头文件 #include<iomanip>
// 		·setw(n)：控制域宽为n
// 			用法：cout << setw(n) << "balabala"
// 