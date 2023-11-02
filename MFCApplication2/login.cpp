// login.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication2.h"
#include "login.h"
#include "afxdialogex.h"
#include<string>
#include<iostream>

#include<stdlib.h>
using namespace std;



// login 대화 상자

IMPLEMENT_DYNAMIC(login, CDialogEx)

login::login(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_login, pParent)
{

}

login::~login()
{
}

void login::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(login, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &login::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &login::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &login::OnBnClickedButton3)
END_MESSAGE_MAP()


// login 메시지 처리기

char* CString2char(CString& str) {
	long len = str.GetLength();
	len = len * 2;
	char* szTemp = new char[len + 1];
	memset(szTemp, 0, len + 1);
	USES_CONVERSION;
	strcpy(szTemp, T2A(str));


	return szTemp;
}
int check = 0;

int overlap = 0;

CString str_id, str_pass1, str_pass2, str_data;

void login::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	
	CString temp = _T(" 10000 \r\n");

	GetDlgItemText(IDC_EDIT1, str_id);
	GetDlgItemText(IDC_EDIT2, str_pass1);
	GetDlgItemText(IDC_EDIT3, str_pass2);
	
	 if (str_id == "") {

		MessageBox(_T("아이디를 입력해주세요"));
	}
	else if (str_pass1 == "") {

		MessageBox(_T("비밀번호를 입력해주세요"));
	}
	else if (str_pass2 == "") {

		MessageBox(_T("비밀번호 확인을 입력해주세요"));
	}
	else if (str_pass1 != str_pass2) {

		 MessageBox(_T("비밀번호가 틀립니다."));
	 }
	else if (overlap == 0) {

		 MessageBox(_T("아이디 중복체크를 해주세요."));
	 }

	else if (overlap == 1) {

		 MessageBox(_T("중복된 아이디입니다."));
	 }

	else {
		
		str_data = str_id + " " + str_pass1 +temp;
		char* sen = CString2char(str_data);

		FILE* fp;
		fp = fopen("data_all.txt", "a");
		fprintf(fp, "%s", sen);
		fclose(fp);
		check = 1;
		MessageBox(_T("회원가입성공"));
	
		CDialogEx::OnCancel();
	}
	
}


void login::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	
	
	if (check == 1)
	{
		MessageBox(_T("회원가입완료 "));
		CDialogEx::OnCancel();
	}
	else {
		int NewExit = MessageBox(_T("아직 회원가입이 완료되지 않았습니다.\n회원가입을 종료하시겠습니까?"), _T("회원가입"), MB_YESNO);
		if (NewExit == 6) {
			CDialogEx::OnCancel();

		}
	}
}


void login::OnBnClickedButton3()
{
	FILE* fp;
	char m_id[256];
	char m_pass[256];
	char m_money[256];
	
	fp = fopen("data_all.txt", "r");
	GetDlgItemText(IDC_EDIT1, str_id);
	char* sen = CString2char(str_id);
	while (1) {
		
		fscanf(fp, "%s %s %s", m_id, m_pass, m_money);
		
		if (!feof(fp) == 0 ) {
			overlap = 2;
			fclose(fp);
			MessageBox(_T("사용가능한 아이디입니다. "));
			break;
		}
		if (strcmp(sen, "") == 0) {
			overlap = 0;

			MessageBox(_T("아이디를 입력해주세요"));
			fclose(fp);
			break;
		}
		if (strcmp(sen, m_id) == 0) {
			overlap = 1;
			
			MessageBox(_T("중복된 아이디가있습니다"));
			fclose(fp);
			break;
		}
	}
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
