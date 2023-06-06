#pragma once


// CCustomTap4 대화 상자

class CCustomTap4 : public CDialogEx
{
	DECLARE_DYNAMIC(CCustomTap4)

public:
	CCustomTap4(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCustomTap4();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = CustomTap4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_dataList;
	afx_msg void OnBnClickedButton1();
	CEdit m_input1;
	CEdit m_input2;
	CString m_inputText1;
	CString m_inputText2;
	afx_msg void OnBnClickedButton2();
};
