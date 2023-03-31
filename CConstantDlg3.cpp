// CConstantDlg3.cpp: 구현 파일
//

#include "pch.h"
#include "ImageProcessing1.h"
#include "afxdialogex.h"
#include "CConstantDlg3.h"


// CConstantDlg3 대화 상자

IMPLEMENT_DYNAMIC(CConstantDlg3, CDialog)

CConstantDlg3::CConstantDlg3(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG10, pParent)
	, m_Constant3(0)
{

}

CConstantDlg3::~CConstantDlg3()
{
}

void CConstantDlg3::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT10, m_Constant3);
	DDV_MinMaxDouble(pDX, m_Constant3, 0, 255);
}


BEGIN_MESSAGE_MAP(CConstantDlg3, CDialog)
END_MESSAGE_MAP()


// CConstantDlg3 메시지 처리기
