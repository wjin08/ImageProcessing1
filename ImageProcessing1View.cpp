
// ImageProcessing1View.cpp: CImageProcessing1View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "ImageProcessing1.h"
#endif

#include "ImageProcessing1Doc.h"
#include "ImageProcessing1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CImageProcessing1View

IMPLEMENT_DYNCREATE(CImageProcessing1View, CView)

BEGIN_MESSAGE_MAP(CImageProcessing1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CImageProcessing1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_DOWN_SAMPLING, &CImageProcessing1View::OnDownSampling)
	ON_COMMAND(ID_UP_SAMPLING, &CImageProcessing1View::OnUpSampling)
	ON_COMMAND(ID_QUANTIZATION, &CImageProcessing1View::OnQuantization)
	ON_COMMAND(ID_SUM_CONSTANT, &CImageProcessing1View::OnSumConstant2)
	ON_COMMAND(ID_SUB_CONSTANT, &CImageProcessing1View::OnSubConstant)
	ON_COMMAND(ID_MUL_CONSTANT, &CImageProcessing1View::OnMulConstant)
	ON_COMMAND(ID_DIV_CONSTANT, &CImageProcessing1View::OnDivConstant)
	ON_COMMAND(ID_AND_OPERATE, &CImageProcessing1View::OnAndOperate)
	ON_COMMAND(ID_OR_OPERATE, &CImageProcessing1View::OnOrOperate)
	ON_COMMAND(ID_XOR_OPERATE, &CImageProcessing1View::OnXorOperate)
	ON_COMMAND(ID_NEGA_TRANSFORM, &CImageProcessing1View::OnNegaTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CImageProcessing1View::OnGammaCorrection)
	ON_COMMAND(ID_BINARIZATION, &CImageProcessing1View::OnBinarization)
	ON_COMMAND(ID_STRESS_TRANSFORM, &CImageProcessing1View::OnStressTransform)
	ON_COMMAND(ID_HISTO_STRETCH, &CImageProcessing1View::OnHistoStretch)
	ON_COMMAND(ID_END_IN_SEARCH, &CImageProcessing1View::OnEndInSearch)
	ON_COMMAND(ID_HISTOGRAM, &CImageProcessing1View::OnHistogram)
	ON_COMMAND(ID_HISTO_SPEC, &CImageProcessing1View::OnHistoSpec)
	ON_COMMAND(ID_EMBOSSING, &CImageProcessing1View::OnEmbossing)
	ON_COMMAND(ID_BLURR, &CImageProcessing1View::OnBlurr)
	ON_COMMAND(ID_GAUSSIAN_FILTER, &CImageProcessing1View::OnGaussianFilter)
	ON_COMMAND(ID_SHARPENING, &CImageProcessing1View::OnSharpening)
	ON_COMMAND(ID_HPF_SHARP, &CImageProcessing1View::OnHpfSharp)
	ON_COMMAND(ID_LPF_SHARP, &CImageProcessing1View::OnLpfSharp)
	ON_COMMAND(ID_DIFF_OPERATOR_HOR, &CImageProcessing1View::OnDiffOperatorHor)
	ON_COMMAND(ID_HOMOGEN_OPERATOR, &CImageProcessing1View::OnHomogenOperator)
	ON_COMMAND(ID_LAPLACIAN, &CImageProcessing1View::OnLaplacian)
	ON_COMMAND(ID_NEAREST, &CImageProcessing1View::OnNearest)
	ON_COMMAND(ID_BILINEAR, &CImageProcessing1View::OnBilinear)
	ON_COMMAND(ID_MEDIAN_SUB, &CImageProcessing1View::OnMedianSub)
	ON_COMMAND(ID_MEAN_SUB, &CImageProcessing1View::OnMeanSub)
END_MESSAGE_MAP()

// CImageProcessing1View 생성/소멸

CImageProcessing1View::CImageProcessing1View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CImageProcessing1View::~CImageProcessing1View()
{
}

BOOL CImageProcessing1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CImageProcessing1View 그리기

void CImageProcessing1View::OnDraw(CDC* pDC)
{
	CImageProcessing1Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	int i, j;
	unsigned char R, G, B;
	// 입력 영상 출력
	for (i = 0; i < pDoc->m_height; i++) {
		for (j = 0; j < pDoc->m_width; j++) {
			R = pDoc->m_InputImage[i * pDoc->m_width + j];
			G = B = R;
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}
	}

	// 축소된 영상 출력
	for (i = 0; i < pDoc->m_Re_height; i++) {
		for (j = 0; j < pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i * pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}


}


// CImageProcessing1View 인쇄


void CImageProcessing1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CImageProcessing1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CImageProcessing1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CImageProcessing1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CImageProcessing1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CImageProcessing1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CImageProcessing1View 진단

#ifdef _DEBUG
void CImageProcessing1View::AssertValid() const
{
	CView::AssertValid();
}

void CImageProcessing1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImageProcessing1Doc* CImageProcessing1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImageProcessing1Doc)));
	return (CImageProcessing1Doc*)m_pDocument;
}
#endif //_DEBUG


// CImageProcessing1View 메시지 처리기


void CImageProcessing1View::OnDownSampling()
{
	CImageProcessing1Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출

	Invalidate(TRUE); // 화면 갱신

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CImageProcessing1View::OnUpSampling()
{
	CImageProcessing1Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnUpSampling(); // Doc 클래스에 OnUpSampling 함수 호출

	Invalidate(TRUE); // 화면 갱신


	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CImageProcessing1View::OnQuantization()
{
	CImageProcessing1Doc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnQuantization(); // Doc 클래스에 OnQuantization 함수 호출

	Invalidate(TRUE); // 화면 갱신


	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CImageProcessing1View::OnSumConstant()
{
	// TODO: 여기에 구현 코드 추가.
	CImageProcessing1Doc* pDoc = GetDocument();
	// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnSumConstant();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnSumConstant2()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnSumConstant2();

	Invalidate(TRUE);

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CImageProcessing1View::OnSubConstant()
{
	CImageProcessing1Doc* pDoc = GetDocument();// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnSubConstant();

	Invalidate(TRUE);

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CImageProcessing1View::OnMulConstant()
{
	CImageProcessing1Doc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnMulConstant();

	Invalidate(TRUE);

	}

	// TODO: 여기에 명령 처리기 코드를 추가합니다.



void CImageProcessing1View::OnDivConstant()
{
	CImageProcessing1Doc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnDivConstant();

	Invalidate(TRUE);

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CImageProcessing1View::OnAndOperate()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnAndOperate();

	Invalidate(TRUE);

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CImageProcessing1View::OnOrOperate()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnOrOperate();

	Invalidate(TRUE);

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CImageProcessing1View::OnXorOperate()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnXorOperate();
	Invalidate(TRUE);

	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CImageProcessing1View::OnNegaTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnNegaTransform();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnGammaCorrection()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGammaCorrection();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnBinarization()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBinarization();

	Invalidate(TRUE);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CImageProcessing1View::OnStressTransform()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnStressTransform();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnHistoStretch()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoStretch();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnEndInSearch()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEndInSearch();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnHistogram()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistogram();
	Invalidate(TRUE);

}


void CImageProcessing1View::OnHistoSpec()

{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoSpec();

		Invalidate(TRUE);
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CImageProcessing1View::OnEmbossing()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEmbossing();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnBlurr()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBlurr();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnGaussianFilter()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGaussianFilter();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnSharpening()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnSharpening();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnHpfSharp()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHpfSharp();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnLpfSharp()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLpfSharp();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnDiffOperatorHor()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnDiffOperatorHor();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnHomogenOperator()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHomogenOperator();

	Invalidate(TRUE);
}


void CImageProcessing1View::OnLaplacian()
{
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnLaplacian();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnNearest()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnNearest();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnBilinear()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBilinear();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnMedianSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMedianSub();

	Invalidate(TRUE);

}


void CImageProcessing1View::OnMeanSub()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CImageProcessing1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnMeanSub();

	Invalidate(TRUE);
}
