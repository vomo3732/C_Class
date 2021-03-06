﻿#pragma once


// CDlgTest 대화 상자

class CDlgTest : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgTest)

public:
	CDlgTest(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgTest();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_Test1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnClickedTestButton();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancle();
};
