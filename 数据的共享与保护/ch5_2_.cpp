// （上机思考题）  设计活期存款类Deposit . 参考图1，
// 每个账户有帐号（自动编号）、户名、密码、金额、月利率（静态成员）、
// 户时间6项信息。
// 银行每月1号要根据账户余额发给客户利息，利息被累计到客户存款余额中。
// 银行可以更改利率。
//
// 本月余额计算方法：	本月余额 = 上月余额 + 上月余额*月利率
//  （如有小数出现，保留小数点后2位，四舍五入）
//
// 主程序中：建立以下5个账户：
// 账号	户名 	密码   	金额   月利率  开户时间
// 1		张三 	123456  10000  0.5% 	2017-3-1
// 2		李四 	112233  20000  0.5% 	2016-2-1
// 3		王五 	111111  15000  0.5% 	2017-5-1
// 4		赵六 	222222  58000  0.5% 	2016-7-1
// 5		周七	888888  50000  0.5% 	2017-3-1
// 程序运行：
// 2017-7-1，输出所有账户的信息；
// 2017-8-1，调整利率为0.4%;
// 2017-9-1, 输出所有账户的信息；
// 2017-10-1, 输出所有账户的信息；
#include <iostream>
#include <iomanip>
using namespace std;
class Deposit{
private:
	int num;
	string name;
	int code;
	double money;
	string time;
public:
	static double profit;
	void search(){
		cout << setw(10) << "账号" << setw(10) << "户名" << setw(10)
		<< "密码" << setw(10) << "金额" << setw(10) << "月利率" << setw(10)
		<< "开户时间" << endl;
		cout << setw(10) << num << setw(10) << name << setw(10)
		<< code << setw(10) << money << setw(10) << profit << setw(10)
		<< time << endl;
	}
	static void fix_profit(){
		profit = 0.004;
	}
	void Set(int n1,string n2,int c,double m,string t){
		num = n1;
		name = n2;
		code = c;
		money = m;
		time = t;
	}
	void cal_money(int month){
		money = money + money*profit;
	}
};
double Deposit::profit = 0.005;
int main(){
	Deposit d1,d2,d3,d4,d5;
	d1.Set(1,"张三",123456,10000,"2017-3-1");
	d2.Set(2,"李四",112233,20000,"2016-2-1");
	d3.Set(3,"王五",111111,15000,"2017-5-1");
	d4.Set(4,"赵六",222222,58000,"2016-7-1");
	d5.Set(5,"周七",888888,50000,"2017-3-1");

	cout << "2017-7-1:" << endl;
	d1.cal_money(4);	d1.search();
	d2.cal_money(17);	d2.search();
	d3.cal_money(2);	d3.search();
	d4.cal_money(12);	d4.search();
	d5.cal_money(4);	d5.search();

	cout << "2017-8-1:" << endl;
	Deposit::fix_profit();
	cout << "利润是：" << Deposit::profit;

	cout << "2017-9-1" << endl;
	d1.cal_money(2);	d1.search();
	d2.cal_money(2);	d2.search();
	d3.cal_money(2);	d3.search();
	d4.cal_money(2);	d4.search();
	d5.cal_money(2);	d5.search();

	cout << "2017-10-1" <<endl;
	d1.cal_money(1);	d1.search();
	d2.cal_money(1);	d2.search();
	d3.cal_money(1);	d3.search();
	d4.cal_money(1);	d4.search();
	d5.cal_money(1);	d5.search();
	}
