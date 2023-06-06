// CInput1.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CInput1.h"
#include "afxdialogex.h"
#include "CSelect.h"


// CInput1 대화 상자

IMPLEMENT_DYNAMIC(CInput1, CDialogEx)

CInput1::CInput1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(InputPage1, pParent)
{

}

CInput1::~CInput1()
{
}

void CInput1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INPUT_BRANCH_EDIT, m_input);
}


BEGIN_MESSAGE_MAP(CInput1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CInput1::OnBnClickedButton2)
END_MESSAGE_MAP()


// CInput1 메시지 처리기

void CInput1::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_input.GetWindowText(m_inputText);
	CDialogEx::OnOK();
    
}