#pragma once


// CDrawTest 대화 상자

class CDrawTest : public CDialogEx
{
	DECLARE_DYNAMIC(CDrawTest)

public:
	CDrawTest(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDrawTest();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_DrawTest };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};
