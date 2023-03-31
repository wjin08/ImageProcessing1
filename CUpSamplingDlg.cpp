// CUpSamplingDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ImageProcessing1.h"
#include "afxdialogex.h"
#include "CUpSamplingDlg.h"


// CUpSamplingDlg 대화 상자

IMPLEMENT_DYNAMIC(CUpSamplingDlg, CDialog)

CUpSamplingDlg::CUpSamplingDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG4, pParent)
	, m_UpSampleRate(0)
{

}

CUpSamplingDlg::~CUpSamplingDlg()
{
}

void CUpSamplingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT4, m_UpSampleRate);
}


BEGIN_MESSAGE_MAP(CUpSamplingDlg, CDialog)
END_MESSAGE_MAP()


// CUpSamplingDlg 메시지 처리기
