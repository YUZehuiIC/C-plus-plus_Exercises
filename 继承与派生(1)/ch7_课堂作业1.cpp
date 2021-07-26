/*------------------------------------------------------
【程序改错】
--------------------------------------------------------

题目:A类为基类，B类、C类继承A类，D类继承B类，C类。继承都为
     公有继承。程序运行结果为：
         class A
         class B
         class C
         class D
         class D

--------------------------------------------------------
注意：不可以增加或删除程序行，也不可以更改程序的结构。
      仅修正改错标记FOUND之下的那行内容，不允许删除FOUND行
------------------------------------------------------*/
#include <iostream>
using namespace std;
class A
{public:
   A(char *s){cout<<s<<endl;}
/***********FOUND***********/
};
class B:public A
{public:
   B(char *s1,char *s2):A(s1)
   {  cout<<s2<<endl;
   }
};
class C:public A
{public:
   C(char *s1,char *s2):A(s1)
   {  cout<<s2<<endl;
   }
};
class D:public B,C
{/***********FOUND***********/
public:
/***********FOUND***********/
   D(char *s1,char *s2,char *s3,char *s4):B(s1,s2),C(s3,s4)
   {  cout<<s4<<endl;
   }
};
int main()
{/***********FOUND***********/

   D d("class A","class B","class C","class D");
   return 0;
}
