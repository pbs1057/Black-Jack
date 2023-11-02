#pragma once


// rule_Explanation 대화 상자

class rule_Explanation : public CDialogEx
{
	DECLARE_DYNAMIC(rule_Explanation)

public:
	rule_Explanation(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~rule_Explanation();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
