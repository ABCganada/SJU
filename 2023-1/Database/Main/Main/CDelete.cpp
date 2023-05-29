// CDelete.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CDelete.h"
#include "afxdialogex.h"
#include "CDeleteTap1.h"
#include "CDeleteTap2.h"


// CDelete 대화 상자

IMPLEMENT_DYNAMIC(CDelete, CDialogEx)

CDelete::CDelete(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DeletePage, pParent)
{

}

CDelete::~CDelete()
{
}

void CDelete::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDelete, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDelete::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDelete::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDelete 메시지 처리기


void CDelete::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDeleteTap1 dlg;
	dlg.DoModal();
}


void CDelete::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDeleteTap2 dlg;
	dlg.DoModal();
}
