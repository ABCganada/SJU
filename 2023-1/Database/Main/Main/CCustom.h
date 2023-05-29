#pragma once


// CCustom 대화 상자

class CCustom : public CDialogEx
{
	DECLARE_DYNAMIC(CCustom)

public:
	CCustom(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CCustom();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = CustomPage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_dataList;
	CEdit m_input;
	CString m_inputText;
	afx_msg void OnBnClickedButton1();
};
