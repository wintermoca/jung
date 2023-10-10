
// jungView.h: CjungView 클래스의 인터페이스
//

#pragma once


class CjungView : public CFormView
{
protected: // serialization에서만 만들어집니다.
	CjungView() noexcept;
	DECLARE_DYNCREATE(CjungView)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_JUNG_FORM };
#endif

// 특성입니다.
public:
	CjungDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CjungView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	CSpinButtonCtrl m_Spin;
	CEdit m_S;
	afx_msg void OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult);
	CString m_B;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSelectColor();
	afx_msg void OnColorRed();
};

#ifndef _DEBUG  // jungView.cpp의 디버그 버전
inline CjungDoc* CjungView::GetDocument() const
   { return reinterpret_cast<CjungDoc*>(m_pDocument); }
#endif

