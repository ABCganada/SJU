#pragma once


// CInsert 대화 상자

class CInsert : public CDialogEx
{
	DECLARE_DYNAMIC(CInsert)

public:
	CInsert(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CInsert();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = InsertPage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
