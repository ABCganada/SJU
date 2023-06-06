// CCustomTap2.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CCustomTap2.h"
#include "afxdialogex.h"


// CCustomTap2 대화 상자

IMPLEMENT_DYNAMIC(CCustomTap2, CDialogEx)

CCustomTap2::CCustomTap2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(CustomTap2, pParent)
{

}

CCustomTap2::~CCustomTap2()
{
}

void CCustomTap2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_dataList);
	DDX_Control(pDX, IDC_EDIT1, m_input1);
	DDX_Control(pDX, IDC_EDIT2, m_input2);
}


BEGIN_MESSAGE_MAP(CCustomTap2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCustomTap2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCustomTap2::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCustomTap2 메시지 처리기


void CCustomTap2::OnBnClickedButton1()
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


void CCustomTap2::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_input1.GetWindowText(m_inputText1);
	CString str1 = m_inputText1;
	m_input2.GetWindowText(m_inputText2);
	CString str2 = m_inputText2;

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), CDatabase::noOdbcDialog);

	if (bRet) {
		CString strSQL;
		strSQL.Format(_T("update package set status = 1 where customer_id = '%s' and pno = '%s';"), str1, str2);

		db.ExecuteSQL(strSQL);

		AfxMessageBox(_T("변경 완료"));
	}
	else {
		AfxMessageBox(_T("DB 연결 실패"));
	}

	db.Close();

}
