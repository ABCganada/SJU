// CCustomTap4.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CCustomTap4.h"
#include "afxdialogex.h"


// CCustomTap4 대화 상자

IMPLEMENT_DYNAMIC(CCustomTap4, CDialogEx)

CCustomTap4::CCustomTap4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(CustomTap4, pParent)
{

}

CCustomTap4::~CCustomTap4()
{
}

void CCustomTap4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_dataList);
	DDX_Control(pDX, IDC_EDIT1, m_input1);
	DDX_Control(pDX, IDC_EDIT2, m_input2);
}


BEGIN_MESSAGE_MAP(CCustomTap4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCustomTap4::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCustomTap4::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCustomTap4 메시지 처리기


void CCustomTap4::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {

		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("select customer_id, pno, status from package where status = 1;"));

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


void CCustomTap4::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_input1.GetWindowText(m_inputText1);
	CString str = m_inputText1;
	m_input2.GetWindowText(m_inputText2);
	CString str2 = m_inputText2;

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), CDatabase::noOdbcDialog);

	if (bRet) {
		CString strSQL;
		strSQL.Format(_T("delete from package where customer_id = '%s' and pno = '%s';"), str, str2);

		db.ExecuteSQL(strSQL);

		AfxMessageBox(_T("삭제 완료"));
	}
	else {
		AfxMessageBox(_T("DB 연결 실패"));
	}

	db.Close();
}
