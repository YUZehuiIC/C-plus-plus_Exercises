// 4.定义、实现并测试一个双向链表结点类DNode。
// 链表结点类中包含私有数据成员为两个整数x，y，以及左结点指针left及右结点指针right。
// 包含的函数成员包括：
// (a)构造函数DNode(int xx=0,int yy=0,DNode* templeft=NULL,DNode* tempright=NULL);
// (b)对结点的数据成员赋值setDNodeValues(int,int);
// (c)链表左插入结点void insertLeft()；		
// (d)链表右插入结点void insertRight();			
// (e)删除结点void deleteNode();				
// (f)获取左侧相邻节点地址DNode* nextNodeLeft(); 
// (g)获取右侧相邻节点的地址DNode* nextNodeRight();
// (h)结点数据输出printNode();
// 编写主程序：
// 	至少输入3组整数（x, y）, 分别利用左侧和右侧插入结点函数组织数据为双向链表，
// 	测试输出链表中每个结点的左侧和右侧相邻节点内容，测试对“指定”结点的删除。
#include <iostream>
using namespace std;
class DNode{
private:
	int x,y,*left,*right;
public:
	DNode(int xx=0,int yy=0,DNode* templeft=NULL,DNode* tempright=NULL){}
	void setDNodeValues(int,int);
	void insertLeft();
	void insertRight();
	void deleteNode();
	DNode* nextNodeLeft();
	
};
int main(){

}