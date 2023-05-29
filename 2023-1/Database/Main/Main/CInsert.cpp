// CInsert.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CInsert.h"
#include "afxdialogex.h"
#include "CInsertTap1.h"
#include "CInsertTap2.h"


// CInsert 대화 상자

IMPLEMENT_DYNAMIC(CInsert, CDialogEx)

CInsert::CInsert(CWnd* pParent /*=nullptr*/)
	: CDialogEx(InsertPage, pParent)
{

}

CInsert::~CInsert()
{
}

void CInsert::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInsert, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CInsert::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CInsert::OnBnClickedButton2)
END_MESSAGE_MAP()


// CInsert 메시지 처리기


void CInsert::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CInsertTap1 dlg;
	if (dlg.DoModal() == IDOK) {
		CString str1 = dlg.m_inputText1;
		CString str2 = dlg.m_inputText2;
		CString str3 = dlg.m_inputText3;
		CString str4 = dlg.m_inputText4;
		CString str5 = dlg.m_inputText5;

		CDatabase db;
		BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), CDatabase::noOdbcDialog);

		if (bRet) {
			CString strSQL;
			strSQL.Format(_T("insert into package values('%s', '%s', '%s', '%s', '%s');"), str1, str2, str3, str4, str5);

			db.ExecuteSQL(strSQL);
		}
		else {
			AfxMessageBox(_T("DB 연결 실패"));
		}

		db.Close();

	}
}


void CInsert::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CInsertTap2 dlg;
	if (dlg.DoModal() == IDOK) {
		CString str1 = dlg.m_inputText1;
		CString str2 = dlg.m_inputText2;
		CString str3 = dlg.m_inputText3;
		CString str4 = dlg.m_inputText4;

		CDatabase db;
		BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), CDatabase::noOdbcDialog);

		if (bRet) {
			CString strSQL;
			strSQL.Format(_T("insert into driver values('%s', '%s', '%s', 0, 0, '%s');"), str1, str2, str3, str4);

			db.ExecuteSQL(strSQL);
		}
		else {
			AfxMessageBox(_T("DB 연결 실패"));
		}

		db.Close();

	}

}
