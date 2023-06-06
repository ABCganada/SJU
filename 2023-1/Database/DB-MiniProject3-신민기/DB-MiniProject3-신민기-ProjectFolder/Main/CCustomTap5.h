#pragma once


// CCustomTap5 대화 상자

class CCustomTap5 : public CDialogEx
{
	DECLARE_DYNAMIC(CCustomTap5)

public:
	CCustomTap5(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCustomTap5();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = CustomTap5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_input1;
	CEdit m_input2;
	CListBox m_dataList;
	CString m_inputText1;
	CString m_inputText2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
