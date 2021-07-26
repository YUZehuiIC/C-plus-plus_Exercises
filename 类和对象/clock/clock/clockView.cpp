// clockView.cpp : implementation of the CClockView class
//

#include "stdafx.h"
#include "clock.h"
#include  "math.h"
#include "clockDoc.h"
#include "clockView.h"
#include "Afxwin.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClockView

IMPLEMENT_DYNCREATE(CClockView, CView)

BEGIN_MESSAGE_MAP(CClockView, CView)
	//{{AFX_MSG_MAP(CClockView)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClockView construction/destruction

CClockView::CClockView()
{
	// TODO: add construction code here

}

CClockView::~CClockView()
{
}

BOOL CClockView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CClockView drawing


void CClockView::OnDraw(CDC* pDC)
{
	CClockDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CBitmap bg;
	bg.LoadBitmap(IDB_BITMAP1);
	CDC dc;
	dc.CreateCompatibleDC(pDC);
	dc.SelectObject(bg);
	pDC->BitBlt(0,0,400,400,&dc,0,0,SRCCOPY);


	CTime tm; 
	tm=CTime::GetCurrentTime();
    //得到系统的时分秒
    int i=tm.GetMinute()-1;//60
	int j=tm.GetHour();//24
	int n=tm.GetSecond();//60
   /*
	CString str;
	str.Format("%d:%d",j,i);
	MessageBox(str);*/
	//24 60
	float   min=(float)(i-14)/60*2*3.1415;

	float   hour=(float)(j-3)/12*2*3.1415; // 角度

	float   sec=(float)(n-14)/60*2*3.1415;


	//原点位置
    int  org_x=200;
	int  org_y=200;
	//时针
	int  hour_ar=90;//长度
   

	int  h_x=hour_ar*cos(hour)+200;
	int  h_y=hour_ar*sin(hour)+200;

	//分针
	int  min_ar=140;//长度

	int  m_x=min_ar*cos(min)+200;
	int  m_y=min_ar*sin(min)+200;

	//秒针
	int  sec_ar=170;//长度
	
	int  s_x=sec_ar*cos(sec)+200;
	int  s_y=sec_ar*sin(sec)+200;
  

    CPen p1(PS_SOLID,4,RGB(100,100,100));
	CPen *penOld=(CPen*)pDC->SelectObject(p1);
	pDC->MoveTo(org_x,org_y);
	pDC->LineTo(m_x,m_y);
	
    CPen p2(PS_SOLID,3,RGB(200,100,100));
	pDC->SelectObject(p2);
	pDC->MoveTo(org_x,org_y);
	pDC->LineTo(h_x,h_y);

    CPen p3(PS_SOLID,2,RGB(150,100,100));
	pDC->SelectObject(p3);
	pDC->MoveTo(org_x,org_y);
	pDC->LineTo(s_x,s_y);

	SetTimer(1,1000,NULL);

}
void CClockView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	this->RedrawWindow();
	CView::OnTimer(nIDEvent);
}

/////////////////////////////////////////////////////////////////////////////
// CClockView printing

BOOL CClockView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CClockView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CClockView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CClockView diagnostics

#ifdef _DEBUG
void CClockView::AssertValid() const
{
	CView::AssertValid();
}

void CClockView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CClockDoc* CClockView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CClockDoc)));
	return (CClockDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CClockView message handlers

