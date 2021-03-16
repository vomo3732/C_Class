// CDlgTest.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication3.h"
#include "CDlgTest.h"
#include "afxdialogex.h"


// CDlgTest 대화 상자

IMPLEMENT_DYNAMIC(CDlgTest, CDialogEx)

CDlgTest::CDlgTest(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLG_Test1, pParent)
{

}

CDlgTest::~CDlgTest()
{
}

void CDlgTest::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgTest, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgTest::OnClickedTestButton)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgTest::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_OK, &CDlgTest::OnBnClickedOk)
	ON_BN_CLICKED(IDC_Cancle, &CDlgTest::OnBnClickedCancle)
END_MESSAGE_MAP()


// CDlgTest 메시지 처리기

int btnStatus = 0;//전역변수
void CDlgTest::OnClickedTestButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CButton* btn = (CButton*)GetDlgItem(IDC_BUTTON1);
	if (btnStatus==0) {
		btn->SetWindowTextW(L"버튼 문자열 1");
		//btnStatus = 1;
	}
	else
	{
		btn->SetWindowTextW(L"버튼 문자열 2");
		//btnStatus = 0;
	}
	btnStatus = !btnStatus;
	
}

void CDlgTest::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFileDialog df(TRUE);
	OPENFILENAME& ofn = df.GetOFN();
	ofn.Flags |= OFN_ALLOWMULTISELECT;
	//df.lpstrFile = L"*.*";
	df.DoModal();
	if (df.DoModal() == IDCANCEL) return;
	CString fPath = df.GetPathName();	//full path
	CFile f;
	f.Open(fPath, CFile::modeRead);
	int n=f.GetLength();
	char* buf = new char[n];
	WCHAR* wBuf = new WCHAR[n];
	f.Read(buf, n);
	f.Close();
	MultiByteToWideChar(CP_ACP, 0, buf, n, wBuf, n);
	GetDlgItem(IDC_EDIT1)->SetWindowTextW(wBuf);

	delete wBuf;
	delete buf;
}


void CDlgTest::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(IDOK);
}


void CDlgTest::OnBnClickedCancle()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	EndDialog(IDCANCEL);
}
