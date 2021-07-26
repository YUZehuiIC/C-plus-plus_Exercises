#include<iostream>
#include<windows.h>
using namespace std;
POINT pt[]={
    0, 450,
    225,390,
    390,225,
    450,0,
    390,-225,
    225,-390,
    0,-450,
    -225,-390,
    -390,-225,
    -450,0,
    -390,225,
    -225,390
};
void SetIsotropic(HDC hdc, int cx, int cy){
    ::SetMapMode(hdc, MM_ISOTROPIC); //设置坐标映射方式
    ::SetWindowExtEx(hdc, 1000, 1000, NULL); //设置坐标系的逻辑单位
    ::SetViewportExtEx(hdc, cx, -cy, NULL); //设置坐标系方向和坐标系包含的范围，即定义域和值域
    ::SetViewportOrgEx(hdc, cx/2, cy/2, NULL); //设置坐标系原点坐标}
class Clock{
    public:
        Clock(short h=0,short m=0,short s=0):h(h),m(m),s(s){}
        void displayTime();
    private:
        short h;
        short m;
        short s;
};
void Clock::displayTime(){
    while(true){
        cout<<h<<':'<<m<<':'<<s<<"   ";
        Sleep(1000);
        cout<<'\r';
        if(!(s=++s%60))
            if(!(m=++m%60))
                h=++h%24;
    }
}
int main()
{
    Clock A(23,59,55);
    A.displayTime();
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        // TODO: 在此添加任意绘图代码...
        //画钟表盘
        int cxClient, cyClient;
        RECT rect;
        ::GetClientRect(hWnd, &rect);
        cxClient = rect.right - rect.left;
        cyClient = rect.bottom - rect.top;

        SetIsotropic(hdc, cxClient, cyClient);

#define  SQUARESIZE 10
        ::SelectObject(hdc, ::GetStockObject(BLACK_BRUSH));
        for(int i=0;i<12;i++)
        {
            ::Ellipse(hdc, pt[i].x-SQUARESIZE,pt[i].y+SQUARESIZE,pt[i].x+SQUARESIZE, pt[i].y-SQUARESIZE);
        }

        EndPaint(hWnd, &ps);
        break;
        return 0;
}
