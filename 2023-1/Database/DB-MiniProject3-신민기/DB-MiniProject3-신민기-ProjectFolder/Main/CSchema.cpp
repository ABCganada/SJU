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
	ON_LBN_SELCHANGE(IDC_DATA_LIST, &CSchema::OnLbnSelchangeDataList)
END_MESSAGE_MAP()

const char* get_data_type_in_string(SQLSMALLINT dataType)
{
	switch (dataType)
	{
	case SQL_CHAR:
		return "CHAR";
		break;
	case SQL_VARCHAR:
		return "VARCHAR";
		break;
	case SQL_LONGVARCHAR:
		return "LONGVARCHAR";
		break;
	case SQL_WCHAR:
		return "WCHAR";
		break;
	case SQL_WVARCHAR:
		return "WVARCHAR";
		break;
	case SQL_WLONGVARCHAR:
		return "WLONGVARCHAR";
		break;
	case SQL_NUMERIC:
		return "NUMERIC";
		break;
	case SQL_SMALLINT:
		return "SMALLINT";
		break;
	case SQL_INTEGER:
		return "INTEGER";
		break;
	case SQL_REAL:
		return "REAL";
		break;
	case SQL_FLOAT:
		return "FLOAT";
		break;
	case SQL_DOUBLE:
		return "DOUBLE";
		break;
	case SQL_BIT:
		return "BIT";
		break;
	case SQL_TINYINT:
		return "TINYINT";
		break;
	case SQL_BIGINT:
		return "BIGINT";
		break;
	case SQL_BINARY:
		return "BINARY";
		break;
	case SQL_VARBINARY:
		return "VARBINARY";
		break;
	case SQL_LONGVARBINARY:
		return "LONGVARBINARY";
		break;
	case SQL_TYPE_DATE:
		return "TYPE_DATE";
		break;
	case SQL_TYPE_TIME:
		return "TYPE_TIME";
		break;
	case SQL_TYPE_TIMESTAMP:
		return "TYPE_TIMESTAMP";
		break;
	case SQL_INTERVAL_MONTH:
		return "INTERVAL_MONTH";
		break;
	case SQL_INTERVAL_YEAR:
		return "INTERVAL_YEAR";
		break;
	case SQL_INTERVAL_YEAR_TO_MONTH:
		return "INTERVAL_YEAR_TO_MONTH";
		break;
	case SQL_INTERVAL_DAY:
		return "INTERVAL_DAY";
		break;
	case SQL_INTERVAL_HOUR:
		return "INTERVAL_HOUR";
		break;
	case SQL_INTERVAL_MINUTE:
		return "INTERVAL_MINUTE";
		break;
	case SQL_INTERVAL_SECOND:
		return "INTERVAL_SECOND";
		break;
	case SQL_INTERVAL_DAY_TO_HOUR:
		return "INTERVAL_DAY_TO_HOUR";
		break;
	case SQL_INTERVAL_DAY_TO_MINUTE:
		return "INTERVAL_DAY_TO_MINUTE";
		break;
	case SQL_INTERVAL_DAY_TO_SECOND:
		return "INTERVAL_DAY_TO_SECOND";
		break;
	case SQL_INTERVAL_HOUR_TO_MINUTE:
		return "INTERVAL_HOUR_TO_MINUTE";
		break;
	case SQL_INTERVAL_HOUR_TO_SECOND:
		return "INTERVAL_HOUR_TO_SECOND";
		break;
	case SQL_INTERVAL_MINUTE_TO_SECOND:
		return "INTERVAL_MINUTE_TO_SECOND";
		break;
	case SQL_GUID:
		return "GUID";
		break;
	default:
		return "UNKNOWN";
	}
}

// CSchema 메시지 처리기

void CSchema::OnBnClickedReadBtn()
{
	// TODO: Add control notification handler code here
	m_dataList.ResetContent();

	CDatabase db;
	BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), 0);
	if (bRet) {
		SQLHDBC hDbc = db.m_hdbc;

		SQLHSTMT hStmt;
		SQLCHAR query[101];

		SQLSMALLINT numCols = -1;
		SQLCHAR columnName[50][31];
		SQLSMALLINT columnNameLen[50];
		SQLSMALLINT columnDataType[50];
		SQLULEN columnDataSize[50];
		SQLSMALLINT columnDataDecimalDigits[50];
		SQLSMALLINT columnDataNullable[50];
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
		{
			sprintf_s((char*)query, 101, "select * from customer");
			SQLExecDirect(hStmt, query, SQL_NTS);

			SQLNumResultCols(hStmt, &numCols);
			for (int i = 0; i < numCols; ++i)
			{
				SQLDescribeCol(hStmt, i + 1, columnName[i], 30, &columnNameLen[i], &columnDataType[i],
					&columnDataSize[i], &columnDataDecimalDigits[i], &columnDataNullable[i]);

				CString nullableString;
				if (columnDataNullable[i] == SQL_NULLABLE)
					nullableString = _T("NULL");
				else
					nullableString = _T("Not NULL");

				CString columnInfo;
				columnInfo.Format(_T("#%d        %s        %d        %s        %d        %s\n"),
					i + 1, columnName[i], columnNameLen[i], get_data_type_in_string(columnDataType[i]),
					columnDataSize[i], nullableString);

				m_dataList.AddString(columnInfo);
			}

			CString columnInfo;
			columnInfo.Format(_T(""));
			m_dataList.InsertString(0, columnInfo);

			columnInfo.Format(_T("Column # / Name / Length / Data type / Data size  / Nullable"));
			m_dataList.InsertString(0, columnInfo);

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
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
		SQLHDBC hDbc = db.m_hdbc;

		SQLHSTMT hStmt;
		SQLCHAR query[101];

		SQLSMALLINT numCols = -1;
		SQLCHAR columnName[50][31];
		SQLSMALLINT columnNameLen[50];
		SQLSMALLINT columnDataType[50];
		SQLULEN columnDataSize[50];
		SQLSMALLINT columnDataDecimalDigits[50];
		SQLSMALLINT columnDataNullable[50];
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
		{
			sprintf_s((char*)query, 101, "select * from package");
			SQLExecDirect(hStmt, query, SQL_NTS);

			SQLNumResultCols(hStmt, &numCols);
			for (int i = 0; i < numCols; ++i)
			{
				SQLDescribeCol(hStmt, i + 1, columnName[i], 30, &columnNameLen[i], &columnDataType[i],
					&columnDataSize[i], &columnDataDecimalDigits[i], &columnDataNullable[i]);

				CString nullableString;
				if (columnDataNullable[i] == SQL_NULLABLE)
					nullableString = _T("NULL");
				else
					nullableString = _T("Not NULL");

				CString columnInfo;
				columnInfo.Format(_T("#%d        %s        %d        %s        %d        %s\n"),
					i + 1, columnName[i], columnNameLen[i], get_data_type_in_string(columnDataType[i]),
					columnDataSize[i], nullableString);

				m_dataList.AddString(columnInfo);
			}

			CString columnInfo;
			columnInfo.Format(_T(""));
			m_dataList.InsertString(0, columnInfo);

			columnInfo.Format(_T("Column # / Name / Length / Data type / Data size  / Nullable"));
			m_dataList.InsertString(0, columnInfo);

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
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
		SQLHDBC hDbc = db.m_hdbc;

		SQLHSTMT hStmt;
		SQLCHAR query[101];

		SQLSMALLINT numCols = -1;
		SQLCHAR columnName[50][31];
		SQLSMALLINT columnNameLen[50];
		SQLSMALLINT columnDataType[50];
		SQLULEN columnDataSize[50];
		SQLSMALLINT columnDataDecimalDigits[50];
		SQLSMALLINT columnDataNullable[50];
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
		{
			sprintf_s((char*)query, 101, "select * from driver");
			SQLExecDirect(hStmt, query, SQL_NTS);

			SQLNumResultCols(hStmt, &numCols);
			for (int i = 0; i < numCols; ++i)
			{
				SQLDescribeCol(hStmt, i + 1, columnName[i], 30, &columnNameLen[i], &columnDataType[i],
					&columnDataSize[i], &columnDataDecimalDigits[i], &columnDataNullable[i]);

				CString nullableString;
				if (columnDataNullable[i] == SQL_NULLABLE)
					nullableString = _T("NULL");
				else
					nullableString = _T("Not NULL");

				CString columnInfo;
				columnInfo.Format(_T("#%d        %s        %d        %s        %d        %s\n"),
					i + 1, columnName[i], columnNameLen[i], get_data_type_in_string(columnDataType[i]),
					columnDataSize[i], nullableString);

				m_dataList.AddString(columnInfo);
			}

			CString columnInfo;
			columnInfo.Format(_T(""));
			m_dataList.InsertString(0, columnInfo);

			columnInfo.Format(_T("Column # / Name / Length / Data type / Data size  / Nullable"));
			m_dataList.InsertString(0, columnInfo);

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
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
		SQLHDBC hDbc = db.m_hdbc;

		SQLHSTMT hStmt;
		SQLCHAR query[101];

		SQLSMALLINT numCols = -1;
		SQLCHAR columnName[50][31];
		SQLSMALLINT columnNameLen[50];
		SQLSMALLINT columnDataType[50];
		SQLULEN columnDataSize[50];
		SQLSMALLINT columnDataDecimalDigits[50];
		SQLSMALLINT columnDataNullable[50];
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
		{
			sprintf_s((char*)query, 101, "select * from car");
			SQLExecDirect(hStmt, query, SQL_NTS);

			SQLNumResultCols(hStmt, &numCols);
			for (int i = 0; i < numCols; ++i)
			{
				SQLDescribeCol(hStmt, i + 1, columnName[i], 30, &columnNameLen[i], &columnDataType[i],
					&columnDataSize[i], &columnDataDecimalDigits[i], &columnDataNullable[i]);

				CString nullableString;
				if (columnDataNullable[i] == SQL_NULLABLE)
					nullableString = _T("NULL");
				else
					nullableString = _T("Not NULL");

				CString columnInfo;
				columnInfo.Format(_T("#%d        %s        %d        %s        %d        %s\n"),
					i + 1, columnName[i], columnNameLen[i], get_data_type_in_string(columnDataType[i]),
					columnDataSize[i], nullableString);

				m_dataList.AddString(columnInfo);
			}

			CString columnInfo;
			columnInfo.Format(_T(""));
			m_dataList.InsertString(0, columnInfo);

			columnInfo.Format(_T("Column # / Name / Length / Data type / Data size  / Nullable"));
			m_dataList.InsertString(0, columnInfo);

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
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
		SQLHDBC hDbc = db.m_hdbc;

		SQLHSTMT hStmt;
		SQLCHAR query[101];

		SQLSMALLINT numCols = -1;
		SQLCHAR columnName[50][31];
		SQLSMALLINT columnNameLen[50];
		SQLSMALLINT columnDataType[50];
		SQLULEN columnDataSize[50];
		SQLSMALLINT columnDataDecimalDigits[50];
		SQLSMALLINT columnDataNullable[50];
		if (SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt) == SQL_SUCCESS)
		{
			sprintf_s((char*)query, 101, "select * from branch");
			SQLExecDirect(hStmt, query, SQL_NTS);

			SQLNumResultCols(hStmt, &numCols);
			for (int i = 0; i < numCols; ++i)
			{
				SQLDescribeCol(hStmt, i + 1, columnName[i], 30, &columnNameLen[i], &columnDataType[i],
					&columnDataSize[i], &columnDataDecimalDigits[i], &columnDataNullable[i]);

				CString nullableString;
				if (columnDataNullable[i] == SQL_NULLABLE)
					nullableString = _T("NULL");
				else
					nullableString = _T("Not NULL");

				CString columnInfo;
				columnInfo.Format(_T("#%d        %s        %d        %s        %d        %s\n"),
					i + 1, columnName[i], columnNameLen[i], get_data_type_in_string(columnDataType[i]),
					columnDataSize[i], nullableString);

				m_dataList.AddString(columnInfo);
			}

			CString columnInfo;
			columnInfo.Format(_T(""));
			m_dataList.InsertString(0, columnInfo);

			columnInfo.Format(_T("Column # / Name / Length / Data type / Data size  / Nullable"));
			m_dataList.InsertString(0, columnInfo);

			SQLCloseCursor(hStmt);
			SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
		}
	}
	else {
		AfxMessageBox(_T("연결 실패"));
	}

	db.Close();
}


void CSchema::OnLbnSelchangeDataList()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
