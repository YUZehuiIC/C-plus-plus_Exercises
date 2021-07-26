// 2. （类的组合）设计人类（Person），包含姓名、生日、性别三种数据。其中生日是日期类（Date）的数据。
// 人类：

// private：
// 姓名
// 生日			//是日期类的对象
// 性别
// public:
// 有参构造函数Person(char* name, int year, int month, int day, char gender); //要有输出
// 析构函数;	//要有输出
// 设置姓名函数void SetName(char* name);
// 设置生日函数void SetBirthday(int y, int m, int d);
// 获得姓名函数char* GetName();
// 获得生日函数Date GetBirthday();
// 输出信息函数void Show(); 		 //此函数输出人的所有信息


// 日期类：
// private:
// 年
// 月
// 日
// public:
// 有参构造函数 Date(int y, int m, int d);		//要有输出
// 析构函数;								//要有输出
// 设置日期函数SetDate(int y, int m, int d);	
// 显示日期函数 void Show();			//输出日期值


// 主程序功能简介：
// 1.用户输入姓名、出生年、月、日、性别的信息
// 2.构造人类的对象A
// 3.显示该对象A
// 4.更改A的姓名
// 5.更改A的生日
// 6.重新显示A对象