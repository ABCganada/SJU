// CCustomTap3.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CCustomTap3.h"
#include "afxdialogex.h"


// CCustomTap3 대화 상자

IMPLEMENT_DYNAMIC(CCustomTap3, CDialogEx)

CCustomTap3::CCustomTap3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(CustomTap3, pParent)
{

}

CCustomTap3::~CCustomTap3()
{
}

void CCustomTap3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_dataList);
	DDX_Control(pDX, IDC_EDIT1, m_input);
}


BEGIN_MESSAGE_MAP(CCustomTap3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCustomTap3::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCustomTap3::OnBnClickedButton2)
END_MESSAGE_MAP()


// CCustomTap3 메시지 처리기


void CCustomTap3::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {

		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("SELECT id, name from driver; "));

		CString id, name1;

		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("Driver ID / Driver Name"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, id);
			rs.GetFieldValue((short)1, name1);

			// 리스트 박스에 데이터 추가
			CString data;
			data.Format(_T("%s        %s"), id, name1);
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


void CCustomTap3::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_input.GetWindowText(m_inputText);
	CString str = m_inputText;

	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {
		CString strSQL;
		strSQL.Format(_T("SELECT id, name, total_packs, CASE WHEN total_packs >= 5 THEN 2500000 + (15000 * total_packs) ELSE 2500000 END AS Salary FROM driver where id = '%s';"), str);

		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, strSQL);

		CString id, name, total_packs, salary;

		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("Driver ID / Driver Name / Total Packages / Salary"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, id);
			rs.GetFieldValue((short)1, name);
			rs.GetFieldValue((short)2, total_packs);
			rs.GetFieldValue((short)3, salary);

			// 리스트 박스에 데이터 추가
			CString data;
			data.Format(_T("%s        %s        %s        %s"), id, name, total_packs, salary);
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
