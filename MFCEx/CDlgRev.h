#pragma once


// CDlgRev 대화 상자

class CDlgRev : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgRev)

public:
	CDlgRev(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgRev();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_REV };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonEx1();
	afx_msg void OnBnClickedButtonEx2();
	afx_msg void OnBnClickedButtonEx3();
	afx_msg void OnBnClickedButtonEx4();
	virtual BOOL OnInitDialog();
};
