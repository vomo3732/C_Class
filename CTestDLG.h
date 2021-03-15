#pragma once


// CTestDLG 대화 상자

class CTestDLG : public CDialogEx
{
	DECLARE_DYNAMIC(CTestDLG)

public:
	CTestDLG(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CTestDLG();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_Test1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CStatic cStaticTest;
	CButton BUTTON_VAR;
	afx_msg void OnBnClickedButton1();
	CEdit m_EditIn;
	CEdit m_EditOut1;
	CEdit m_EditOut2;
};
