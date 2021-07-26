#include <iostream>
using namespace std;

class fraction{
  int num;
  int den;
  void standardize();
public:
  fraction(int n=0,int d=1);
  friend fraction add(fraction,fraction);
  friend fraction sub(fraction,fraction);
};
fraction add(fraction a,fraction b){
  fraction x;
  x.num=a.num*b.den+a.den*b.num;
  x.den=a.den*b.den;
  x.standardize();
  return x;
}
fraction sub(fraction a,fraction b){
  fraction x;
  x.num=a.num*b.den-a.den*b.num;
  x.den=a.den*b.den;
  x.standardize();
  return x;
}
int main(){
fraction  f1,f2(2,3),f3(4,5),f4;
f1=add(f2,f3);
f4=sub(f2,f3);
return 0;

}

