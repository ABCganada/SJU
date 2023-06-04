// CInsertTap3.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CInsertTap3.h"
#include "afxdialogex.h"


// CInsertTap3 대화 상자

IMPLEMENT_DYNAMIC(CInsertTap3, CDialogEx)

CInsertTap3::CInsertTap3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(InsertTap3, pParent)
{

}

CInsertTap3::~CInsertTap3()
{
}

void CInsertTap3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_input1);
	DDX_Control(pDX, IDC_EDIT2, m_input2);
	DDX_Control(pDX, IDC_EDIT3, m_input3);
	DDX_Control(pDX, IDC_EDIT4, m_input4);
	DDX_Control(pDX, IDC_EDIT5, m_input5);
	DDX_Control(pDX, IDC_EDIT6, m_input6);
	DDX_Control(pDX, IDC_EDIT7, m_input7);
}


BEGIN_MESSAGE_MAP(CInsertTap3, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInsertTap3::OnBnClickedOk)
END_MESSAGE_MAP()


// CInsertTap3 메시지 처리기


void CInsertTap3::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_input1.GetWindowTextW(m_inputText1);
	m_input2.GetWindowTextW(m_inputText2);
	m_input3.GetWindowTextW(m_inputText3);
	m_input4.GetWindowTextW(m_inputText4);
	m_input5.GetWindowTextW(m_inputText5);
	m_input6.GetWindowTextW(m_inputText6);
	m_input7.GetWindowTextW(m_inputText7);
	CDialogEx::OnOK();
}
