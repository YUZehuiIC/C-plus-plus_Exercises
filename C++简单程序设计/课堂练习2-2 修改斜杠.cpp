// 201611210222�����
// �ڶ��ο�����ҵ���뽫·����c:/program files/microsoft/vs2015���е�б�ܡ�/���滻Ϊ��б�ܡ�\��.
#include <iostream>
#include <string>
using namespace std;
int main(void){
    string s;
    int position;

    // �ĳɷ�б��
    s = "c:/program files/microsoft/vs2015";
    while(1){
        if(s.find("/") == string::npos)
            break;
        else
            s.replace(s.find("/"),1,"\\");
    }
    cout << s << endl;

    // ɾ��б��
    s = "c:/program files/microsoft/vs2015";
    while(1){
        position = s.find("/");
        if(s.find("/") == string::npos)
            break;
        else
            s.erase(position,1);
    }
    cout << s << endl;


    return 0;
}
