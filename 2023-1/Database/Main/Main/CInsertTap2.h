#pragma once


// CInsertTap2 대화 상자

class CInsertTap2 : public CDialogEx
{
	DECLARE_DYNAMIC(CInsertTap2)

public:
	CInsertTap2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CInsertTap2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = InsertTap2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString m_inputText1;
	CString m_inputText2;
	CString m_inputText3;
	CString m_inputText4;
	CEdit m_input1;
	CEdit m_input2;
	CEdit m_input3;
	CEdit m_input4;
	afx_msg void OnBnClickedOk();
};
