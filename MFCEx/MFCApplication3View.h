﻿
// MFCApplication3View.h: CMFCApplication3View 클래스의 인터페이스
//

#pragma once


class CMFCApplication3View : public CView
{
protected: // serialization에서만 만들어집니다.
	CMFCApplication3View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication3View)

// 특성입니다.
public:
	CMFCApplication3Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCApplication3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCApplication3View.cpp의 디버그 버전
inline CMFCApplication3Doc* CMFCApplication3View::GetDocument() const
   { return reinterpret_cast<CMFCApplication3Doc*>(m_pDocument); }
#endif

