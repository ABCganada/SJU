#pragma once


// CUpdateTap4 대화 상자

class CUpdateTap4 : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdateTap4)

public:
	CUpdateTap4(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CUpdateTap4();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = UpdateTap4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CListBox m_dataList;
	afx_msg void OnBnClickedButton1();
};
