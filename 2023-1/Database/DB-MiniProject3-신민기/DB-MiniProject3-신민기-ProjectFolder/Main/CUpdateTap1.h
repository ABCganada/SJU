#pragma once


// CUpdateTap1 대화 상자

class CUpdateTap1 : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdateTap1)

public:
	CUpdateTap1(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CUpdateTap1();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = UpdateTap1 };
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
	afx_msg void OnBnClickedButton3();
};
