// CDlgRev.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication3.h"
#include "CDlgRev.h"
#include "afxdialogex.h"
#include "string.h"


// CDlgRev 대화 상자

IMPLEMENT_DYNAMIC(CDlgRev, CDialogEx)

CDlgRev::CDlgRev(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_REV, pParent)
{

}

CDlgRev::~CDlgRev()
{
}

void CDlgRev::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgRev, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_EX1, &CDlgRev::OnBnClickedButtonEx1)
	ON_BN_CLICKED(IDC_BUTTON_EX2, &CDlgRev::OnBnClickedButtonEx2)
	ON_BN_CLICKED(IDC_BUTTON_EX3, &CDlgRev::OnBnClickedButtonEx3)
	ON_BN_CLICKED(IDC_BUTTON_EX4, &CDlgRev::OnBnClickedButtonEx4)
END_MESSAGE_MAP()


// CDlgRev 메시지 처리기

int btnReview = 0;

void CDlgRev::OnBnClickedButtonEx1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//여기에서 테스트 버튼

	CFont f;
	f.CreateFontW(36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Arial"));
	CButton* btn = (CButton*)GetDlgItem(IDC_BUTTON_EX1);
	//글씨크기 36, Arial체로 출력하기
	//GetDlgItem(IDC_EDIT1)->SetWindowTextW(L"안녕하세요. 반갑습니다.");
	//GetDlgItem(IDC_EDIT1)->SetFont(&f);


	if (btnReview == 0) {
		btn->SetWindowTextW(L"버튼 문자열 1");
	}
	else
	{
		btn->SetWindowTextW(L"버튼 문자열 2");
		//btnStatus = 0;
	}
	btnReview = !btnReview;

}



void CDlgRev::OnBnClickedButtonEx2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	//여기에서 파일 읽어오기
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFont fc;
	fc.CreateFontW(36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Arial"));

	CFileDialog df(TRUE);
	OPENFILENAME& ofn = df.GetOFN();
	ofn.Flags |= OFN_ALLOWMULTISELECT;
	//df.lpstrFile = L"*.*";
	df.DoModal();
	if (df.DoModal() == IDCANCEL) return;
	CString fPath = df.GetPathName();	//full path
	CFile f;
	f.Open(fPath, CFile::modeRead);
	int n = f.GetLength();
	char* buf = new char[n];
	WCHAR* wBuf = new WCHAR[n];
	f.Read(buf, n);
	f.Close();
	MultiByteToWideChar(CP_ACP, 0, buf, n, wBuf, n);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(wBuf);

	delete wBuf;
	delete buf;
}


void CDlgRev::OnBnClickedButtonEx3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	EndDialog(IDOK);
}


void CDlgRev::OnBnClickedButtonEx4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(IDCANCEL);
}


BOOL CDlgRev::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	CFont f;
	f.CreateFontW(36, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, TEXT("Arial"));

	GetDlgItem(IDC_BUTTON_EX4)->SetFont(&f);
	GetDlgItem(IDC_BUTTON_EX1)->SetFont(&f);
	GetDlgItem(IDC_BUTTON_EX2)->SetFont(&f);
	GetDlgItem(IDC_BUTTON_EX3)->SetFont(&f);

	//cStaticTest.SetWindowTextW(L"안녕하세요. 반갑습니다.");
	//글씨크기 36, Arial체로 출력하기
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
