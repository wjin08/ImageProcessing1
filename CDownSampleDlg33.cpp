// CDownSampleDlg33.cpp: 구현 파일
//

#include "pch.h"
#include "ImageProcessing1.h"
#include "afxdialogex.h"
#include "CDownSampleDlg33.h"


// CDownSampleDlg33 대화 상자

IMPLEMENT_DYNAMIC(CDownSampleDlg33, CDialog)

CDownSampleDlg33::CDownSampleDlg33(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG3, pParent)
	, m_DownSampleRate3(0)
{

}

CDownSampleDlg33::~CDownSampleDlg33()
{
}

void CDownSampleDlg33::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, m_DownSampleRate3);
	DDV_MinMaxInt(pDX, m_DownSampleRate3, 1, 32);
}


BEGIN_MESSAGE_MAP(CDownSampleDlg33, CDialog)
END_MESSAGE_MAP()


// CDownSampleDlg33 메시지 처리기
