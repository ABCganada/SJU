// CCustomTap5.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CCustomTap5.h"
#include "afxdialogex.h"


// CCustomTap5 대화 상자

IMPLEMENT_DYNAMIC(CCustomTap5, CDialogEx)

CCustomTap5::CCustomTap5(CWnd* pParent /*=nullptr*/)
	: CDialogEx(CustomTap5, pParent)
{

}

CCustomTap5::~CCustomTap5()
{
}

void CCustomTap5::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_input1);
	DDX_Control(pDX, IDC_EDIT2, m_input2);
	DDX_Control(pDX, IDC_LIST1, m_dataList);
}


BEGIN_MESSAGE_MAP(CCustomTap5, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCustomTap5::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCustomTap5::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCustomTap5 메시지 처리기


void CCustomTap5::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {

		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("select customer_id, pno, weight, charge from package; "));

		CString id;
		CString name;
		CString weight;
		CString charge;

		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("Customer ID / Package No / Weight / Charge"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, id);
			rs.GetFieldValue((short)1, name);
			rs.GetFieldValue((short)2, weight);
			rs.GetFieldValue((short)3, charge);

			// 리스트 박스에 데이터 추가
			CString data;
			data.Format(_T("%s        %s        %s        %s"), id, name, weight, charge);
			m_dataList.InsertString(index, data);

			index++;

			rs.MoveNext();
		}
	}
	else {
		AfxMessageBox(_T("DB 연결 실패"));
	}

	db.Close();
}


void CCustomTap5::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_input1.GetWindowText(m_inputText1);
	CString str1 = m_inputText1;
	m_input2.GetWindowText(m_inputText2);
	CString str2 = m_inputText2;

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), CDatabase::noOdbcDialog);

	if (bRet) {
		CString strSQL1;
		strSQL1.Format(_T("update package set charge = charge + 1000 where weight >= '%s'; "), str1);
		db.ExecuteSQL(strSQL1);

		CString strSQL2;
		strSQL2.Format(_T("update package set charge = charge + 1000 where customer_id in (select id from customer where address = '%s')"), str2);
		db.ExecuteSQL(strSQL2);

		AfxMessageBox(_T("변경 완료"));
	}
	else {
		AfxMessageBox(_T("DB 연결 실패"));
	}

	db.Close();
}
