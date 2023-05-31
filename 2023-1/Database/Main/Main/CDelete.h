#pragma once


// CDelete 대화 상자

class CDelete : public CDialogEx
{
	DECLARE_DYNAMIC(CDelete)

public:
	CDelete(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDelete();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = DeletePage };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
