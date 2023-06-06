#pragma once


// CUpdateTap3 대화 상자

class CUpdateTap3 : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdateTap3)

public:
	CUpdateTap3(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CUpdateTap3();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = UpdateTap3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_dataList;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
