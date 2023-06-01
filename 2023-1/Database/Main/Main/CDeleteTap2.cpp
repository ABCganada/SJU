// CDeleteTap2.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CDeleteTap2.h"
#include "afxdialogex.h"


// CDeleteTap2 대화 상자

IMPLEMENT_DYNAMIC(CDeleteTap2, CDialogEx)

CDeleteTap2::CDeleteTap2(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DeleteTap2, pParent)
{

}

CDeleteTap2::~CDeleteTap2()
{
}

void CDeleteTap2::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_dataList);
	DDX_Control(pDX, IDC_EDIT1, m_input);
	DDX_Control(pDX, IDC_EDIT2, m_input2);
}


BEGIN_MESSAGE_MAP(CDeleteTap2, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDeleteTap2::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDeleteTap2::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CDeleteTap2::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CDeleteTap2 메시지 처리기


void CDeleteTap2::OnBnClickedButton1()
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


void CDeleteTap2::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_input.GetWindowTextW(m_inputText);
	CString str = m_inputText;
	m_input2.GetWindowTextW(m_inputText2);
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


void CDeleteTap2::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
