#pragma once


// CUpdateTap2 대화 상자

class CUpdateTap2 : public CDialogEx
{
	DECLARE_DYNAMIC(CUpdateTap2)

public:
	CUpdateTap2(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CUpdateTap2();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = UpdateTap2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CListBox m_dataList;
	afx_msg void OnBnClickedButton2();
};
