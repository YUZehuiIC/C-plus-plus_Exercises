// 201611210222虞泽慧
// 第一次课堂作业：比较auto和static变量
#include <iostream>
using namespace std;
void fun()
{   int i(3);
     static int j(3);
     i++;
     j--;
     cout<<"i="<<i<<"\t"<<"j="<<j<<endl;
}
int main()
{   int i(0);
     static int j(0);
     i++;
     j--;
     cout<<"i="<<i<<"\t"<<"j="<<j<<endl;
     fun();
     cout<<"****************\n";
     i++;
     j--;
    cout<<"i="<<i<<"\t"<<"j="<<j<<endl;
    fun();
    return 0;
}
