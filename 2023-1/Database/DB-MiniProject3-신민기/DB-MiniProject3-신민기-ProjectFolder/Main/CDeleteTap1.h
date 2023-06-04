#pragma once


// CDeleteTap1 대화 상자

class CDeleteTap1 : public CDialogEx
{
	DECLARE_DYNAMIC(CDeleteTap1)

public:
	CDeleteTap1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDeleteTap1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = DeleteTap1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_data_list;
	afx_msg void OnBnClickedButton2();
	CEdit m_input;
	CString m_inputText;
	afx_msg void OnBnClickedButton1();
};
