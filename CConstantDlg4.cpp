// CConstantDlg4.cpp: 구현 파일
//

#include "pch.h"
#include "ImageProcessing1.h"
#include "afxdialogex.h"
#include "CConstantDlg4.h"


// CConstantDlg4 대화 상자

IMPLEMENT_DYNAMIC(CConstantDlg4, CDialog)

CConstantDlg4::CConstantDlg4(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG13, pParent)
	, m_Constant4(0)
{

}

CConstantDlg4::~CConstantDlg4()
{
}

void CConstantDlg4::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT13, m_Constant4);
	DDV_MinMaxDouble(pDX, m_Constant4, 0, 255);
}


BEGIN_MESSAGE_MAP(CConstantDlg4, CDialog)
END_MESSAGE_MAP()


// CConstantDlg4 메시지 처리기
