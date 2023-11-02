// rule_Explanation.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication2.h"
#include "rule_Explanation.h"
#include "afxdialogex.h"


// rule_Explanation 대화 상자

IMPLEMENT_DYNAMIC(rule_Explanation, CDialogEx)

rule_Explanation::rule_Explanation(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_rule_Explanation, pParent)
{

}

rule_Explanation::~rule_Explanation()
{
}

void rule_Explanation::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(rule_Explanation, CDialogEx)
END_MESSAGE_MAP()


// rule_Explanation 메시지 처리기
