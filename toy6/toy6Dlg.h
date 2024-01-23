
// toy6Dlg.h : ��� ����
//

#pragma once
using namespace std;

namespace _SIGN
{
	enum { 
		NORMAL =0,PLUS,MINUS,MULTI,DIVIDE,PLUS2,MINUS2,MULTI2,DIVIDE2
	// 0 + - x % / +2 -2 x2 %2 (2���� ������ ��½� ���̴� �ڸ��� �ٲ�)
	};
}

// Ctoy6Dlg ��ȭ ����
class Ctoy6Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	Ctoy6Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TOY6_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// ���� ��ư 0 ~ 9
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
	// + - x �� ��ȣ ��ư
	afx_msg void OnBnClickedButtonplus();
	afx_msg void OnBnClickedButtonminus();
	afx_msg void OnBnClickedButtonmulti();
	afx_msg void OnBnClickedButtondivide();
	// del ��ư
	afx_msg void OnBnClickedButtondel();
	// reset ��ư
	afx_msg void OnBnClickedButtonreset();
	// dot ��ư
	afx_msg void OnBnClickedButtondot();
	// - ��ư
	afx_msg void OnBnClickedButtonreverse();
	// = ��ư
	afx_msg void OnBnClickedButtonequals();
	
	// ��Ģ���� ���� �Լ�
	// int num => _SIGN:: 
	// NORMAL =0,PLUS,MINUS,MULTI,DIVIDE,PLUS2,MINUS2,MULTI2,DIVIDE2
	// 0 + - x % / +2 -2 x2 %2 (2���� ������ ��½� ���̴� �ڸ��� �ٲ�)
	void Calculator(int num);

private:
	CFont newFont;
	CFont newFont2;
	CString sign; // ǥ�ÿ�
	CString result;// ��� �����
	CString zero; // �ʱ�ȭ�� 0
	CString num1; // ���Ŀ� �� ��1
	CString num2; // ���Ŀ� �� ��2
	CString BigRes; // ����ǥ�� ū â
	CString SmRes;	// ����â
	CString war1; // ���ǵ��� ���� ���
	CString war2; // 0���� ������ �����ϴ�
	int signController; // ��ȣ ��������
	int plusState; // +
	int minusState; // -
	int multiState; // *
	int divideState; // %
	int signFlag; // - ��ȣ �Ѱ� ���� ����ġ
};
