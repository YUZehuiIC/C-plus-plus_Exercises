// 1.一个表示分数的数据类型，它能以2/3这样的格式输出或输入，
// 	能完成分数的加、减、乘、除等运算。
// 　一个Fraction分数须满足以下两个条件：
// 　　①分母永远为正，分数的符号用分子表示；
// 　　②分子分母互质，即总表示为最简分数。
// 　说明：
// 数据成员： fraction通过两个私有数据成员int 型num和den分别保存分子和分母；
// 成员函数：
// (a)构造函数Fraction（int n=0，int d=1）；
// (b) Standardize函数进行标准化处理，例如：2/4 = 1/2 ， 2/-3 = -2/3 ；
// (c)GCD是求两个整数的最大公约数的函数，standardize在化简分数时要调用它；
// (d)void Set(int,int); 为分数的分子、分母赋值；
// (e)void Display(); 输出分数，如输出1/2 ；
// (f)Fraction Add(Fraction x) 求当前对象和x的和；
// (g)Fraction Sub(Fraction) 求当前对象和x的差；
// (h)Fraction Mul(Fraction) 求当前对象和x的积；
// (i)Fraction Div(Fraction) 求当前对象和x的商，注意x不能为0；
// (j)bool BigOrEqual(Fraction) 比较当前对象和x的大小；
// 	在main函数中，创建至少3个分数，测试加减乘除比较等功能。
#include <iostream>
using namespace std;
class Fraction{
private:
	int num,den; // num是分子，den是分母
public:
	Fraction(int n=0,int d=1){num = n;den = d;}
	// 标准化处理函数
	void Standardize(){
        int gcd = GCD(num,den);
        num = num / gcd;
        den = den / gcd;
	}
	// 求最大公约数
	int GCD(int a ,int b){  return b==0 ? a : GCD(b,a%b);   }
	// 为分数的分子、分母赋值
	void Set(int n,int d){
        num = n;
        den = d;
	}
	//输出分数
	void Display(){
        Standardize(); // 标准化处理
        cout << num << '/' << den << ' ';
	}
    // 求当前对象和x的和
	Fraction Add(Fraction x){
        int n,d;
        n = num*x.den + den*x.num;
        d = den*x.den;
        Fraction newf(n,d);
        newf.Standardize();
        return newf;
	}
	// 求当前对象和x的差
	Fraction Sub(Fraction x){
        int n,d;
        n = num*x.den - den*x.num;
        d = den*x.den;
        Fraction newf(n,d);
        newf.Standardize();
        return newf;
	}
	// 求当前对象和x的积
	Fraction Mul(Fraction x){
		int n,d;
        n = num*x.num;
        d = den*x.den;
        Fraction newf(n,d);
        newf.Standardize();
        return newf;
	}
	// 求当前对象和x的商
	Fraction Div(Fraction x){
        int n,d;
        n = num*x.den;
        d = den*x.num;
        Fraction newf(n,d);
        newf.Standardize();
        return newf;
	}
	// 比较当前对象和x的大小
	bool BigOrEqual(Fraction x){
        if(num*x.den > x.num*den)
            return true;
        else
            return false;
    }
};
int main(){
	Fraction x,y,z;
	int n,d;
	// 获取用户输入的三个分数
	cout << "第一个分数：" << endl;
	cout << "分子：";
	cin >> n;
	cout << "分母：";
	cin >> d;
	x.Set(n,d);

	cout << "第二个分数：" << endl;
	cout << "分子：";
	cin >> n;
	cout << "分母：";
	cin >> d;
	y.Set(n,d);

	cout << "第三个分数：" << endl;
	cout << "分子：";
	cin >> n;
	cout << "分母：";
	cin >> d;
	z.Set(n,d);

	// 输出处理后的三个分数
	cout << "这三个分数依次是：";
	x.Display();
	y.Display();
	z.Display();
    cout << endl;

	// 测试x和y的加减乘除功能
	cout << "第一个分数和第二个分数的和：";
	x.Add(y).Display();
	cout << endl;

	cout << "第一个分数和第二个分数的差：";
	x.Sub(y).Display();
	cout << endl;

	cout << "第一个分数和第二个分数的积：";
	x.Mul(y).Display();
	cout << endl;

	cout << "第一个分数和第二个分数的商：";
	x.Div(y).Display();
    cout << endl;

	// 通过比较大小，对x，y，z进行排序
	cout << "这三个分数从大到小排序后依次是：";
	if(x.BigOrEqual(y)){
		if(y.BigOrEqual(z)){
			x.Display();y.Display();z.Display();
		}
		else{
			if(x.BigOrEqual(z)){
				x.Display();z.Display();y.Display();
			}
			else{
				z.Display();x.Display();y.Display();
			}
		}
	}
	else{
		if(x.BigOrEqual(z)){
			y.Display();x.Display();z.Display();
		}
		else{
			if(y.BigOrEqual(z)){
				y.Display();z.Display();x.Display();
			}
			else{
				z.Display();y.Display();x.Display();
			}
		}
	}

}
