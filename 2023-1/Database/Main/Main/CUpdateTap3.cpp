// CUpdateTap3.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CUpdateTap3.h"
#include "afxdialogex.h"


// CUpdateTap3 대화 상자

IMPLEMENT_DYNAMIC(CUpdateTap3, CDialogEx)

CUpdateTap3::CUpdateTap3(CWnd* pParent /*=nullptr*/)
	: CDialogEx(UpdateTap3, pParent)
{

}

CUpdateTap3::~CUpdateTap3()
{
}

void CUpdateTap3::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_dataList);
}


BEGIN_MESSAGE_MAP(CUpdateTap3, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CUpdateTap3::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CUpdateTap3::OnBnClickedButton2)
END_MESSAGE_MAP()


// CUpdateTap3 메시지 처리기


void CUpdateTap3::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {

		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("select id, name, packs, total_packs from driver;"));

		CString id;
		CString name;
		CString packages;
		CString total_packs;

		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("Driver ID / Driver Name / Current Packages / Total Packages"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, id);
			rs.GetFieldValue((short)1, name);
			rs.GetFieldValue((short)2, packages);
			rs.GetFieldValue((short)3, total_packs);

			// 리스트 박스에 데이터 추가
			CString data;
			data.Format(_T("%s        %s        %s        %s"), id, name, packages, total_packs);
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


void CUpdateTap3::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), CDatabase::noOdbcDialog);

	if (bRet) {
		CString strSQL1, strSQL2;
		strSQL1.Format(_T("update driver set packs = (select count(*) from customer, package where driver.id = customer.dno and customer.id = package.customer_id and package.status < > 1); "));
		db.ExecuteSQL(strSQL1);

		strSQL2.Format(_T("update driver set total_packs = total_packs + packs; "));
		db.ExecuteSQL(strSQL2);
	}
	else {
		AfxMessageBox(_T("DB 연결 실패"));
	}

	db.Close();
	
}
