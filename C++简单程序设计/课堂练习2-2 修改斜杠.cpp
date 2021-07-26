// 201611210222虞泽慧
// 第二次课堂作业：请将路径“c:/program files/microsoft/vs2015”中的斜杠“/”替换为反斜杠“\”.
#include <iostream>
#include <string>
using namespace std;
int main(void){
    string s;
    int position;

    // 改成反斜杠
    s = "c:/program files/microsoft/vs2015";
    while(1){
        if(s.find("/") == string::npos)
            break;
        else
            s.replace(s.find("/"),1,"\\");
    }
    cout << s << endl;

    // 删掉斜杠
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
