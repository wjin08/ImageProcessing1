// CDownSampleDlg.cpp: 구현 파일
//

#include "pch.h"
#include "ImageProcessing1.h"
#include "afxdialogex.h"
#include "CDownSampleDlg.h"


// CDownSampleDlg 대화 상자

IMPLEMENT_DYNAMIC(CDownSampleDlg, CDialog)

CDownSampleDlg::CDownSampleDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG11, pParent)
{

}

CDownSampleDlg::~CDownSampleDlg()
{
}

void CDownSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDownSampleDlg, CDialog)
END_MESSAGE_MAP()


// CDownSampleDlg 메시지 처리기
