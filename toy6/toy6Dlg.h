
// toy6Dlg.h : 헤더 파일
//

#pragma once
using namespace std;

namespace _SIGN
{
	enum { 
		NORMAL =0,PLUS,MINUS,MULTI,DIVIDE,PLUS2,MINUS2,MULTI2,DIVIDE2
	// 0 + - x % / +2 -2 x2 %2 (2붙은 연산은 출력시 보이는 자리가 바뀜)
	};
}

// Ctoy6Dlg 대화 상자
class Ctoy6Dlg : public CDialogEx
{
// 생성입니다.
public:
	Ctoy6Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TOY6_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// 숫자 버튼 0 ~ 9
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton0();
	// + - x ÷ 부호 버튼
	afx_msg void OnBnClickedButtonplus();
	afx_msg void OnBnClickedButtonminus();
	afx_msg void OnBnClickedButtonmulti();
	afx_msg void OnBnClickedButtondivide();
	// del 버튼
	afx_msg void OnBnClickedButtondel();
	// reset 버튼
	afx_msg void OnBnClickedButtonreset();
	// dot 버튼
	afx_msg void OnBnClickedButtondot();
	// - 버튼
	afx_msg void OnBnClickedButtonreverse();
	// = 버튼
	afx_msg void OnBnClickedButtonequals();
	
	// 사칙연산 내장 함수
	// int num => _SIGN:: 
	// NORMAL =0,PLUS,MINUS,MULTI,DIVIDE,PLUS2,MINUS2,MULTI2,DIVIDE2
	// 0 + - x % / +2 -2 x2 %2 (2붙은 연산은 출력시 보이는 자리가 바뀜)
	void Calculator(int num);

private:
	CFont newFont;
	CFont newFont2;
	CString sign; // 표시용
	CString result;// 계산 결과값
	CString zero; // 초기화에 0
	CString num1; // 계산식에 들어갈 값1
	CString num2; // 계산식에 들어갈 값2
	CString BigRes; // 숫자표시 큰 창
	CString SmRes;	// 작은창
	CString war1; // 정의되지 않은 결과
	CString war2; // 0으로 나눌수 없습니다
	int signController; // 부호 눌렀을시
	int plusState; // +
	int minusState; // -
	int multiState; // *
	int divideState; // %
	int signFlag; // - 부호 켜고 끄는 스위치
};
