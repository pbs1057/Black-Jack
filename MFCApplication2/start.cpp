// start.cpp: 구현 파일
//

#include "pch.h"
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "start.h"
#include "afxdialogex.h"
#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>
using namespace std;

// start 대화 상자

IMPLEMENT_DYNAMIC(start, CDialogEx)

start::start(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_start, pParent)
{

}

start::~start()
{
}

void start::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, p_card_1, p_card_one);
	DDX_Control(pDX, p_card_2, p_card_two);
	DDX_Control(pDX, p_card_3, p_card_three);
	DDX_Control(pDX, p_card_4, p_card_four);
	DDX_Control(pDX, p_card_5, p_card_five);
	DDX_Control(pDX, d_card_1, d_card_one);
	DDX_Control(pDX, d_card_2, d_card_two);
	DDX_Control(pDX, d_card_3, d_card_three);
	DDX_Control(pDX, d_card_4, d_card_four);
	DDX_Control(pDX, d_card_5, d_card_five);
	DDX_Control(pDX, d_card_num_10, d_num_10);
	DDX_Control(pDX, d_card_num_1, d_num_1);
	DDX_Control(pDX, p_card_num_1, p_num_1);
	DDX_Control(pDX, p_card_num_10, p_num_10);
}


BEGIN_MESSAGE_MAP(start, CDialogEx)

	ON_EN_CHANGE(IDC_EDIT1, &start::OnEnChangeEdit1)

	ON_BN_CLICKED(start_1, &start::clcked)
	ON_EN_CHANGE(IDC_EDIT2, &start::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON1, &start::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &start::OnBnClickedButton2)
	ON_BN_CLICKED(IDCANCEL, &start::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON3, &start::OnBnClickedButton3)

	
	ON_BN_CLICKED(IDC_BUTTON4, &start::OnBnClickedButton4)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// start 메시지 처리기
int x, y;
int dealer = 0;						//딜러의 카드의 총합계
int player_1 = 0;					//플레이어의 카드의 총합계
int  number_1 = 0, number_2 = 0;	//카드 배열 인덱스 변수
int save = 0;						//딜러의 카드를 배열에 저장하고 출력을 위한 인덱스 변수
int save_2 = 0;						//플레이어의 카드를 배열에 저장하고 출력을 위한 인덱스 변수
int add = 0;						//플레이어가 카드를 더받을지에 대한 변수
int betting = 0;					//플레이어의 베팅을 위한변수
int sum = 0;
int money;			     //플레이어의 자본저장
int type = 0; //   딜러가이기면 1,플레이어가이기면 2, 비기면 3
int count_bitmap = 0;
static int temp_check = 0;
static int temp_sp = 0;
string card[4][13] = { {"S_A","S_2","S_3","S_4","S_5","S_6","S_7","S_8","S_9","S_10","S_J","S_Q","S_K" }, //스페이드
 						{"D_A","D_2","D_3","D_4","D_5","D_6","D_7","D_8","D_9","D_10","D_J","D_Q","D_K" }, // 다이아
						{"H_A","H_2","H_3","H_4","H_5","H_6","H_7","H_8","H_9","H_10","H_J","H_Q","H_K" }, // 하트
						{"C_A","C_2","C_3","C_4","C_5","C_6","C_7","C_8","C_9","C_10","C_J","C_Q","C_K" } }; // 클로버

string dealer_card[10];
string player_card[10];
string temp = { " " };

int bitmap_card();
int bitmap_card_d();
int num_bit(int score);
int pay_bat_player(string card_pay[], int x);
int change_player(string card[][13], int x, int y) {   // 스트링으로받은 플레이어 카드를 int로 봐꾸는 함수

	int sum = 0;
	int ace = 0;
	if (card[x][y] == "S_2" || card[x][y] == "D_2" || card[x][y] == "H_2" || card[x][y] == "C_2") sum = 2;

	else if (card[x][y] == "S_3" || card[x][y] == "D_3" || card[x][y] == "H_3" || card[x][y] == "C_3") sum = 3;

	else if (card[x][y] == "S_4" || card[x][y] == "D_4" || card[x][y] == "H_4" || card[x][y] == "C_4") sum = 4;

	else if (card[x][y] == "S_5" || card[x][y] == "D_5" || card[x][y] == "H_5" || card[x][y] == "C_5") sum = 5;

	else if (card[x][y] == "S_6" || card[x][y] == "D_6" || card[x][y] == "H_6" || card[x][y] == "C_6") sum = 6;

	else if (card[x][y] == "S_7" || card[x][y] == "D_7" || card[x][y] == "H_7" || card[x][y] == "C_7") sum = 7;

	else if (card[x][y] == "S_8" || card[x][y] == "D_8" || card[x][y] == "H_8" || card[x][y] == "C_8") sum = 8;

	else if (card[x][y] == "S_9" || card[x][y] == "D_9" || card[x][y] == "H_9" || card[x][y] == "C_9") sum = 9;

	else if (card[x][y] == "S_10" || card[x][y] == "D_10" || card[x][y] == "H_10" || card[x][y] == "C_10") sum = 10;

	else if (card[x][y] == "S_J" || card[x][y] == "D_J" || card[x][y] == "H_J" || card[x][y] == "C_J") sum = 10;

	else if (card[x][y] == "S_Q" || card[x][y] == "D_Q" || card[x][y] == "H_Q" || card[x][y] == "C_Q") sum = 10;

	else if (card[x][y] == "S_K" || card[x][y] == "D_K" || card[x][y] == "H_K" || card[x][y] == "C_K") sum = 10;

	else if (card[x][y] == "S_A" || card[x][y] == "D_A" || card[x][y] == "H_A" || card[x][y] == "C_A") sum = 0;
	
	return sum;
}

int change_dealer(string card[][13], int x, int y) { // 스트링으로받은 딜러 카드를 int로 봐꾸는 함수

	int sum = 0;
	int ace = 0;
	if (card[x][y] == "S_2" || card[x][y] == "D_2" || card[x][y] == "H_2" || card[x][y] == "C_2") sum = 2;

	else if (card[x][y] == "S_3" || card[x][y] == "D_3" || card[x][y] == "H_3" || card[x][y] == "C_3") sum = 3;

	else if (card[x][y] == "S_4" || card[x][y] == "D_4" || card[x][y] == "H_4" || card[x][y] == "C_4") sum = 4;

	else if (card[x][y] == "S_5" || card[x][y] == "D_5" || card[x][y] == "H_5" || card[x][y] == "C_5") sum = 5;

	else if (card[x][y] == "S_6" || card[x][y] == "D_6" || card[x][y] == "H_6" || card[x][y] == "C_6") sum = 6;

	else if (card[x][y] == "S_7" || card[x][y] == "D_7" || card[x][y] == "H_7" || card[x][y] == "C_7") sum = 7;

	else if (card[x][y] == "S_8" || card[x][y] == "D_8" || card[x][y] == "H_8" || card[x][y] == "C_8") sum = 8;

	else if (card[x][y] == "S_9" || card[x][y] == "D_9" || card[x][y] == "H_9" || card[x][y] == "C_9") sum = 9;

	else if (card[x][y] == "S_10" || card[x][y] == "D_10" || card[x][y] == "H_10" || card[x][y] == "C_10") sum = 10;

	else if (card[x][y] == "S_J" || card[x][y] == "D_J" || card[x][y] == "H_J" || card[x][y] == "C_J") sum = 10;

	else if (card[x][y] == "S_Q" || card[x][y] == "D_Q" || card[x][y] == "H_Q" || card[x][y] == "C_Q") sum = 10;

	else if (card[x][y] == "S_K" || card[x][y] == "D_K" || card[x][y] == "H_K" || card[x][y] == "C_K") sum = 10;

	else if (card[x][y] == "S_A" || card[x][y] == "D_A" || card[x][y] == "H_A" || card[x][y] == "C_A") {

		if (dealer + 11 <= 21) {

			sum = 11;
		}
		else {

			sum = 1;
		}
	}
	return sum;
}

void check(int *x, int *y) { // 배열을 하나씩 이동시켜줌
	int x_1, y_1;
	srand((unsigned)time(NULL));
	if (*y == 12 && *x == 3) {
		*y = 0;
		*x = 0;

		AfxMessageBox(_T("카드 셔플중입니다."));
		for (int i = 0; i < 4; i++) {        //카드를 섞어줌
			for (int j = 0; j < 13; j++) {
				x_1 = rand() % 4;
				y_1 = rand() % 13;

				temp = card[i][j];

				card[i][j] = card[x_1][y_1];

				card[x_1][y_1] = temp;
				
			}
		}

	}
	if (*y == 12) {
		*y = 0;
		*x = *x + 1;
	}
	else {

		*y = *y + 1;

	}
}

void delay(clock_t n) // 딜레이 함수

{

	clock_t start = clock();

	while (clock() - start < n);

}


void start::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void start::OnEnChangeEdit2()
{

	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void end_1(int dealer_t, int player_t) {
	if (dealer_t > 21 && player_t <= 21) {

		AfxMessageBox(_T("딜러 21초과 플레이어승"));



		type = 2;

	}
	else if (player_t > 21 && dealer_t <= 21) {

		AfxMessageBox(_T("플레이어 21초과 딜러승"));

		type = 1;
	}
	else if ((player_t > 21 && dealer > 21) || player_t == dealer_t) {

		AfxMessageBox(_T("무승부"));

		type = 3;
	}

	else if (player_t > dealer_t) {

		AfxMessageBox(_T("플레이어 승"));

		type = 2;
	}
	else if (player_t < dealer_t) {

		AfxMessageBox(_T("딜러 승"));

		type = 1;
		// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	}


}

void start::end_2() {
	
	if (type == 1) {
		CString str;

		str.Format(_T("나의 금액 : %d"), money);
		GetDlgItem(IDC_EDIT4)->SetWindowText(str);
	}
	else if (type == 2) {
		money = money + sum * 2;
		CString str;

		str.Format(_T("나의 금액 : %d"), money);
		GetDlgItem(IDC_EDIT4)->SetWindowText(str);

	}
	else if (type == 3) {
		money = money + sum;
		CString str;

		str.Format(_T("나의 금액 : %d"), money);
		GetDlgItem(IDC_EDIT4)->SetWindowText(str);

	}

	if (money <= 0) {
		AfxMessageBox(_T("금액을 모두 잃으셨습니다. "));
		AfxMessageBox(_T("추가로 1000원이 지급됩니다."));
		money = 1000;
	}

	player_1 = 0;
	dealer = 0;
	save = 0;
	save_2 = 0;
	CString str;

	str.Format(_T("나의 금액 : %d"), money);
	GetDlgItem(IDC_EDIT4)->SetWindowText(str);
}


void start::clcked()     // 시작버튼
{
	
	if (temp_check == 0) {                            //처음 시작할때만 메인 다이얼로그에서 계정의 돈 정보를 가져옴
		money = ((CMFCApplication2Dlg*)GetParent())->menber_x;
		temp_check =1;
	}
	
	CString bet = _T("");

	GetDlgItem(IDC_EDIT2)->GetWindowText(bet);
	
	int bet_N;
	 
	bet_N = _ttoi(bet);

	if (bet == "") {
		MessageBox(_T("배팅금액을 입력해주세요"));
		
	}
	else if (save_2 != 0) {
		MessageBox(_T("게임이 진행중입니다."));

	}
	else if (bet_N > money) {

		MessageBox(_T("현재가지고있는 금액보다 배팅금액이 큽니다"));
	}
	else {

		AfxMessageBox(_T("게임을 시작하겠습니다"));
		GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
		CString str;
		
		money = money - bet_N;
		sum = bet_N;
		CString msg;
		msg.Format(_T("%d \r\n배팅금액 : %d"), money ,bet_N);
		
		GetDlgItem(IDC_EDIT4)->SetWindowText(_T("나의금액 : ")+msg);
		srand((unsigned)time(NULL));
		if (temp_sp == 0) {
			MessageBox(_T("카드 셔플중입니다."));
			temp_sp = 1;
			for (int i = 0; i < 4; i++) {        //카드를 섞어줌
				for (int j = 0; j < 13; j++) {
					x = rand() % 4;
					y = rand() % 13;

					temp = card[i][j];

					card[i][j] = card[x][y];

					card[x][y] = temp;
				}
			}
		}
		dealer = change_dealer(card, number_1, number_2);      //딜러의 카드를 받음
		dealer_card[save] = card[number_1][number_2];                // 딜러카드 배열에 받은 카드를 저장
		
		int t = bitmap_card_d();
		HBITMAP hbit;
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_CARD_BACK));
		d_card_one.SetBitmap(hbit);
		save++;                                                      //카드받은 숫자를 계산
		check(&number_1, &number_2);                                 //다음 카드를 받기위해 check 함수로 변수의 숫자를 옮겨줌

		dealer = dealer + change_dealer(card, number_1, number_2);
		dealer_card[save] = card[number_1][number_2];

		delay(500);
		t = bitmap_card_d();
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		d_card_two.SetBitmap(hbit);

		save++;
		check(&number_1, &number_2);

		player_1 = player_1 + change_player(card, number_1, number_2);
		player_card[save_2] = card[number_1][number_2];

		delay(500);
		t = bitmap_card();
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		p_card_one.SetBitmap(hbit);

		save_2++;
		check(&number_1, &number_2);

		player_1 = player_1 + change_player(card, number_1, number_2);
		player_card[save_2] = card[number_1][number_2];

		delay(500);
		t = bitmap_card();
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		p_card_two.SetBitmap(hbit);

		save_2++;
		check(&number_1, &number_2);

		if (player_card[0] == "S_A" || player_card[0] == "D_A" || player_card[0] == "H_A" || player_card[0] == "C_A" ) {
			int temp;
			int nmsg = AfxMessageBox(_T("A카드가 나왔습니다 확인 = 1 , 취소 = 11"), MB_OKCANCEL | MB_ICONSTOP);

			if (nmsg == 1) {

				temp = 1;

			}
			else {
				temp = 11;
			}

			player_1 = player_1 + temp;
		}

		if (player_card[1] == "S_A" || player_card[1] == "D_A" || player_card[1] == "H_A" || player_card[1] == "C_A") {
			int temp;
			int nmsg = AfxMessageBox(_T("A카드가 나왔습니다 확인 = 1 , 취소 = 11"), MB_OKCANCEL | MB_ICONSTOP);

			if (nmsg == 1) {

				temp = 1;

			}
			else {
				temp = 11;
			}

			player_1 = player_1 + temp;
		}
		CString msg_3;

		t = num_bit(player_1 % 10);
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		p_num_1.SetBitmap(hbit);
		t = num_bit(player_1 / 10);
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		p_num_10.SetBitmap(hbit);
	}

	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	




void start::OnBnClickedButton1()      //hit 버튼
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (save_2 == 5) {

		MessageBox(_T("카드를 더이상 받으실수 없습니다."));
	}
	else if (save_2 == 0) {

		MessageBox(_T("게임 시작 전입니다."));
	}
	else {
		player_1 = player_1 + change_player(card, number_1, number_2);
		player_card[save_2] = card[number_1][number_2];

		int t = bitmap_card();
		HBITMAP hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));

		if (save_2 == 2) {
			p_card_three.SetBitmap(hbit);
		}
		else if (save_2 == 3) {
			p_card_four.SetBitmap(hbit);
		}
		else if (save_2 == 4) {
			p_card_five.SetBitmap(hbit);
		}
		save_2++;
		check(&number_1, &number_2);

		if (player_card[save_2 - 1] == "S_A" || player_card[save_2 - 1] == "D_A" || player_card[save_2 - 1] == "H_A" || player_card[save_2 - 1] == "C_A") {
			int temp;
			int nmsg = AfxMessageBox(_T("A카드가 나왔습니다 확인 = 1 , 취소 = 11"), MB_OKCANCEL | MB_ICONSTOP);

			if (nmsg == 1) {

				temp = 1;

			}
			else {
				temp = 11;
			}

			player_1 = player_1 + temp;
		}
		t = num_bit(player_1 % 10);
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		p_num_1.SetBitmap(hbit);
		t = num_bit(player_1 / 10);
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		p_num_10.SetBitmap(hbit);

		if (player_1 > 21) {
			MessageBox(_T("bust!!!"));
			while (1) {

				if (dealer <= 16) {          //딜러의 카드의 합이 16이하면 카드를 더받음

					dealer = dealer + change_dealer(card, number_1, number_2);
					dealer_card[save] = card[number_1][number_2];
					save++;
					check(&number_1, &number_2);
				}
				else if (save == 5) {    //최대 5장까지만 받음

					break;
				}
				else {

					break;

				}
			}
			while (1) {
				int i = save;
				save = 0;
				if (save == 0) {
					int t_1 = bitmap_card_d();
					HBITMAP hbit;
					hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
					d_card_one.SetBitmap(hbit);
					save++;
				}
				if (save == i)break;
				if (save == 1) {
					int t_1 = bitmap_card_d();
					HBITMAP hbit;
					hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
					d_card_two.SetBitmap(hbit);
					save++;
				}
				if (save == i)break;
				if (save == 2) {
					int t_1 = bitmap_card_d();
					HBITMAP hbit;
					hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
					d_card_three.SetBitmap(hbit);
					save++;
					
				}
				if (save == i)break;
				if (save == 3) {
					int t_1 = bitmap_card_d();
					HBITMAP hbit;
					hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
					d_card_four.SetBitmap(hbit);
					save++;
				}
				if (save == i)break;
				if (save == 4) {
					int t_1 = bitmap_card_d();
					HBITMAP hbit;
					hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
					d_card_five.SetBitmap(hbit);
					save++;
				}
				if (save == i)break;
			}

			t = num_bit(dealer % 10);
			hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
			d_num_1.SetBitmap(hbit);
			t = num_bit(dealer / 10);
			hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
			d_num_10.SetBitmap(hbit);

			end_1(dealer, player_1);
			start::end_2();
			hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(0));
			p_card_one.SetBitmap(hbit);
			p_card_two.SetBitmap(hbit);
			p_card_three.SetBitmap(hbit);
			p_card_four.SetBitmap(hbit);
			p_card_five.SetBitmap(hbit);

			d_card_one.SetBitmap(hbit);
			d_card_two.SetBitmap(hbit);
			d_card_three.SetBitmap(hbit);
			d_card_four.SetBitmap(hbit);
			d_card_five.SetBitmap(hbit);

			hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_0));
			d_num_1.SetBitmap(hbit);
			d_num_10.SetBitmap(hbit);
			p_num_1.SetBitmap(hbit);
			p_num_10.SetBitmap(hbit);
		}
	}
}


void start::OnBnClickedButton2() //stay
{
	if(save_2 == 0){
	MessageBox(_T("게임 시작 전입니다."));
	}
	else {
		while (1) {

			if (dealer <= 16) {          //딜러의 카드의 합이 16이하면 카드를 더받음

				dealer = dealer + change_dealer(card, number_1, number_2);
				dealer_card[save] = card[number_1][number_2];
				save++;
				check(&number_1, &number_2);
			}
			else if (save == 5) {    //  최대 5장까지만 허용

				break;

			}
			else {

				break;

			}
		}
		while (1) {
			int i = save;
			save = 0;
			if (save == 0) {
				int t_1 = bitmap_card_d();
				HBITMAP hbit;
				hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
				d_card_one.SetBitmap(hbit);
				save++;
			}
			if (save == i)break;
			if (save == 1) {
				int t_1 = bitmap_card_d();
				HBITMAP hbit;
				hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
				d_card_two.SetBitmap(hbit);
				save++;
			}
			if (save == i)break;
			if (save == 2) {
				int t_1 = bitmap_card_d();
				HBITMAP hbit;
				hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
				d_card_three.SetBitmap(hbit);
				save++;

			}
			if (save == i)break;
			if (save == 3) {
				int t_1 = bitmap_card_d();
				HBITMAP hbit;
				hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
				d_card_four.SetBitmap(hbit);
				save++;

			}
			if (save == i)break;
			if (save == 4) {
				int t_1 = bitmap_card_d();
				HBITMAP hbit;
				hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
				d_card_five.SetBitmap(hbit);
				save++;
			}
			if (save == i)break;
		}
		int t = num_bit(dealer % 10);
		HBITMAP hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		d_num_1.SetBitmap(hbit);
		t = num_bit(dealer / 10);
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		d_num_10.SetBitmap(hbit);

		end_1(dealer, player_1);
		start::end_2();
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(0));
		p_card_one.SetBitmap(hbit);
		p_card_two.SetBitmap(hbit);
		p_card_three.SetBitmap(hbit);
		p_card_four.SetBitmap(hbit);
		p_card_five.SetBitmap(hbit);

		d_card_one.SetBitmap(hbit);
		d_card_two.SetBitmap(hbit);
		d_card_three.SetBitmap(hbit);
		d_card_four.SetBitmap(hbit);
		d_card_five.SetBitmap(hbit);


		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_0));
		d_num_1.SetBitmap(hbit);
		d_num_10.SetBitmap(hbit);
		p_num_1.SetBitmap(hbit);
		p_num_10.SetBitmap(hbit);
	}
}

void start::OnBnClickedCancel()
{
	char* id = ((CMFCApplication2Dlg*)GetParent())->menber_id;

	FILE* fp, *fp_2;
	char m_id[256];
	char m_pass[256];
	char m_money[256];
	char *temp_f;
	
	fp = fopen("data_all.txt", "r");
	fp_2 = fopen("data_all_2.txt", "w");

	while (1) {

		fscanf(fp, "%s %s %s", m_id, m_pass, m_money);

		if (!feof(fp) == 0) {
			break;
		}
		
		int a = strcmp(id, m_id);
		if (a == 0 ){
		
			temp_f = (char*)malloc(256);
			_itoa(money, temp_f, 10);
			
			fprintf(fp_2, "%s %s %s \n", m_id, m_pass, temp_f);
			free(temp_f);
			
		}
		else {
			fprintf(fp_2, "%s %s %s \n", m_id, m_pass, m_money);
		}
		
	
	}
	fclose(fp);
	fclose(fp_2);
	fp_2 = fopen("data_all_2.txt", "r");
	fp = fopen("data_all.txt", "w");

	while (1) {

		fscanf(fp_2, "%s %s %s", m_id, m_pass, m_money);

		if (!feof(fp_2) == 0) {
			break;
		}
		fprintf(fp, "%s %s %s \n", m_id, m_pass, m_money);

		
	}
	fclose(fp);
	fclose(fp_2);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void start::OnBnClickedButton3()        // 더블다운
{
	if (save_2 != 2) {
		MessageBox(_T(" 게임시작 전이거나 카드가 두장 초과임으로 더블다운을 하실수없습니다."));

	}
	else {
		while (1) {

			if (dealer <= 16) {          //딜러의 카드의 합이 16이하면 카드를 더받음

				dealer = dealer + change_dealer(card, number_1, number_2);
				dealer_card[save] = card[number_1][number_2];
				save++;
				check(&number_1, &number_2);
			}
			else if (save == 5) {

				break;

			}
			else {
				break;

			}
		}
		while (1) {
			int i = save;
			save = 0;
			if (save == 0) {
				int t_1 = bitmap_card_d();
				HBITMAP hbit;
				hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
				d_card_one.SetBitmap(hbit);
				save++;
			}
			if (save == i)break;
			if (save == 1) {
				int t_1 = bitmap_card_d();
				HBITMAP hbit;
				hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
				d_card_two.SetBitmap(hbit);
				save++;
			}
			if (save == i)break;
			if (save == 2) {
				int t_1 = bitmap_card_d();
				HBITMAP hbit;
				hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
				d_card_three.SetBitmap(hbit);
				save++;

			}
			if (save == i)break;
			if (save == 3) {
				int t_1 = bitmap_card_d();
				HBITMAP hbit;
				hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
				d_card_four.SetBitmap(hbit);
				save++;

			}
			if (save == i)break;
			if (save == 4) {
				int t_1 = bitmap_card_d();
				HBITMAP hbit;
				hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t_1));
				d_card_five.SetBitmap(hbit);
				save++;
			}
			if (save == i)break;
		}


		player_1 = player_1 + change_player(card, number_1, number_2);
		player_card[save_2] = card[number_1][number_2];

		
		int t = bitmap_card();
		HBITMAP hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		p_card_three.SetBitmap(hbit);

		if (player_card[2] == "S_A" || player_card[2] == "D_A" || player_card[2] == "H_A" || player_card[2] == "C_A") {
			int temp;
			int nmsg = AfxMessageBox(_T("A카드가 나왔습니다 확인 = 1 , 취소 = 11"), MB_OKCANCEL | MB_ICONSTOP);

			if (nmsg == 1) {

				temp = 1;

			}
			else {
				temp = 11;
			}

			player_1 = player_1 + temp;
		}
		save_2++;
		check(&number_1, &number_2);


		money = money - sum;
		sum = sum * 2;

		t = num_bit(player_1 % 10);
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		p_num_1.SetBitmap(hbit);
		t = num_bit(player_1 / 10);
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		p_num_10.SetBitmap(hbit);

		t = num_bit(dealer % 10);
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		d_num_1.SetBitmap(hbit);

		t = num_bit(dealer / 10);
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		d_num_10.SetBitmap(hbit);

		end_1(dealer, player_1);
		start::end_2();

		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(0));
		p_card_one.SetBitmap(hbit);
		p_card_two.SetBitmap(hbit);
		p_card_three.SetBitmap(hbit);
		p_card_four.SetBitmap(hbit);
		p_card_five.SetBitmap(hbit);

		d_card_one.SetBitmap(hbit);
		d_card_two.SetBitmap(hbit);
		d_card_three.SetBitmap(hbit);
		d_card_four.SetBitmap(hbit);
		d_card_five.SetBitmap(hbit);


		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_0));
		d_num_1.SetBitmap(hbit);
		d_num_10.SetBitmap(hbit);
		p_num_1.SetBitmap(hbit);
		p_num_10.SetBitmap(hbit);
	}
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void start::OnBnClickedButton4() //pay bat
{
	
	if (temp_check == 0) {                            //처음 시작할때만 메인 다이얼로그에서 계정의 돈 정보를 가져옴
		money = ((CMFCApplication2Dlg*)GetParent())->menber_x;
		temp_check = 1;
	}

	CString bet = _T("");

	GetDlgItem(IDC_EDIT2)->GetWindowText(bet);

	int bet_N;

	bet_N = _ttoi(bet);
	if (save_2 != 0) {

		MessageBox(_T("카드를 받고난 후 Pay Bat은 할수없습니다."));
	}
	 else if (bet == "") {
		MessageBox(_T("배팅금액을 입력해주세요"));

	}
	else if (bet_N > money) {

		MessageBox(_T("현재가지고있는 금액보다 배팅금액이 큽니다"));
	}
	
	else {

		AfxMessageBox(_T("Pay Bat을 시작하겠습니다"));
		GetDlgItem(IDC_EDIT2)->SetWindowText(_T(""));
		CString str;

		money = money - bet_N;
		sum = bet_N;
		CString msg;
		msg.Format(_T("%d \r\n배팅금액 : %d"), money, bet_N);

		GetDlgItem(IDC_EDIT4)->SetWindowText(_T("나의금액 : ") + msg);
		srand((unsigned)time(NULL));
		if (temp_sp == 0) {
			MessageBox(_T("카드 셔플중입니다."));
			temp_sp = 1;
			for (int i = 0; i < 4; i++) {        //카드를 섞어줌
				for (int j = 0; j < 13; j++) {
					x = rand() % 3 + 1;
					y = rand() % 12 + 1;

					temp = card[i][j];

					card[i][j] = card[x][y];

					card[x][y] = temp;
				}
			}
		}

		player_1 = player_1 + change_player(card, number_1, number_2);
		player_card[save_2] = card[number_1][number_2];
		int t = bitmap_card_d();
		HBITMAP hbit;
		t = bitmap_card();
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		p_card_one.SetBitmap(hbit);

		save_2++;
		check(&number_1, &number_2);

		player_1 = player_1 + change_player(card, number_1, number_2);
		player_card[save_2] = card[number_1][number_2];
		delay(500);
		t = bitmap_card();
		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(t));
		p_card_two.SetBitmap(hbit);

		save_2++;
		check(&number_1, &number_2);
		int same_1 = pay_bat_player(player_card, 0);
		int same_2 = pay_bat_player(player_card, 1);
		if (same_1 == same_2) {

			MessageBox(_T("Pay Bat 성공 !!!"));
			money = money + sum * 11;

		}
		else {
			MessageBox(_T("Pay Bat 실패 !!!"));
		}
		if (money <= 0) {
			AfxMessageBox(_T("금액을 모두 잃으셨습니다. "));
			exit(0);

		}
		
		

		hbit = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(0));
		p_card_one.SetBitmap(hbit);
		p_card_two.SetBitmap(hbit);

		str.Format(_T("나의 금액 : %d"), money);
		GetDlgItem(IDC_EDIT4)->SetWindowText(str);

		dealer, player_1 = 0;
		save = 0;
		save_2 = 0;

		
		
	}
	
	
}

int bitmap_card() {

	if (player_card[save_2] == "S_A") {

		return IDB_S_ACE;
	}
	else if (player_card[save_2] == "S_2") {

		return IDB_S_2;
	}
	else if (player_card[save_2] == "S_3") {

		return IDB_S_3;
	}
	else if (player_card[save_2] == "S_4") {

		return IDB_S_4;
	}
	else if (player_card[save_2] == "S_5") {

		return IDB_S_5;
	}
	else if (player_card[save_2] == "S_6") {

		return IDB_S_6;
	}
	else if (player_card[save_2] == "S_7") {

		return IDB_S_7;
	}
	else if (player_card[save_2] == "S_8") {

		return IDB_S_8;
	}
	else if (player_card[save_2] == "S_9") {
		return IDB_S_9;
	}
	else if (player_card[save_2] == "S_10") {

		return IDB_S_10;
	}
	else if (player_card[save_2] == "S_K") {

		return IDB_S_K;
	}
	else if (player_card[save_2] == "S_Q") {

		return IDB_S_Q;
	}
	else if (player_card[save_2] == "S_J") {

		return IDB_S_J;
	}
	else if (player_card[save_2] == "D_A") {

		return IDB_D_ACE;
	}
	else if (player_card[save_2] == "D_2") {

		return IDB_D_2;
	}
	else if (player_card[save_2] == "D_3") {

		return IDB_D_3;
	}
	else if (player_card[save_2] == "D_4") {

		return IDB_D_4;
	}
	else if (player_card[save_2] == "D_5") {

		return IDB_D_5;
	}
	else if (player_card[save_2] == "D_6") {

		return IDB_D_6;
	}
	else if (player_card[save_2] == "D_7") {

		return IDB_D_7;
	}
	else if (player_card[save_2] == "D_8") {

		return IDB_D_8;
	}
	else if (player_card[save_2] == "D_9") {
		return IDB_D_9;
	}
	else if (player_card[save_2] == "D_10") {

		return IDB_D_10;
	}
	else if (player_card[save_2] == "D_K") {

		return IDB_D_K;
	}
	else if (player_card[save_2] == "D_Q") {

		return IDB_D_Q;
	}
	else if (player_card[save_2] == "D_J") {

		return IDB_D_J;
	}
	else if (player_card[save_2] == "H_A") {

		return IDB_H_ACE;
	}
	else if (player_card[save_2] == "H_2") {

		return IDB_H_2;
	}
	else if (player_card[save_2] == "H_3") {

		return IDB_H_3;
	}
	else if (player_card[save_2] == "H_4") {

		return IDB_H_4;
	}
	else if (player_card[save_2] == "H_5") {

		return IDB_H_5;
	}
	else if (player_card[save_2] == "H_6") {

		return IDB_H_6;
	}
	else if (player_card[save_2] == "H_7") {

		return IDB_H_7;
	}
	else if (player_card[save_2] == "H_8") {

		return IDB_H_8;
	}
	else if (player_card[save_2] == "H_9") {
		return IDB_H_9;
	}
	else if (player_card[save_2] == "H_10") {

		return IDB_H_10;
	}
	else if (player_card[save_2] == "H_K") {

		return IDB_H_K;
	}
	else if (player_card[save_2] == "H_Q") {

		return IDB_H_Q;
	}
	else if (player_card[save_2] == "H_J") {

		return IDB_H_J;
	}
	else if (player_card[save_2] == "C_A") {

		return IDB_C_ACE;
	}
	else if (player_card[save_2] == "C_2") {

		return IDB_C_2;
	}
	else if (player_card[save_2] == "C_3") {

		return IDB_C_3;
	}
	else if (player_card[save_2] == "C_4") {

		return IDB_C_4;
	}
	else if (player_card[save_2] == "C_5") {

		return IDB_C_5;
	}
	else if (player_card[save_2] == "C_6") {

		return IDB_C_6;
	}
	else if (player_card[save_2] == "C_7") {

		return IDB_C_7;
	}
	else if (player_card[save_2] == "C_8") {

		return IDB_C_8;
	}
	else if (player_card[save_2] == "C_9") {
		return IDB_C_9;
	}
	else if (player_card[save_2] == "C_10") {

		return IDB_C_10;
	}
	else if (player_card[save_2] == "C_K") {

		return IDB_C_K;
	}
	else if (player_card[save_2] == "C_Q") {

		return IDB_C_Q;
	}
	else if (player_card[save_2] == "C_J") {

		return IDB_C_J;
	}
}

int bitmap_card_d() {

	if (dealer_card[save] == "S_A") {

		return IDB_S_ACE;
	}
	else if (dealer_card[save] == "S_2") {

		return IDB_S_2;
	}
	else if (dealer_card[save] == "S_3") {

		return IDB_S_3;
	}
	else if (dealer_card[save] == "S_4") {

		return IDB_S_4;
	}
	else if (dealer_card[save] == "S_5") {

		return IDB_S_5;
	}
	else if (dealer_card[save] == "S_6") {

		return IDB_S_6;
	}
	else if (dealer_card[save] == "S_7") {

		return IDB_S_7;
	}
	else if (dealer_card[save] == "S_8") {

		return IDB_S_8;
	}
	else if (dealer_card[save] == "S_9") {
		return IDB_S_9;
	}
	else if (dealer_card[save] == "S_10") {

		return IDB_S_10;
	}
	else if (dealer_card[save] == "S_K") {

		return IDB_S_K;
	}
	else if (dealer_card[save] == "S_Q") {

		return IDB_S_Q;
	}
	else if (dealer_card[save] == "S_J") {

		return IDB_S_J;
	}
	else if (dealer_card[save] == "D_A") {

		return IDB_D_ACE;
	}
	else if (dealer_card[save] == "D_2") {

		return IDB_D_2;
	}
	else if (dealer_card[save] == "D_3") {

		return IDB_D_3;
	}
	else if (dealer_card[save] == "D_4") {

		return IDB_D_4;
	}
	else if (dealer_card[save] == "D_5") {

		return IDB_D_5;
	}
	else if (dealer_card[save] == "D_6") {

		return IDB_D_6;
	}
	else if (dealer_card[save] == "D_7") {

		return IDB_D_7;
	}
	else if (dealer_card[save] == "D_8") {

		return IDB_D_8;
	}
	else if (dealer_card[save] == "D_9") {
		return IDB_D_9;
	}
	else if (dealer_card[save] == "D_10") {

		return IDB_D_10;
	}
	else if (dealer_card[save] == "D_K") {

		return IDB_D_K;
	}
	else if (dealer_card[save] == "D_Q") {

		return IDB_D_Q;
	}
	else if (dealer_card[save] == "D_J") {

		return IDB_D_J;
	}
	else if (dealer_card[save] == "H_A") {

		return IDB_H_ACE;
	}
	else if (dealer_card[save] == "H_2") {

		return IDB_H_2;
	}
	else if (dealer_card[save] == "H_3") {

		return IDB_H_3;
	}
	else if (dealer_card[save] == "H_4") {

		return IDB_H_4;
	}
	else if (dealer_card[save] == "H_5") {

		return IDB_H_5;
	}
	else if (dealer_card[save] == "H_6") {

		return IDB_H_6;
	}
	else if (dealer_card[save] == "H_7") {

		return IDB_H_7;
	}
	else if (dealer_card[save] == "H_8") {

		return IDB_H_8;
	}
	else if (dealer_card[save] == "H_9") {
		return IDB_H_9;
	}
	else if (dealer_card[save] == "H_10") {

		return IDB_H_10;
	}
	else if (dealer_card[save] == "H_K") {

		return IDB_H_K;
	}
	else if (dealer_card[save] == "H_Q") {

		return IDB_H_Q;
	}
	else if (dealer_card[save] == "H_J") {

		return IDB_H_J;
	}
	else if (dealer_card[save] == "C_A") {

		return IDB_C_ACE;
	}
	else if (dealer_card[save] == "C_2") {

		return IDB_C_2;
	}
	else if (dealer_card[save] == "C_3") {

		return IDB_C_3;
	}
	else if (dealer_card[save] == "C_4") {

		return IDB_C_4;
	}
	else if (dealer_card[save] == "C_5") {

		return IDB_C_5;
	}
	else if (dealer_card[save] == "C_6") {

		return IDB_C_6;
	}
	else if (dealer_card[save] == "C_7") {

		return IDB_C_7;
	}
	else if (dealer_card[save] == "C_8") {

		return IDB_C_8;
	}
	else if (dealer_card[save] == "C_9") {
		return IDB_C_9;
	}
	else if (dealer_card[save] == "C_10") {

		return IDB_C_10;
	}
	else if (dealer_card[save] == "C_K") {

		return IDB_C_K;
	}
	else if (dealer_card[save] == "C_Q") {

		return IDB_C_Q;
	}
	else if (dealer_card[save] == "C_J") {

		return IDB_C_J;
	}


}

int num_bit(int score) {

	if (score == 0) {

		return IDB_0;
	}
	else if (score == 1) {

		return IDB_1;
	}
	else if (score == 2) {

		return IDB_2;
	}
	else if (score == 3) {

		return IDB_3;
	}
	else if (score == 4) {

		return IDB_4;
	}
	else if (score == 5) {

		return IDB_5;
	}
	else if (score == 6) {

		return IDB_6;
	}
	else if (score == 7) {

		return IDB_7;
	}
	else if (score == 8) {

		return IDB_8;
	}
	else if (score == 9) {

		return IDB_9;
	}

}

int pay_bat_player(string card_pay[], int x) {   // 스트링으로받은 플레이어 카드를 int로 봐꾸는 함수

	int sum = 0;
	int ace = 0;
	if (card_pay[x] == "S_2" || card_pay[x] == "D_2" || card_pay[x] == "H_2" || card_pay[x] == "C_2") sum = 2;

	else if (card_pay[x] == "S_3" || card_pay[x] == "D_3" || card_pay[x] == "H_3" || card_pay[x] == "C_3") sum = 3;

	else if (card_pay[x] == "S_4" || card_pay[x] == "D_4" || card_pay[x] == "H_4" || card_pay[x] == "C_4") sum = 4;

	else if (card_pay[x] == "S_5" || card_pay[x] == "D_5" || card_pay[x] == "H_5" || card_pay[x] == "C_5") sum = 5;

	else if (card_pay[x] == "S_6" || card_pay[x] == "D_6" || card_pay[x] == "H_6" || card_pay[x] == "C_6") sum = 6;

	else if (card_pay[x] == "S_7" || card_pay[x] == "D_7" || card_pay[x] == "H_7" || card_pay[x] == "C_7") sum = 7;

	else if (card_pay[x] == "S_8" || card_pay[x] == "D_8" || card_pay[x] == "H_8" || card_pay[x] == "C_8") sum = 8;

	else if (card_pay[x] == "S_9" || card_pay[x] == "D_9" || card_pay[x] == "H_9" || card_pay[x] == "C_9") sum = 9;

	else if (card_pay[x] == "S_10" || card_pay[x] == "D_10" || card_pay[x] == "H_10" || card_pay[x] == "C_10") sum = 11;

	else if (card_pay[x] == "S_J" || card_pay[x] == "D_J" || card_pay[x] == "H_J" || card_pay[x] == "C_J") sum = 12;

	else if (card_pay[x] == "S_Q" || card_pay[x] == "D_Q" || card_pay[x] == "H_Q" || card_pay[x] == "C_Q") sum = 13;

	else if (card_pay[x] == "S_K" || card_pay[x] == "D_K" || card_pay[x] == "H_K" || card_pay[x] == "C_K") sum = 14;

	else if (card_pay[x] == "S_A" || card_pay[x] == "D_A" || card_pay[x] == "H_A" || card_pay[x] == "C_A") sum = 15;

	return sum;
}



