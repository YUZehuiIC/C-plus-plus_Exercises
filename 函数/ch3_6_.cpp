// 6.typedef struct Student
// {	string department;		//系别
// 		char gender;			//性别: 男-‘m’,女-‘f’
// 		int num;				//学号
// 		string name;			//姓名
// } STUDENT;
// 请设计输入函数STUDENT InputStudent(int num1,string de,string name1,char g);
// 其中，系别的默认值是”Computer”, 性别的默认值是’m’ ，学号的默认值是2017001，姓名的默认值是”XXX”.
// 	在主程序中，定义学生数组STUD
//
// 	ENT stu[6];  然后输入以下6名同学的信息：
// 	Computer		m	2017001	王伟
// 	Mathematics		f	2017012	刘海华
// 	Computer		m	2017003	赵天瑞
// 	Physical		m	2016085	胡文明
// 	Computer		f	2017009	于冬梅
// 	Computer		m	2016007	岳海山
#include <iostream>
#include <iomanip>
using namespace std;
typedef struct Student
{	string department = "Computer";		//系别
	char gender = 'm';			//性别: 男-‘m’,女-‘f’
	int num = 2017001;				//学号
	string name = "XXX";			//姓名
} STUDENT;
int main(){
	STUDENT stud[6];
	int i;

	stud[0].name = "王伟";

	stud[1].department = "Mathematics";
	stud[1].gender = 'f';
	stud[1].num = 2017012;
	stud[1].name = "刘海华";

	stud[2].num = 2017003;
	stud[2].name = "赵天瑞";

	stud[3].department = "Physical";
	stud[3].num = 2016085;
	stud[3].name = "胡文明";

	stud[4].gender = 'f';
	stud[4].num = 2017009;
	stud[4].name = "于冬梅";

	stud[5].num = 2016007;
	stud[5].name = "岳海山";

	cout << "学生信息" << endl;
	for(i=0;i<6;i++){
		cout << setw(15) << stud[i].department << setw(15) << stud[i].gender
		 << setw(15) << stud[i].num << setw(15) << stud[i].name << endl;
	}
}

// 学习小结：
// 1.结构体
//
// 		//定义一个结构体，类型为struct Student
// 		struct  Student
//  	{
// 	    string name;
// 	    double eng;
//  	    double ch;
//  	};

//  	//定义了一个结构体，类型为struct Student；且定义了一个结构体实例，名叫Stu
// 		struct  Student
// 	 	{
// 	    string name;
//  	    double eng;
// 	    double ch;
//  	}Stu;

// 	    //定义了无名的结构体，且定义了一个结构体实例，名叫Stu
//  	struct
//  	{
//  	  string name;
//  	  double eng;
// 	      double ch;
// 		}Stu;

//  	//重定义结构体，类型为struct Student 或者是Stu
//  	typedef struct  Student
//  	{
//  	    string name;
//  	    double eng;
//  	    double ch;
//  	}Stu;

// 		//重定义结构体，类型为Stu
//  	typedef struct
//  	{
// 	    string name;
//  	    double eng;
//  	    double ch;
//  	}Stu;	

// 	如果用typedef则，Stu stu;
// 	否则，struct Student stu;
// 
// 2.typedef语句：用于为一个已有的数据类型另外命名
// 	· typedef 已有类型名 新类型名表