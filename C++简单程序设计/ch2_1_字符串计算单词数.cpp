// 字符串：输入任意一段文字，输入任意一个单词，
// 计算该单词在该文字中的个数。
// 以文字：
// “Beijing is the capital of the P.R.C. It locates in the arms of the North China Plain, and lies at the feet of the Yanshan Mountains.”
// 和单词”the”为例：

// 输入输出：
// 请输入字符串：
// Beijing is the capital of the P.R.C. It locates in the arms of the North China Plain, and lies at the feet of the Yanshan Mountains.
// 请输入单词：
// the
// 你输入的内容是：
// Beijing is the capital of the P.R.C. It locates in the arms of the North China Plain, and lies at the feet of the Yanshan Mountains.
// 其中”the”有6个.
// press any key to continue….
#include <iostream>
#include <string>
using namespace std;
int main(){
	string s,word;
	int index,num;
	num = 0;

	// 输入输出
	cout << "请输入字符串：" << endl;
	getline(cin,s);
	cout << "请输入单词：";
	cin >> word;

	//
	while((index = s.find(word)) != string::npos){

		s.erase(index,3);
		num ++;
	}
	cout << "其中“" << word << "”有" << num << "个";
	return 0;
}

// 学习小结：
// 1. getline()函数：用于接收字符串
// 	·cin.getline(char* s,n,d)
// 		s：存放的位置
// 		n: 读取n个字符。
// 		d: 如果没有读够n个字符就遇到了字符（串）d，则读取终止。
// 		   字符d默认为'\n'。（d不会被保存到字符数组中）
// 	·getline(cin,s)或getline(cin,s,d)
// 		cin: 读入
// 		s：存放的位置
// 		d：同上
// 2. str.find()函数：用于在字符串中查找子字符串
// 	·str.find(word)
// 		str：字符串
// 		word：查找的子字符串
// 	注意：
// 		·str.find(word)返回值是找到的word在str中第一个字符的下标
// 		·当str.find(word)返回值为string::npos时表示已查找到字符串末尾
// 		·用该函数需要使用头文件#include<string>
// 3. str.erase()函数：用于在字符串中删除子字符串
// 	·str.erase(i,n)
// 		i:str中要删除的字符串的开始下标
// 		n：str中要删除的字符串的长度
// 	4. main函数中要记得return 0；
