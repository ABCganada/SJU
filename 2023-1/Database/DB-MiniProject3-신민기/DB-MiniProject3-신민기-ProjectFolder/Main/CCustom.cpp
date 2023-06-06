// CCustom.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CCustom.h"
#include "afxdialogex.h"
#include "CCustomTap1.h"
#include "CCustomTap2.h"
#include "CCustomTap3.h"
#include "CCustomTap4.h"
#include "CCustomTap5.h"

// CCustom 대화 상자

IMPLEMENT_DYNAMIC(CCustom, CDialogEx)

CCustom::CCustom(CWnd* pParent /*=nullptr*/)
	: CDialogEx(CustomPage, pParent)
{

}

CCustom::~CCustom()
{
}

void CCustom::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CCustom, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCustom::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCustom::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCustom::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CCustom::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCustom::OnBnClickedButton5)
END_MESSAGE_MAP()


// CCustom 메시지 처리기


void CCustom::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCustomTap1 dlg;
	dlg.DoModal();
}


void CCustom::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCustomTap2 dlg;
	dlg.DoModal();
}


void CCustom::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCustomTap3 dlg;
	dlg.DoModal();
}


void CCustom::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCustomTap4 dlg;
	dlg.DoModal();
}


void CCustom::OnBnClickedButton5()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CCustomTap5 dlg;
	dlg.DoModal();
}
