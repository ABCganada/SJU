#pragma once


// CInput1 대화 상자

class CInput1 : public CDialogEx
{
	DECLARE_DYNAMIC(CInput1)

public:
	CInput1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CInput1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = InputPage1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_inputText;
	CEdit m_input;
	afx_msg void OnBnClickedButton2();
};

