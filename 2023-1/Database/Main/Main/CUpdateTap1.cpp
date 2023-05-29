// CUpdateTap1.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CUpdateTap1.h"
#include "afxdialogex.h"


// CUpdateTap1 대화 상자

IMPLEMENT_DYNAMIC(CUpdateTap1, CDialogEx)

CUpdateTap1::CUpdateTap1(CWnd* pParent /*=nullptr*/)
	: CDialogEx(UpdateTap1, pParent)
{

}

CUpdateTap1::~CUpdateTap1()
{
}

void CUpdateTap1::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_dataList);
	DDX_Control(pDX, IDC_EDIT1, m_input1);
	DDX_Control(pDX, IDC_EDIT2, m_input2);
}


BEGIN_MESSAGE_MAP(CUpdateTap1, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CUpdateTap1::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CUpdateTap1::OnBnClickedButton3)
END_MESSAGE_MAP()


// CUpdateTap1 메시지 처리기


void CUpdateTap1::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {

		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("select customer_id, pno, status from package"));

		CString customer_id;
		CString pno;
		CString status;

		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("Customer ID / Package No / Status"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, customer_id);
			rs.GetFieldValue((short)1, pno);
			rs.GetFieldValue((short)2, status);

			// 리스트 박스에 데이터 추가
			CString data;
			data.Format(_T("%s        %s        %s"), customer_id, pno, status);
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


void CUpdateTap1::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_input1.GetWindowTextW(m_inputText1);
	CString str1 = m_inputText1;
	m_input2.GetWindowTextW(m_inputText2);
	CString str2 = m_inputText2;

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), CDatabase::noOdbcDialog);

	if (bRet) {
		CString strSQL;
		strSQL.Format(_T("update package set status = 1 where customer_id = '%s' and pno = '%s';"), str1, str2);

		db.ExecuteSQL(strSQL);
	}
	else {
		AfxMessageBox(_T("DB 연결 실패"));
	}

	db.Close();
}
