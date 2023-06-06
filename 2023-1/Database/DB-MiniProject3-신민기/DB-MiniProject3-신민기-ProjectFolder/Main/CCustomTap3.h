#pragma once


// CCustomTap3 대화 상자

class CCustomTap3 : public CDialogEx
{
	DECLARE_DYNAMIC(CCustomTap3)

public:
	CCustomTap3(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCustomTap3();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = CustomTap3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_dataList;
	CEdit m_input;
	CString m_inputText;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
