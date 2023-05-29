// CCustom.cpp: 구현 파일
//

#include "pch.h"
#include "Main.h"
#include "CCustom.h"
#include "afxdialogex.h"


// CCustom 대화 상자

IMPLEMENT_DYNAMIC(CCustom, CDialogEx)

CCustom::CCustom(CWnd* pParent /*=nullptr*/)
	: CDialogEx(CustomPage, pParent)
{

}

CCustom::~CCustom()
{
}

void CCustom::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_dataList);
	DDX_Control(pDX, IDC_EDIT1, m_input);
}


BEGIN_MESSAGE_MAP(CCustom, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CCustom::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCustom 메시지 처리기


void CCustom::OnBnClickedButton1()
{
    // TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
    m_input.GetWindowTextW(m_inputText);
    CString str = m_inputText;

    CDatabase db;
    BOOL bRet = db.OpenEx(_T("DSN=DB02_Server; uid=KIM; PWD=aaaa;"), CDatabase::noOdbcDialog);

    if (bRet) {
        if (str.Left(6).CompareNoCase(_T("select")) == 0) {
            CStringArray dataArray;
            CString strSQL;
            strSQL.Format(_T("%s;"), str);

            CRecordset recSet(&db);
            recSet.Open(CRecordset::forwardOnly, strSQL, CRecordset::readOnly);

            int filedCnt = recSet.GetODBCFieldCount();

            while (!recSet.IsEOF()) {
                CString data;
                for (int i = 0; i < filedCnt; i++) {
                    CString fieldValue;
                    recSet.GetFieldValue(i, fieldValue);
                    data += fieldValue + _T(" ");
                }
                dataArray.Add(data);
                recSet.MoveNext();
            }

            recSet.Close();

            // Clear the existing items in the list box
            m_dataList.ResetContent();

            // Add the retrieved data to the list box
            for (int i = 0; i < dataArray.GetSize(); i++) {
                m_dataList.AddString(dataArray[i]);
            }
        }
        else {
            // Execute the non-SELECT SQL statement
            CString strSQL;
            strSQL.Format(_T("%s;"), str);
            db.ExecuteSQL(strSQL);
        }
    }
    else {
        AfxMessageBox(_T("DB 연결 실패"));
    }

    db.Close();
}
