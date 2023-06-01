// CDeleteTap4.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CDeleteTap4.h"
#include "afxdialogex.h"


// CDeleteTap4 대화 상자

IMPLEMENT_DYNAMIC(CDeleteTap4, CDialogEx)

CDeleteTap4::CDeleteTap4(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DeleteTap4, pParent)
{

}

CDeleteTap4::~CDeleteTap4()
{
}

void CDeleteTap4::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_dataList);
	DDX_Control(pDX, IDC_EDIT1, m_input);
}


BEGIN_MESSAGE_MAP(CDeleteTap4, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteTap4::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDeleteTap4::OnBnClickedButton2)
END_MESSAGE_MAP()


// CDeleteTap4 메시지 처리기


void CDeleteTap4::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {

		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("select * from car where id not in (select carno from driver);"));

		CString id;
		CString capa_w;
		CString capa_n;
		CString bno;

		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("Car ID / Capability of Weight / Capability of Weight / Branch No"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, id);
			rs.GetFieldValue((short)1, capa_w);
			rs.GetFieldValue((short)2, capa_n);
			rs.GetFieldValue((short)3, bno);

			// 리스트 박스에 데이터 추가
			CString data;
			data.Format(_T("%s        %s        %s        %s"), id, capa_w, capa_n, bno);
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


void CDeleteTap4::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_input.GetWindowTextW(m_inputText);
	CString str = m_inputText;

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), CDatabase::noOdbcDialog);

	if (bRet) {
		CString strSQL;
		strSQL.Format(_T("delete from car where car.id = '%s';"), str);

		db.ExecuteSQL(strSQL);
		AfxMessageBox(_T("삭제 완료"));
	}
	else {
		AfxMessageBox(_T("DB 연결 실패"));
	}

	db.Close();
}
