// clockView.h : interface of the CClockView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLOCKVIEW_H__7DA7FD5A_A7A3_48C0_8A30_2787C24504A4__INCLUDED_)
#define AFX_CLOCKVIEW_H__7DA7FD5A_A7A3_48C0_8A30_2787C24504A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CClockView : public CView
{
protected: // create from serialization only
	CClockView();
	DECLARE_DYNCREATE(CClockView)

// Attributes
public:
	CClockDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClockView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CClockView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CClockView)
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in clockView.cpp
inline CClockDoc* CClockView::GetDocument()
   { return (CClockDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLOCKVIEW_H__7DA7FD5A_A7A3_48C0_8A30_2787C24504A4__INCLUDED_)
