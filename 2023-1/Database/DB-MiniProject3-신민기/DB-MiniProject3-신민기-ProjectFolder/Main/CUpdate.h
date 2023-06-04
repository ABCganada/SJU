#pragma once


// CUpdate 대화 상자

class CUpdate : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdate)

public:
	CUpdate(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CUpdate();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = UpdatePage };
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
