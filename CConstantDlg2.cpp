// CConstantDlg2.cpp: 구현 파일
//

#include "pch.h"
#include "ImageProcessing1.h"
#include "afxdialogex.h"
#include "CConstantDlg2.h"


// CConstantDlg2 대화 상자

IMPLEMENT_DYNAMIC(CConstantDlg2, CDialog)

CConstantDlg2::CConstantDlg2(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG9, pParent)
	, m_Constant2(0)
{

}

CConstantDlg2::~CConstantDlg2()
{
}

void CConstantDlg2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT9, m_Constant2);
	DDV_MinMaxDouble(pDX, m_Constant2, 0, 255);
}


BEGIN_MESSAGE_MAP(CConstantDlg2, CDialog)
END_MESSAGE_MAP()


// CConstantDlg2 메시지 처리기
