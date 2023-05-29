﻿// CSelect.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CSelect.h"
#include "afxdialogex.h"
#include "CInput1.h"


// CSelect 대화 상자

IMPLEMENT_DYNAMIC(CSelect, CDialogEx)

CSelect::CSelect(CWnd* pParent /*=nullptr*/)
	: CDialogEx(SelectPage, pParent)
{

}

CSelect::~CSelect()
{
}

void CSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_DATA_LIST, m_dataList);
}


BEGIN_MESSAGE_MAP(CSelect, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CSelect::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CSelect::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CSelect::OnBnClickedButton3)
END_MESSAGE_MAP()


// CSelect 메시지 처리기


void CSelect::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("각 driver가 담당하고 있는 package 개수를 확인합니다."));

	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {

		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("select id, (select count(*) from customer where customer.dno = driver.id) as total_customer from driver"));

		CString driver_id;
		CString total_customer;

		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("Driver ID / Driver's customers"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, driver_id);
			rs.GetFieldValue((short)1, total_customer);

			// 리스트 박스에 데이터 추가
			CString data;
			data.Format(_T("%s        %s"), driver_id, total_customer);
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

void CSelect::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	AfxMessageBox(_T("추가적인 배송 요금을 지불해야 하는 고객의 이름, 주소, 전화번호를 확인합니다."));

	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

	if (bRet) {

		CRecordset rs(&db);
		rs.Open(CRecordset::forwardOnly, _T("select name, address, phone_no from customer where address='jeju'"));

		CString name;
		CString address;
		CString phone_no;

		// Add the header string to the data list box at the top
		m_dataList.InsertString(0, _T("Customer Name / Address / Phone No"));
		m_dataList.InsertString(1, _T(""));

		int index = 2; // Start index for inserting data strings

		while (!rs.IsEOF()) {
			rs.GetFieldValue((short)0, name);
			rs.GetFieldValue((short)1, address);
			rs.GetFieldValue((short)2, phone_no);

			// 리스트 박스에 데이터 추가
			CString data;
			data.Format(_T("%s        %s        %s"), name, address, phone_no);
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

void CSelect::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CInput1 dlg;
	if (dlg.DoModal() == IDOK) {
		CString str = dlg.m_inputText;
		m_dataList.ResetContent();

		CDatabase db;
		BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);

		if (bRet) {
			CString strSQL;
			strSQL.Format(_T("select driver.name, car.bno from driver, car where driver.carno = car.id and car.bno = '%s';"), str);

			CRecordset rs(&db);
			rs.Open(CRecordset::forwardOnly, strSQL);

			CString name;
			CString branch_no;

			// Add the header string to the data list box at the top
			m_dataList.InsertString(0, _T("Customer Name / Branch No"));
			m_dataList.InsertString(1, _T(""));

			int index = 2; // Start index for inserting data strings

			while (!rs.IsEOF()) {
				rs.GetFieldValue((short)0, name);
				rs.GetFieldValue((short)1, branch_no);

				// 리스트 박스에 데이터 추가
				CString data;
				data.Format(_T("%s        %s"), name, branch_no);
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
}