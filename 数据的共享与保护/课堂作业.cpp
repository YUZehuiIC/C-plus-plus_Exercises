// 【课堂练习】设计类，使用静态成员，
// 求从1到n（n是大于0的整数）的和 .
// 程序中不要使用循环，不要使用求和公式。
#include <iostream>
using namespace std;
class Sum{
public:
    static int num;
    static int sum_temp;
	Sum(){
		sum_temp += num;
        num++;
	}
};
int Sum::num = 1;
int Sum::sum_temp = 0;
int main(){
	int n;
	cout << "n=";
	cin >> n;
	Sum sum[n];
	cout << "sum=" << Sum::sum_temp;
	return 0;
}
