// 口袋中有红、黄、蓝、白、黑5种颜色的球若干个。
// 每次从口袋中取出3个不同颜色的球，问有多少种取法？
// 请输出这些取法。
// （建议使用枚举型完成）
#include <iostream>
using namespace std;
int main(void){
    int ball[5]={0,1,2,3,4}; // 用数字代替五种颜色的小球
    int first_ball,second_ball,third_ball,i,j,k;
    int num = 0; // 记录有几种取法

    // 首先通过三重循环找到三个球first_ball,second_ball,third_ball
    for(i=0;i<5;i++){
        if(i == 3) break;
        first_ball = ball[i];

        for(j=i+1;j<5;j++){
            second_ball = ball[j];

            for(k=j+1;k<5;k++){
                third_ball = ball[k];
                num ++;

                // 找到三个球之后，输出三个球
                if(first_ball == 0) cout << "红球、";
                if(first_ball == 1) cout << "黄球、";
                if(first_ball == 2) cout << "蓝球、";
                if(first_ball == 3) cout << "白球、";
                if(first_ball == 4) cout << "黑球、";

                if(second_ball == 1) cout << "黄球、";
                if(second_ball == 2) cout << "蓝球、";
                if(second_ball == 3) cout << "白球、";
                if(second_ball == 4) cout << "黑球、";

                if(third_ball == 2) cout << "蓝球" << endl;
                if(third_ball == 3) cout << "白球" << endl;
                if(third_ball == 4) cout << "黑球" << endl;

            }
        }
    }
    cout << "共有" << num << "种取法。" << endl;
}

// 学习小结：
// 1. 枚举类型enum
//  ·enum 枚举类型名 {变量值列表}；
//      如：enum Weekday {MON,TUE,WED,THU,FRI};
//  ·枚举元素按常量处理，不能对它们赋值。如，不能写MON = 0;
//   但是可以在声明时另外指定枚举元素的值，如：
//   enum Weekday{MON=7,TUE=3,WED,THU,FRI};
//  ·枚举元素有默认值，依次为：0，1，2...
//  ·enum 的使用：
//  
// #include <iostream>
// using namespace std;
// enum game_result { WIN, LOSE, TIE, CANCEL };//定义：在main函数之前，namespace之后
// int main(void)
// {   game_result result;
//     enum game_result omit = CANCEL;// 定义其中CANCEL这种情况为omit
//     int count;
//     for (count = WIN; count <= CANCEL; count++) //枚举元素都看作常量使用
//     {   result = (game_result)count; // int转enum：显式强制类型转换
//     
//         if (result == omit)
//         {   cout << "The game was cancelled\n";
//         }
//         else
//         {   cout << "The game was played ";
//             if (result == WIN)    cout << "and we won!";
//             if (result == LOSE)   cout << "and we lost.";
//             cout << "\n";    // 如果直接输出result，会输出数字，而不会输出枚举类型中的字符串。可以定义一个字符串数组
//         }
//     }
//     return 0;
// }
//  · int 转成enum 型要显式转换，enum转成int型可以不用加强制转换的括号直接转换

// 2. 字符串数组
//  string ball_str[5] = {"red ","yellow ","blue ","white ","black "};
//  cout << ball_str[0];
//  会输出 red
// 3. 
// 4. 
// 5. 