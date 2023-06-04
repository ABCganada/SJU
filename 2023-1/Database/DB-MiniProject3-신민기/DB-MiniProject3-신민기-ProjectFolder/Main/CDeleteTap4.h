#pragma once


// CDeleteTap4 대화 상자

class CDeleteTap4 : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteTap4)

public:
	CDeleteTap4(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDeleteTap4();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = DeleteTap4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_dataList;
	afx_msg void OnBnClickedButton1();
	CEdit m_input;
	CString m_inputText;
	afx_msg void OnBnClickedButton2();
};
