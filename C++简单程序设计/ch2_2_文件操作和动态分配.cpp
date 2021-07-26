// 文件操作和动态内存分配：
// 文件in.txt中存储着3个整数数组，存储格式是：
// 先存储数据个数n，接着存储n个整数。
// 请设计程序，对这3个数组按照升序排序。
// 排序后的结果存入文件out.txt中，还是按照输入时的格式存储。
// in.txt内容：
// 5 99 0 -23 87 3
// 10 0 120 -56 35 24 -15 -3 86 11 212
// 8 77 9 18 35 -4 0 -78 26
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
    int n;
    int min_index,min_data,k,temp,i,j,a[1000];// 每一个数组的第一个数，即数据个数n
    char x;
	ifstream OpenFile("in.txt"); // 打开文件in.txt
	ofstream SaveFile("out.txt"); // 新建文件out.txt
	for(i=0;i<3;i++){
        OpenFile >> n;
        cout << n;
        // 读取每一个数组的数据
        for(j=0;j<n;j++){
            OpenFile >> a[j];
        }

        // 对每一个数据的数据进行升序排序
        for(j=0;j<n;j++){
            min_data = a[j];
            min_index = j;

            for(k=j;k<10;k++){
                if(a[k] < min_data){
                    min_data = a[k];
                    min_index = k;
                }
            }

            temp = a[j];
            a[j] = min_data;
            a[min_index] = temp;
        }

        // 将数据进行格式化输入out.txt
        SaveFile << n << " ";
        for(j=0;j<n;j++){
            SaveFile << a[j];

            // 控制每个数据后面的字符（空格或换行）
            if (j < n-1)    SaveFile << " ";
            else    SaveFile << endl;
        }


	}
}

// 学习小结：
// 1. 文件的输入输出：
//    ·头文件#include<fstream>
//    ·打开文件：ifstream OpenFile(*.txt)
//              OpenFile:所打开文件的标识符名称
//              (*.txt)：括号里是文件路径（未必是.txt文件）
//    ·存入文件：ofsteam SaveFile(*.txt)
//              SaveFile:所要保存内容的文件的标识符名称，若不存在此文件就自动创建
//              (*.txt)：要保存的文件路径
//    ·从打开的文件中读取数据：
//      OpenFile >> ch;
//          ch：一个字符。读取数据时按照字符的长度来读取。
//      注意：
//          ·
// 2. 动态分配关键字new
//      ·new和delete并不是函数，而是运算符
//      ·使用new申请内存空间可以是一个单元或一组单元
//      如： char* char_ptr = new char;
//           int* int_array = new int[20];
//           delete char_ptr;
//           delete[] int;
// 3. 
// 4. 