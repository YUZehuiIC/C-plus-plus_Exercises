// 二、冒泡排序函数模板
// 主程序测试整型数组、字符数组、字符串数组的排序
#include <iostream>
using namespace std;
template <typename T>
void BubbleSort (T* array,int len){	// len表示数组array有len个数
	T temp;// int* temp;

	for(int i=len-1;i>0;i--){ // 取前i+1(即len)个数进行顺序排序,最大的排在array[i]
		for(int j=0;j<i;j++){
			if(array[j] > array[j+1]){	// 把大的排在右边(实现从小到大排序)
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	for(int i=0;i<len;i++){
        cout << array[i] << " ";
	}
    cout << endl;
}
int main(){
	// 测试整型数组的排序
	int intArray[]= {8,6,7,2,5};
	BubbleSort(intArray,5);

	// 测试字符数组的排序
	char charArray[] = {'b','a','d','c','e'};
	BubbleSort(charArray,5);

	// 测试字符串数组的排序
	string stringArray[] = {"acd","ade","abc"};
	BubbleSort(stringArray,3);
}
