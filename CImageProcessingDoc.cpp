// CImageProcessingDoc.cpp: 구현 파일
//

#include "pch.h"
#include "ImageProcessing1.h"
#include "CImageProcessingDoc.h"


// CImageProcessingDoc

IMPLEMENT_DYNCREATE(CImageProcessingDoc, CDocument)

CImageProcessingDoc::CImageProcessingDoc()
{
}

BOOL CImageProcessingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	return TRUE;
}

CImageProcessingDoc::~CImageProcessingDoc()
{
}


BEGIN_MESSAGE_MAP(CImageProcessingDoc, CDocument)
END_MESSAGE_MAP()


// CImageProcessingDoc 진단

#ifdef _DEBUG
void CImageProcessingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

#ifndef _WIN32_WCE
void CImageProcessingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif
#endif //_DEBUG

#ifndef _WIN32_WCE
// CImageProcessingDoc serialization

void CImageProcessingDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else
	{
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}
#endif


// CImageProcessingDoc 명령
