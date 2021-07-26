/*------------------------------------------------------
【程序填空】
--------------------------------------------------------

题目:Country类为基类，Province类继承Country类，City类继承Province类。继承都为
公有继承。程序运行结果为：
The People's Republic of China
Jiangsu
Nanjing

--------------------------------------------------------
注意：不可以增加或删除程序行，也不可以更改程序的结构。
仅在【 】中填入所需的内容
------------------------------------------------------*/
#include <iostream>
#include <cstring>
using namespace std;
class Country
{
	char m_Name[50];
public:
	Country(char * name)
	{  strcpy(m_Name,name);
	}
	void Display()
	{  cout<<m_Name<<endl;
	}
};
class Province: public Country
{
    char m_Name[20];
public:
    Province(char * nameCountry,char * nameProvince) 【:Country(nameCountry)】
    {  strcpy(m_Name,nameProvince);
    }
    void Display()
    {
        【Country::Display();】
        cout<<m_Name<<endl;
    }
};
class City:public Province
{
    char m_Name[20];
public:
    City(char * nameCountry,char * nameProvince,char * nameCity)【:Province(nameCountry,nameProvince)】
    {  strcpy(m_Name,nameCity);
    }
    void Display()
    {
        【Province::Display();】
        cout<<m_Name<<endl;
    }
};

int main( )
{
    City nj("The People's Republic of China","Jiangsu","Nanjing");
    nj.Display();
	return 0;
}
