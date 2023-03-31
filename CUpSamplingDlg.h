#pragma once
#include "afxdialogex.h"


// CUpSamplingDlg 대화 상자

class CUpSamplingDlg : public CDialog
{
	DECLARE_DYNAMIC(CUpSamplingDlg)

public:
	CUpSamplingDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CUpSamplingDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int m_UpSampleRate;
};
