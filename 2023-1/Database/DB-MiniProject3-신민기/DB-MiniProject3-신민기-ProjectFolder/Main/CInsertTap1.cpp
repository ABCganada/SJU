// CInsertTap1.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CInsertTap1.h"
#include "afxdialogex.h"


// CInsertTap1 대화 상자

IMPLEMENT_DYNAMIC(CInsertTap1, CDialogEx)

CInsertTap1::CInsertTap1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(InsertTap1, pParent)
{

}

CInsertTap1::~CInsertTap1()
{
}

void CInsertTap1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_input1);
	DDX_Control(pDX, IDC_EDIT2, m_input2);
	DDX_Control(pDX, IDC_EDIT3, m_input3);
	DDX_Control(pDX, IDC_EDIT4, m_input4);
	DDX_Control(pDX, IDC_EDIT5, m_input5);
}


BEGIN_MESSAGE_MAP(CInsertTap1, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInsertTap1::OnBnClickedOk)
END_MESSAGE_MAP()


// CInsertTap1 메시지 처리기


void CInsertTap1::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_input1.GetWindowText(m_inputText1);
	m_input2.GetWindowText(m_inputText2);
	m_input3.GetWindowText(m_inputText3);
	m_input4.GetWindowText(m_inputText4);
	m_input5.GetWindowText(m_inputText5);
	CDialogEx::OnOK();
}
