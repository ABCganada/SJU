#pragma once


// CSelect 대화 상자

class CSelect : public CDialogEx
{
	DECLARE_DYNAMIC(CSelect)

public:
	CSelect(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CSelect();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = SelectPage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CListBox m_dataList;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
