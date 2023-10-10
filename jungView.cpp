
// jungView.cpp: CjungView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "jung.h"
#endif

#include "jungDoc.h"
#include "jungView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CjungView

IMPLEMENT_DYNCREATE(CjungView, CFormView)

BEGIN_MESSAGE_MAP(CjungView, CFormView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFormView::OnFilePrintPreview)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN1, &CjungView::OnDeltaposSpin1)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_SELECT_COLOR, &CjungView::OnSelectColor)
END_MESSAGE_MAP()

// CjungView 생성/소멸

CjungView::CjungView() noexcept
	: CFormView(IDD_JUNG_FORM)
	, m_B(_T(""))
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CjungView::~CjungView()
{
}

void CjungView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SPIN1, m_Spin);
	DDX_Control(pDX, IDC_EDIT1, m_S);
	DDX_Text(pDX, IDC_EDIT1, m_B);
}

BOOL CjungView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CFormView::PreCreateWindow(cs);
}

void CjungView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CjungView 인쇄

BOOL CjungView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CjungView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CjungView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CjungView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: 여기에 사용자 지정 인쇄 코드를 추가합니다.
}


// CjungView 진단

#ifdef _DEBUG
void CjungView::AssertValid() const
{
	CFormView::AssertValid();
}

void CjungView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CjungDoc* CjungView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CjungDoc)));
	return (CjungDoc*)m_pDocument;
}
#endif //_DEBUG


// CjungView 메시지 처리기


void CjungView::OnDeltaposSpin1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMUPDOWN pNMUpDown = reinterpret_cast<LPNMUPDOWN>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void CjungView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	
	
}

//계산기 만들기 팬 만들기 중간


COLORREF Col;
CPoint opnt;
void CjungView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CClientDC dc(this);
	UpdateData(true);
	int n = GetDlgItemInt(IDC_EDIT1);
	CPen pen(PS_SOLID, n, Col);
	dc.SelectObject(&pen);
	if (nFlags & MK_LBUTTON) {
		dc.MoveTo(opnt);
		dc.LineTo(point);
	}
	opnt = point;
	CFormView::OnMouseMove(nFlags, point);
}


void CjungView::OnSelectColor()
{
	CColorDialog dlg;
	if (dlg.DoModal() == IDOK) {
		Col = dlg.GetColor();
	}
}


