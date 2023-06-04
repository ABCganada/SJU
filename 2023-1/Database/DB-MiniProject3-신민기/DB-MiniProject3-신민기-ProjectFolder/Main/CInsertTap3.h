#pragma once


// CInsertTap3 대화 상자

class CInsertTap3 : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertTap3)

public:
	CInsertTap3(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CInsertTap3();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = InsertTap3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_input1;
	CEdit m_input2;
	CEdit m_input3;
	CEdit m_input4;
	CEdit m_input5;
	CEdit m_input6;
	CEdit m_input7;
	CString m_inputText1;
	CString m_inputText2;
	CString m_inputText3;
	CString m_inputText4;
	CString m_inputText5;
	CString m_inputText6;
	CString m_inputText7;
	afx_msg void OnBnClickedOk();
};
