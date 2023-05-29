// CSchema.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CSchema.h"
#include "afxdialogex.h"
#include "framework.h"


// CSchema 대화 상자

IMPLEMENT_DYNAMIC(CSchema, CDialog)

CSchema::CSchema(CWnd* pParent /*=nullptr*/)
	: CDialog(SchemaPage, pParent)
{

}

CSchema::~CSchema()
{
}

void CSchema::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATA_LIST, m_dataList);
}


BEGIN_MESSAGE_MAP(CSchema, CDialog)
	ON_BN_CLICKED(IDC_READ_BTN, &CSchema::OnBnClickedReadBtn)
	ON_BN_CLICKED(IDC_READ_BTN2, &CSchema::OnBnClickedReadBtn2)
	ON_BN_CLICKED(IDC_READ_BTN3, &CSchema::OnBnClickedReadBtn3)
	ON_BN_CLICKED(IDC_READ_BTN4, &CSchema::OnBnClickedReadBtn4)
	ON_BN_CLICKED(IDC_READ_BTN5, &CSchema::OnBnClickedReadBtn5)
END_MESSAGE_MAP()


// CSchema 메시지 처리기

void CSchema::OnBnClickedReadBtn()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {

		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("select * from Customer"));

		CString name;
		CString address;
		CString phone_no;
		CString email;
		CString dno;

		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("name / Address / Phone_no / email / Dno"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)1, name);
			rs.GetFieldValue((short)2, address);
			rs.GetFieldValue((short)3, phone_no);
			rs.GetFieldValue((short)4, email);
			rs.GetFieldValue((short)5, dno);

			// 리스트 박스에 데이터 추가
			CString data;
			data.Format(_T("%s, %s, %s, %s, %s"), name, address, phone_no, email, dno);
			m_dataList.InsertString(index,data);

			index++;

			rs.MoveNext();
		}
	}
	else {
		AfxMessageBox(_T("연결 실패"));
	}

	db.Close();
}


void CSchema::OnBnClickedReadBtn2()
{
	// TODO: Add control notification handler code here
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

		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("Custmoer ID / Pno / Weight / Status"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, customer_id);
			rs.GetFieldValue((short)1, pno);
			rs.GetFieldValue((short)2, weight);
			rs.GetFieldValue((short)3, status);

			// Construct a string with the retrieved data
			CString data;
			data.Format(_T("%s, %s, %s, %s"),
				customer_id, pno, weight, status);

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




void CSchema::OnBnClickedReadBtn3()
{
	// TODO: Add control notification handler code here
	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {
		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("SELECT * FROM Driver"));

		CString id;
		CString name;
		CString phone_no;
		CString packs;
		CString total_packs;
		CString carno;
		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("ID / Name / Phone No / packages / Total Packages / Car No"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, id);
			rs.GetFieldValue((short)1, name);
			rs.GetFieldValue((short)2, phone_no);
			rs.GetFieldValue((short)3, packs);
			rs.GetFieldValue((short)4, total_packs);
			rs.GetFieldValue((short)5, carno);

			// Construct a string with the retrieved data
			CString data;
			data.Format(_T("%s, %s, %s, %s, %s, %s"),
				id, name, phone_no, packs, total_packs, carno);

			// Add the string to the data list box
			m_dataList.InsertString(index, data);

			index++;

			rs.MoveNext();
		}
	}
	else {
		AfxMessageBox(_T("연결 실패"));
	}

	db.Close();
}


void CSchema::OnBnClickedReadBtn4()
{
	// TODO: Add control notification handler code here
	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {
		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("SELECT * FROM Car"));

		CString id;
		CString capa_w;
		CString capa_n;
		CString bno;

		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("ID / Capability Weight / Capability No / Branch No"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, id);
			rs.GetFieldValue((short)1, capa_w);
			rs.GetFieldValue((short)2, capa_n);
			rs.GetFieldValue((short)3, bno);

			// Construct a string with the retrieved data
			CString data;
			data.Format(_T("%s, %s, %s, %s"),
				id, capa_w, capa_n, bno);

			// Add the string to the data list box
			m_dataList.InsertString(index, data);

			index++;

			rs.MoveNext();
		}
	}
	else {
		AfxMessageBox(_T("연결 실패"));
	}

	db.Close();
}


void CSchema::OnBnClickedReadBtn5()
{
	// TODO: Add control notification handler code here
	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {
		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("SELECT * FROM Branch"));

		CString id;
		CString name;
		CString phone_no;
		CString manager;
		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("ID / Name / Phone No / Manager"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, id);
			rs.GetFieldValue((short)1, name);
			rs.GetFieldValue((short)2, phone_no);
			rs.GetFieldValue((short)3, manager);

			// Construct a string with the retrieved data
			CString data;
			data.Format(_T("%s, %s, %s, %s"),
				id, name, phone_no, manager);

			// Add the string to the data list box
			m_dataList.InsertString(index, data);

			index++;

			rs.MoveNext();
		}
	}
	else {
		AfxMessageBox(_T("연결 실패"));
	}

	db.Close();
}
