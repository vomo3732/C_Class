﻿// CTestDLG.cpp: 구현 파일
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
