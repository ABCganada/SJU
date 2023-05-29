// CUpdateTap2.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CUpdateTap2.h"
#include "afxdialogex.h"


// CUpdateTap2 대화 상자

IMPLEMENT_DYNAMIC(CUpdateTap2, CDialogEx)

CUpdateTap2::CUpdateTap2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(UpdateTap2, pParent)
{

}

CUpdateTap2::~CUpdateTap2()
{
}

void CUpdateTap2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_dataList);
}


BEGIN_MESSAGE_MAP(CUpdateTap2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CUpdateTap2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUpdateTap2::OnBnClickedButton2)
END_MESSAGE_MAP()


// CUpdateTap2 메시지 처리기


void CUpdateTap2::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {
		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("SELECT * FROM package"));

		CString customer_id;
		CString pno;
		CString weight;
		CString status;
		CString charge;

		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("Custmoer ID / Pno / Weight / Status / Charge"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, customer_id);
			rs.GetFieldValue((short)1, pno);
			rs.GetFieldValue((short)2, weight);
			rs.GetFieldValue((short)3, status);
			rs.GetFieldValue((short)4, charge);

			// Construct a string with the retrieved data
			CString data;
			data.Format(_T("%s        %s        %s        %s        %s"), customer_id, pno, weight, status, charge);

			// Insert the string at the specified index
			m_dataList.InsertString(index, data);

			index++; // Increment the index for the next string
			rs.MoveNext();
		}
	}
	else {
		AfxMessageBox(_T("연결 실패"));
	}

	db.Close();
}


void CUpdateTap2::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), CDatabase::noOdbcDialog);

	if (bRet) {
		CString strSQL;
		strSQL.Format(_T("update package set charge = charge + 1000 where customer_id in (select id from customer where address = 'jeju')"));

		db.ExecuteSQL(strSQL);
	}
	else {
		AfxMessageBox(_T("DB 연결 실패"));
	}

	db.Close();
}
