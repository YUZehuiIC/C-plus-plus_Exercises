// 2.1 基本要求：
//		教师作为学生的友元类，操作学生的学分和总成绩。
//	2.2 功能设计：
//		（1）设计学生类，包含学生姓名、学分和总成绩；
//		（2）设计教师类，包含教师姓名，教师有权限修改每个学生的学分和总成绩；
//		（3）在以上类中增加合适的成员函数以完成程序的功能；
//		（4）教师类设计成学生类的友元；
//	2.3 主程序中建立1名教师，3名学生，实现教师分别修改3名学生的学分和总成绩的操作。
//	2.4  上机思考题部分：
//主程序和界面要求：
//2.4.1 主程序要求：
//	（1）至少有5名学生，3名教师；
//	（2）用户随意选择一位教师、一名学生，让该教师给该学生增加学分、
//		增加总成绩；
//	（3）程序结束前输出每位学生的姓名、学分、总成绩
//2.4.2 界面要求（输出样例）：
//您需要建立几位学生(M)和几位教师(N)：5 3
//请输入5位学生的姓名：张朋 李元 刘文 贺明 鲁笑
//请输入3位教师的姓名：严华 耿燕 吴晓乐
//请选择一位教师: 吴晓乐
//请选择一位学生：贺明
//请输入要增加的学分：3
//教师吴晓乐给学生贺明增加学分，操作成功。
//请输入要增加的总成绩：88
//教师吴晓乐给学生贺明增加总成绩，操作成功。
//还要继续吗？(Y/N):
//如果用户选择N，则输出每位学生的姓名、学分、总成绩，然后程序结束；
//如果用户选择Y, 则转向步骤：选择教师，程序继续运行。
#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;
class Student{
private:
	string stu_name;
	int score = 0;
	int totalGrade = 0;
public:
	friend class Teacher;
	void SetName(string name){ stu_name = name; }
	string GetName(){return stu_name;}
	bool CompareStuName(string name){
		if(name==stu_name)
			return true;
		else
			return false;
	}
	void show(){
		cout << setw(10) << stu_name
			 << " 学分" << setw(6) << score
			 << " 总成绩" <<setw(4) << totalGrade << endl;
	}
};
class Teacher{
private:
	string tea_name;
public:
	void SetName(string name){ tea_name = name; }
	string GetName(){return tea_name;}
	bool CompareTeaName(string name){
		if(name==tea_name)
			return true;
		else
			return false;
	}
	void addScore(int n,Student& stu){stu.score += n;}
	void addTotalGrade(int n,Student& stu){stu.totalGrade += n;}
};
int main(){

	int m,n,flag;
	int add_score,add_total_grade;
	string name;
	char judge;
	cout << "您需要建立几位学生(M)和几位教师(N)：";
	cin >> m >> n;
	Student stu[m],sel_stu;
	Teacher tea[n],sel_tea;
	cout << "请输入" << m << "位学生的姓名：";
	for(int i=0;i<m;i++){
		cin >> name;
		stu[i].SetName(name);
	}
	cout << "请输入" << n << "位教师的姓名：";
	for(int i=0;i<n;i++){
		cin >> name;
		tea[i].SetName(name);
	}
while(1){
	cout << "请选择一位教师：";
	cin >> name;
	for(int i=0;i<n;i++){
		if(tea[i].CompareTeaName(name) == true){
			sel_tea = tea[i];
		}
	}
	cout << "请选择一位学生：";
	cin >> name;
	for(int i=0;i<m;i++){
		if(stu[i].CompareStuName(name) == true){
			sel_stu = stu[i];
			flag = i;
		}
	}
	cout << "请输入要增加的学分：";
	cin >> add_score;
	sel_tea.addScore(add_score,sel_stu);
    cout << "教师" << sel_tea.GetName() << "给学生" << sel_stu.GetName() << "增加总成绩，操作成功。" << endl;
	cout << "请输入要增加的总成绩：";
	cin >> add_total_grade;
	sel_tea.addTotalGrade(add_total_grade,sel_stu);
	cout << "教师" << sel_tea.GetName() << "给学生" << sel_stu.GetName() << "增加总成绩，操作成功。" << endl;
    stu[flag] = sel_stu;

	cout << "还要继续吗？(Y/N)";
	cin >> judge;
	if(judge=='N'){
		for(int i=0;i<m;i++){
			stu[i].show();
		}
		break;
	}
}
	return 0;
}

// 代码反思：
// 1.中途将选出的学生对象stu[i]赋给了sel_stu，然后改变了sel_stu的变量值，
// 却没有改变stu[i]，而最后输出所有学生的成绩时是直接输出stu数组，
// 因此数据没有发生改变
// 
