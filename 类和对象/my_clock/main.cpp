#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"
#include <iostream>
using namespace std;
class  Clock{
	private:
   		int Hour, Minute, Second;
 	public:
   		void SetTime (int NewH, int NewM, int NewS);	//设置初始时间
   		void Tick(int TestMinute);	//走秒
   		void ShowTime();	// 显示初始时间
   		int GetHour(){int n; GetDlgItemText(IDC_EDIT1,n); return n;}	// 获取初始小时数
   		int GetMinute(){int n; GetDlgItemText(IDC_EDIT2,n); return n;}	// 获取初始分钟数
   		int GetSecond(){int n; GetDlgItemText(IDC_EDIT3,n); return n;}	// 获取初始秒数
   		int GetTestMinute(){int n; GetDlgItemText(IDC_EDIT4,n); return n;} // 获取测试时长
 };
 void Clock::SetTime(int NewH,int NewM,int NewS){
    // 这里读入的第一个参数一定是Second,第二个是Minute,第三个是Hour，不知道为什么
	Hour = NewH;
	Minute = NewM;
	Second = NewS;
}
void Clock::Tick(int TestMinute){
	int TestSecond,i;
	string outstr;
	TestSecond = TestMinute * 60;
	for(i=0;i<TestSecond;i++){
        // 设置走秒
		if(!(Second = ++Second%60))
			if(!(Minute = ++Minute%60))
				Hour = ++Hour%24;
        sprintf(outstr,"%02d:%02d:%02d",Hour,Minute,Second);
        Sleep(1000); // 定时1s
        GetDlgItem(IDC_EDIT5)->SetWindowText(outstr));
        UpdateData(FALSE);
	}
}


HINSTANCE hInst;
HWND button1; // 声明句柄
HWND button2;
HANDLE hOut =  GetStdHandle(STD_OUTPUT_HANDLE); // 得到窗口句柄
Clock my_clock;

/* 窗口回调函数，一旦有事情响应，系统就会调用该函数 */
BOOL CALLBACK DlgMain(HWND hwndDlg, // 窗口句柄，32位无符号整数
                      UINT uMsg,  //消息类型
                      WPARAM wParam, // wParam和lParam这两个是具体的事件信息
                      LPARAM lParam)
{

    switch(uMsg)
    {
    case WM_INITDIALOG: // 窗口被初始化时被引发的时间
    {
        button1 = GetDlgItem(hwndDlg,IDC_BUTTON1); // 在初始化后获得句柄，windows中一切控件都是窗口
        button2 = GetDlgItem(hwndDlg,IDC_BUTTON2);
    }
    return TRUE;

    case WM_CLOSE: // 窗口被关闭时的时间，即点击了“x”
    {
        if(MessageBox(hwndDlg,"关闭窗口？","提示",MB_YESNO) == IDYES)
        {
            EndDialog(hwndDlg, 0); // 如果选择是，就关闭窗口
        }
    }
    return TRUE;

    case WM_COMMAND: // 单击事件，就是触发按钮的时间，就是这个
    {
        switch(LOWORD(wParam))
        {

        case IDC_BUTTON1: // IDC_BUTTON1在resource.h里有自动的宏定义
            my_clock.SetTime(my_clock.GetHour(),my_clock.GetMinute(),my_clock.GetSecond());
            my_clock.Tick(my_clock.GetTestMinute());
            // SetWindowText(button1,TEXT("我的按钮")); // 设置点击按钮后按钮的标题
            break;
        case IDC_BUTTON2:
            IDC_EDIT1.SetWindowText("");
            IDC_EDIT2.SetWindowText("");
            IDC_EDIT3.SetWindowText("");
            IDC_EDIT4.SetWindowText("");
            break;
        }
    }
    return TRUE;
    }
    return FALSE;
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();

    return DialogBox(hInst, MAKEINTRESOURCE(myclock), NULL, (DLGPROC)DlgMain);
}
