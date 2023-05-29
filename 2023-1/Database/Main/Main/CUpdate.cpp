// CUpdate.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CUpdate.h"
#include "afxdialogex.h"
#include "CUpdateTap1.h"
#include "CUpdateTap2.h"

// CUpdate 대화 상자

IMPLEMENT_DYNAMIC(CUpdate, CDialogEx)

CUpdate::CUpdate(CWnd* pParent /*=nullptr*/)
	: CDialogEx(UpdatePage, pParent)
{

}

CUpdate::~CUpdate()
{
}

void CUpdate::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CUpdate, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CUpdate::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUpdate::OnBnClickedButton2)
END_MESSAGE_MAP()


// CUpdate 메시지 처리기


void CUpdate::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CUpdateTap1 dlg;
	dlg.DoModal();
}


void CUpdate::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CUpdateTap2 dlg;
	dlg.DoModal();
}
