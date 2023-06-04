#pragma once


// CInsertTap1 대화 상자

class CInsertTap1 : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertTap1)

public:
	CInsertTap1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CInsertTap1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = InsertTap1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString m_inputText1;
	CString m_inputText2;
	CString m_inputText3;
	CString m_inputText4;
	CString m_inputText5;
	CEdit m_input1;
	CEdit m_input2;
	CEdit m_input3;
	CEdit m_input4;
	CEdit m_input5;
};
