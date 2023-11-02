#pragma once


// start 대화 상자

class start : public CDialogEx
{
	DECLARE_DYNAMIC(start)

public:
	void end_2();
	

public:
	start(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~start();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_start };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClicked1();
	afx_msg void clcked();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnStnClickedcard1();
	
	CStatic p_card_one;
	CStatic p_card_two;
	CStatic p_card_three;
	CStatic p_card_four;
	CStatic p_card_five;
	
	CStatic d_card_one;
	CStatic d_card_two;
	CStatic d_card_three;
	CStatic d_card_four;
	CStatic d_card_five;
//	CStatic d_card_num_1;
//	CStatic d_card_num_10;
//	CStatic p_card_num_1;
//	CStatic p_card_num_10;
	CStatic d_num_10;
	CStatic d_num_1;
//	CStatic p_num_10;
	CStatic p_num_1;
	CStatic p_num_10;
	afx_msg void OnBnClickedButton4();
	
};
