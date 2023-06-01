// CInsert.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CInsert.h"
#include "afxdialogex.h"
#include "CInsertTap1.h"
#include "CInsertTap2.h"
#include "CInsertTap3.h"
#include "CInsertTap4.h"


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
	ON_BN_CLICKED(IDC_BUTTON3, &CInsert::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CInsert::OnBnClickedButton4)
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


void CInsert::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CInsertTap3 dlg;
	if (dlg.DoModal() == IDOK) {
		CString str1 = dlg.m_inputText1;
		CString str2 = dlg.m_inputText2;
		CString str3 = dlg.m_inputText3;
		CString str4 = dlg.m_inputText4;
		CString str5 = dlg.m_inputText5;
		CString str6 = dlg.m_inputText6;
		CString str7 = dlg.m_inputText7;

		CDatabase db;
		BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), CDatabase::noOdbcDialog);

		if (bRet) {
			CString strSQL1, strSQL2;

			if (!str2.IsEmpty() && !str3.IsEmpty() && !str4.IsEmpty()) {
				strSQL1.Format(_T("insert into branch values('%s', '%s', '%s', '%s');"), str1, str2, str3, str4);
				db.ExecuteSQL(strSQL1);
			}

			if (!str5.IsEmpty() && !str6.IsEmpty() && !str7.IsEmpty()) {
				strSQL2.Format(_T("insert into car values('%s', '%s', '%s', '%s')"), str5, str6, str7, str1);
				db.ExecuteSQL(strSQL2);
			}
		}
		else {
			AfxMessageBox(_T("DB 연결 실패"));
		}

		db.Close();
	}
}


void CInsert::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CInsertTap4 dlg;
	if (dlg.DoModal() == IDOK) {
		CString str1 = dlg.m_inputText1;
		CString str2 = dlg.m_inputText2;
		CString str3 = dlg.m_inputText3;
		CString str4 = dlg.m_inputText4;

		CDatabase db;
		BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), CDatabase::noOdbcDialog);

		if (bRet) {
			CString strSQL;

			strSQL.Format(_T("insert into customer(name, address, phone_no, email, dno) values('%s', '%s', '%s', '%s', NULL);"), str1, str2, str3, str4);
			db.ExecuteSQL(strSQL);
		}
		else {
			AfxMessageBox(_T("DB 연결 실패"));
		}

		db.Close();
	}
}
