// CDeleteTap1.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CDeleteTap1.h"
#include "afxdialogex.h"


// CDeleteTap1 대화 상자

IMPLEMENT_DYNAMIC(CDeleteTap1, CDialogEx)

CDeleteTap1::CDeleteTap1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DeleteTap1, pParent)
{

}

CDeleteTap1::~CDeleteTap1()
{
}

void CDeleteTap1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATA_LIST, m_data_list);
	DDX_Control(pDX, IDC_EDIT1, m_input);
}


BEGIN_MESSAGE_MAP(CDeleteTap1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &CDeleteTap1::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteTap1::OnBnClickedButton1)
END_MESSAGE_MAP()


// CDeleteTap1 메시지 처리기

void CDeleteTap1::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_data_list.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {

		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("select id, (select count(*) from customer where customer.dno = driver.id) as total_customer from driver"));

		CString driver_id;
		CString total_customer;

		// Add the header string to the data list box at the top
		m_data_list.InsertString(0, _T("Driver ID / Driver's customers"));
		m_data_list.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, driver_id);
			rs.GetFieldValue((short)1, total_customer);

			// 리스트 박스에 데이터 추가
			CString data;
			data.Format(_T("%s        %s"), driver_id, total_customer);
			m_data_list.InsertString(index, data);

			index++;

			rs.MoveNext();
		}
	}
	else {
		AfxMessageBox(_T("DB 연결 실패"));
	}

	db.Close();
}


void CDeleteTap1::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_input.GetWindowTextW(m_inputText);
	CString str = m_inputText;

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), CDatabase::noOdbcDialog);

	if (bRet) {
		CString strSQL;
		strSQL.Format(_T("delete from driver where id = '%s';"), str);

		db.ExecuteSQL(strSQL);
	}
	else {
		AfxMessageBox(_T("DB 연결 실패"));
	}

	db.Close();


}
