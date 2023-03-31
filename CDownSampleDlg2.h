#pragma once
#include "afxdialogex.h"


// CDownSampleDlg2 대화 상자

class CDownSampleDlg2 : public CDialog
{
	DECLARE_DYNAMIC(CDownSampleDlg2)

public:
	CDownSampleDlg2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDownSampleDlg2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
