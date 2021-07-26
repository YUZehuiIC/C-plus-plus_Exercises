// 模拟电力公司统计用户用电量。
// 请设计一个类FamliyElecPower描述每户人家一年的用电情况，一年的12个月的每月电量都要记录。
// 设计函数CalTotalEPower，计算每户一年的总电量；
// 函数CalAveEPower计算每户的每月平均用电量。
// 函数CalTotalEPower和函数CalAveEPower是类FamliyElecPower的友元函数。
// 主程序中创建1户人家，输入这户人家1年12个月的用电量，
// 然后调用函数CalTotalEPowver和函数CalAveEPower分别计算并输出这家的总用电量和平均每月用电量。
// 输入输出样例：
// 请输入用户名称：Wang 					//带下划线的部分表示用户的输入
// 请分别输入12个月的电量：89 70 56 102 112 92 90 88 75 89 86 123
// 用户用电信息是：
// 编号：1				名称：Wang
// 12个月的用电量：89 70 56 102 112 92 90 88 75 89 86 123
// 年总电量：1072		月均电量:：89
// 上机思考题部分:
// 从文件输入100个家庭的信息，统计每户年总电量、月均电量，结果可以输出到另一个文件中
// 选作部分的输入输出参见in.txt, out.txt
#include <iostream>
#include <string.h>
#include <iomanip>
#include <fstream>
using namespace std;
class FamilyElecPower
{

	int m_nID;// 用户编号，是从1开始的正整数，由程序自动生成
	string n_strFamilyName;// 家庭名称
	int m_array[12];// 用电量数组
	static int m_nCount; // 用来生成自动编号的计数器
public:
	FamilyElecPower(){ m_nCount ++; }
	FamilyElecPower(string name, int* array){
		m_nCount ++;
		m_nID = m_nCount;
		n_strFamilyName = name;
		for(int i=0;i < 12;i++){
			m_array[i] = array[i];
		}
	}
	friend double CalAveEPower(FamilyElecPower& f);	// 计算每户的每月平均用电量
	friend int CalTotalEPower(FamilyElecPower& f);	// 计算这家的总用电量
	void Show(){	//输出这户人家的所有信息
		cout << "用户用电信息是：" << endl;
		cout << "编号：" << m_nID << endl;
		cout << "名称：" << n_strFamilyName << endl;

		cout << "12个月的用电量：";
		for(int i=0;i<12;i++){
			cout << m_array[i] << " ";
		}
		cout << endl;


	}
	string GetName(){ return n_strFamilyName; }
};
int FamilyElecPower::m_nCount = 0;
double CalAveEPower(FamilyElecPower& f){	// 计算每户的每月平均用电量
	return CalTotalEPower(f)/12;
}
int CalTotalEPower(FamilyElecPower& f){	// 计算这家的总用电量
	int sum = 0;
	for(int i=0;i<12;i++){
		sum += f.m_array[i];
	}
	return sum;
}
int main(){
	// 自定义一个用户
	string name;
	int m[12];

	cout << "请输入用户名称：";
	cin >> name;
	cout << "请分别输入12个月的电量：";
	for(int i =0;i<12;i++){ cin >> m[i]; }
	FamilyElecPower fep(name,m);
	fep.Show();
    cout << "年总电量：" << CalTotalEPower(fep) << endl;
    cout << "月均电量：" << setprecision(5) << CalAveEPower(fep) << endl;

	// 从文件in.txt中输入100个家庭的信息，结果输出到out.txt
	ifstream OpenFile(".\\电量统计in&out\\in.txt");
	ofstream SaveFile(".\\电量统计in&out\\new_out.txt");
	for(int i=0;i<100;i++){
		OpenFile >> name;
		for(int j=0;j<12;j++){
			OpenFile >> m[j];
		}
		FamilyElecPower nfep(name,m);
		SaveFile << setw(10) << nfep.GetName() ;
		SaveFile << " 年总电量：" << setw(15) << CalTotalEPower(nfep);
		SaveFile << " 月均电量：" << setw(15) << setprecision(5) << CalAveEPower(nfep) << endl;
	}
	return 0;
}
