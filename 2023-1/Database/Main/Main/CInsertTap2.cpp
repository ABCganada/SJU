// CInsertTap2.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CInsertTap2.h"
#include "afxdialogex.h"


// CInsertTap2 대화 상자

IMPLEMENT_DYNAMIC(CInsertTap2, CDialogEx)

CInsertTap2::CInsertTap2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(InsertTap2, pParent)
{

}

CInsertTap2::~CInsertTap2()
{
}

void CInsertTap2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_input1);
	DDX_Control(pDX, IDC_EDIT2, m_input2);
	DDX_Control(pDX, IDC_EDIT3, m_input3);
	DDX_Control(pDX, IDC_EDIT4, m_input4);
}


BEGIN_MESSAGE_MAP(CInsertTap2, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInsertTap2::OnBnClickedOk)
END_MESSAGE_MAP()


// CInsertTap2 메시지 처리기


void CInsertTap2::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_input1.GetWindowTextW(m_inputText1);
	m_input2.GetWindowTextW(m_inputText2);
	m_input3.GetWindowTextW(m_inputText3);
	m_input4.GetWindowTextW(m_inputText4);
	CDialogEx::OnOK();
}
