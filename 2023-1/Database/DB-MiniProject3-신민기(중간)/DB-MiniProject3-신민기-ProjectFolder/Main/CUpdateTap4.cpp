// CUpdateTap4.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CUpdateTap4.h"
#include "afxdialogex.h"


// CUpdateTap4 대화 상자

IMPLEMENT_DYNAMIC(CUpdateTap4, CDialogEx)

CUpdateTap4::CUpdateTap4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(UpdateTap4, pParent)
{

}

CUpdateTap4::~CUpdateTap4()
{
}

void CUpdateTap4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_dataList);
}


BEGIN_MESSAGE_MAP(CUpdateTap4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CUpdateTap4::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CUpdateTap4::OnBnClickedButton1)
END_MESSAGE_MAP()


// CUpdateTap4 메시지 처리기


void CUpdateTap4::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), CDatabase::noOdbcDialog);

	if (bRet) {
		CString strSQL;
		strSQL.Format(_T("update package set charge = charge + 1000 where weight >= 10; "));
		db.ExecuteSQL(strSQL);

		AfxMessageBox(_T("변경 완료"));
	}
	else {
		AfxMessageBox(_T("DB 연결 실패"));
	}

	db.Close();
}


void CUpdateTap4::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {

		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("select customer.id, customer.name, SUM(package.charge) as total_charge from customer, package where customer.id = package.customer_id group by customer.id, customer.name; "));

		CString id;
		CString name;
		CString total_charge;

		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("Customer ID / Customer Name / Total Charge"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, id);
			rs.GetFieldValue((short)1, name);
			rs.GetFieldValue((short)2, total_charge);

			// 리스트 박스에 데이터 추가
			CString data;
			data.Format(_T("%s        %s        %s"), id, name, total_charge);
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
