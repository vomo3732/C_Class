#### 03/15
MFC 앱 환경에서의 dialog 설정과 값 입출력을 받는 법, 폰트 크기 변경법에 대한 내용
```
// CTestDLG.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication1.h"
#include "CTestDLG.h"
#include "afxdialogex.h"
#include "string.h"


// CTestDLG 대화 상자

IMPLEMENT_DYNAMIC(CTestDLG, CDialogEx)

CTestDLG::CTestDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_Test1, pParent)
{

}

CTestDLG::~CTestDLG()
{
}

void CTestDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_Text1, cStaticTest);
	DDX_Control(pDX, IDC_BUTTON1, BUTTON_VAR);
	DDX_Control(pDX, IDC_EDIT2, m_EditIn);
	DDX_Control(pDX, IDC_EDIT3, m_EditOut1);
	DDX_Control(pDX, IDC_EDIT4, m_EditOut2);
}


BEGIN_MESSAGE_MAP(CTestDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CTestDLG::OnBnClickedButton1)
END_MESSAGE_MAP()


// CTestDLG 메시지 처리기
//Item1에 소문자 입력 Button1을 누르면 대문자로 변환해서 Item2에 출력 Item3에는 그 갯수를 출력....
//Button 눌렸을 때의 함수를 정의하는 것.,...


BOOL CTestDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CFont f;
	f.CreateFontW(36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Arial"));
	//글씨크기 36, Arial체로 출력하기
//	GetDlgItem(IDC_STATIC_Text1)->SetWindowTextW(L"안녕하세요. 반갑습니다.");
//	GetDlgItem(IDC_STATIC_Text1)->SetFont(&f);
	cStaticTest.SetFont(&f);
	cStaticTest.SetWindowTextW(L"안녕하세요. 반갑습니다.");

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CTestDLG::OnBnClickedButton1()
{
	CString str;
	//변수를 선언하지 않고 진행하기
//	GetDlgItem(IDC_EDIT2)->GetWindowTextW(str);
//	GetDlgItem(IDC_EDIT3)->SetWindowTextW(str.MakeUpper());
//	int n = str.GetLength();
//	CString s;
//	s.Format(L"%d", n);
//	GetDlgItem(IDC_EDIT4)->SetWindowTextW(s);
//	대문자로 바꾸는 작업은 str.MakeUpper()함수를 이용한다. 이때 대문자로 바꾼 문자열을 반환하는 것이며 원본은 변하지 않는다.


//	변수를 선언해서 진행하기
	m_EditIn.GetWindowTextW(str);
	m_EditOut1.SetWindowTextW(str.MakeUpper());
	int n = str.GetLength();
	CString s;
	s.Format(L"%d", n);
	m_EditOut2.SetWindowTextW(s);


}
```

#### 03/16
MFC를 활용하여 마우스가 위치한 좌표에 따라 원 그리기 (파일읽어오기-CDlgRev.cpp, CDlgTest.cpp)

```
// CDrawTest.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication3.h"
#include "CDrawTest.h"
#include "afxdialogex.h"


// CDrawTest 대화 상자

IMPLEMENT_DYNAMIC(CDrawTest, CDialogEx)

CDrawTest::CDrawTest(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_DrawTest, pParent)
{

}

CDrawTest::~CDrawTest()
{
}

void CDrawTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDrawTest, CDialogEx)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CDrawTest 메시지 처리기

CStatic* pD;
CDC* PDC;

BOOL CDrawTest::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	pD = (CStatic*)GetDlgItem(IDC_PNL_DRAW);
	PDC = GetDC();		//Device Context Pointer

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CDrawTest::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int r = 100;//반지름 100

	PDC->Ellipse(point.x-r, point.y-r, point.x+r, point.y+r);


	CDialogEx::OnLButtonDown(nFlags, point);
}
```

메인 소스코드에서의 처리(MFCApplication3.cpp)
```
#include "CDrawTest.h"
void CMFCApplication3App::OnMnuDraw()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CDrawTest* dlg = new CDrawTest();
	dlg->DoModal();

}

```
