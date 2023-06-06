#pragma once


// CSchema 대화 상자

class CSchema : public CDialog
{
	DECLARE_DYNAMIC(CSchema)

public:
	CSchema(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSchema();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = SchemaPage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedReadBtn();
	CListBox m_dataList;
	afx_msg void OnBnClickedReadBtn2();
	afx_msg void OnBnClickedReadBtn3();
	afx_msg void OnBnClickedReadBtn4();
	afx_msg void OnBnClickedReadBtn5();
	afx_msg void OnLbnSelchangeDataList();
	CMFCShellListCtrl m_dataShell;
};
const char* get_data_type_in_string(SQLSMALLINT dataType);