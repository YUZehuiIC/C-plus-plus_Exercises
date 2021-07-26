#include<iostream>
#include<string>
using namespace std;
string instr;
string key = "ilikecplusplus";
void cipertext(int len_instr);

int main(){
    cout << "请输入需要加密的字符串：";
    getline(cin,instr);
    int n = instr.length();
    cipertext(n);
    cout << instr << endl;
	return 0;
}
void cipertext(int len_instr){
    int i,k,len_key;
    len_key = key.length();

    cout << "cipertext:";
	for(i=0;i<len_instr;i++){
        for(k=0;k<len_key;k++)
            {instr[i] = instr[i]^key[k];
           }
	}

}
