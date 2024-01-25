
// toy6Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "toy6.h"
#include "toy6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ctoy6Dlg ��ȭ ����



Ctoy6Dlg::Ctoy6Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TOY6_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ctoy6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Ctoy6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_1, &Ctoy6Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, &Ctoy6Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, &Ctoy6Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON_plus, &Ctoy6Dlg::OnBnClickedButtonplus)
	ON_BN_CLICKED(IDC_BUTTON_4, &Ctoy6Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, &Ctoy6Dlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, &Ctoy6Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, &Ctoy6Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, &Ctoy6Dlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, &Ctoy6Dlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_0, &Ctoy6Dlg::OnBnClickedButton0)
	ON_BN_CLICKED(IDC_BUTTON_minus, &Ctoy6Dlg::OnBnClickedButtonminus)
	ON_BN_CLICKED(IDC_BUTTON_multi, &Ctoy6Dlg::OnBnClickedButtonmulti)
	ON_BN_CLICKED(IDC_BUTTON_divide, &Ctoy6Dlg::OnBnClickedButtondivide)
	ON_BN_CLICKED(IDC_BUTTON_del, &Ctoy6Dlg::OnBnClickedButtondel)
	ON_BN_CLICKED(IDC_BUTTON_reset, &Ctoy6Dlg::OnBnClickedButtonreset)
	ON_BN_CLICKED(IDC_BUTTON_dot, &Ctoy6Dlg::OnBnClickedButtondot)
	ON_BN_CLICKED(IDC_BUTTON_reverse, &Ctoy6Dlg::OnBnClickedButtonreverse)
	ON_BN_CLICKED(IDC_BUTTON_equals, &Ctoy6Dlg::OnBnClickedButtonequals)
END_MESSAGE_MAP()


// Ctoy6Dlg �޽��� ó����


BOOL Ctoy6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	sign = "";
	zero = "0";
	SetDlgItemText(IDC_EDIT_result, zero);
	SetDlgItemText(IDC_EDIT_minires, zero);
	result = "0";
	signController = 0; // ��ȣ ī��Ʈ
	plusState = 0; // ��Ʈ�ѽ���ġ
	minusState = 0; // 
	multiState = 0; // 
	divideState = 0; //
	signFlag = 0;
	war1 = "���ǵ��� ���� ����Դϴ�.";
	war2 = "0���� ������ �����ϴ�.";


	// ��Ʈ ����
	CFont *currentFont = this->GetFont();
	LOGFONT logFont;
	LOGFONT logFont2;
	currentFont->GetLogFont(&logFont);
	currentFont->GetLogFont(&logFont2);
	logFont.lfHeight = 90;
	logFont.lfWeight = FW_SEMIBOLD;
	logFont2.lfHeight = 50;
	logFont2.lfWeight = FW_BOLD;

	this->newFont.CreateFontIndirectA(&logFont);
	this->newFont2.CreateFontIndirectA(&logFont2);
	this->GetDlgItem(IDC_EDIT_result)->SetFont(&this->newFont);
	this->GetDlgItem(IDC_EDIT_minires)->SetFont(&this->newFont2);
	this->GetDlgItem(IDC_BUTTON_0)->SetFont(&this->newFont);
	this->GetDlgItem(IDC_BUTTON_1)->SetFont(&this->newFont);
	this->GetDlgItem(IDC_BUTTON_2)->SetFont(&this->newFont);
	this->GetDlgItem(IDC_BUTTON_3)->SetFont(&this->newFont);
	this->GetDlgItem(IDC_BUTTON_4)->SetFont(&this->newFont);
	this->GetDlgItem(IDC_BUTTON_5)->SetFont(&this->newFont);
	this->GetDlgItem(IDC_BUTTON_6)->SetFont(&this->newFont);
	this->GetDlgItem(IDC_BUTTON_7)->SetFont(&this->newFont);
	this->GetDlgItem(IDC_BUTTON_8)->SetFont(&this->newFont);
	this->GetDlgItem(IDC_BUTTON_9)->SetFont(&this->newFont);
	this->GetDlgItem(IDC_BUTTON_del)->SetFont(&this->newFont2);
	this->GetDlgItem(IDC_BUTTON_divide)->SetFont(&this->newFont2);
	this->GetDlgItem(IDC_BUTTON_dot)->SetFont(&this->newFont2);
	this->GetDlgItem(IDC_BUTTON_equals)->SetFont(&this->newFont2);
	this->GetDlgItem(IDC_BUTTON_minus)->SetFont(&this->newFont2);
	this->GetDlgItem(IDC_BUTTON_multi)->SetFont(&this->newFont2);
	this->GetDlgItem(IDC_BUTTON_plus)->SetFont(&this->newFont2);
	this->GetDlgItem(IDC_BUTTON_reset)->SetFont(&this->newFont2);
	this->GetDlgItem(IDC_BUTTON_reverse)->SetFont(&this->newFont2);
	this->GetDlgItem(IDC_EDIT_sign)->SetFont(&this->newFont2);
	// ��Ʈ ���� end

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void Ctoy6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void Ctoy6Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR Ctoy6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// ���� 0~9 // ����κ� Button0�� ������
void Ctoy6Dlg::OnBnClickedButton1()
{
	CString num = "1";
	signFlag = 0;
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	if (BigRes == war1 || BigRes == war2 || SmRes == war1 || SmRes == war2)
	{
		OnBnClickedButtonreset();
	}
	if (signController != 1)
	{
		if (BigRes == "0" || BigRes == "-0")
		{
			int index = BigRes.Find('0');
			BigRes.Delete(index);
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
		else
		{
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
	}
	else
	{
		GetDlgItemText(IDC_EDIT_result, SmRes);
		int index = SmRes.Find('.');
		if (index != -1)
		{
			for (int i = SmRes.GetLength() - 1; i >= index; i--)
			{
				char c = SmRes.GetAt(i);
				if (c == '0' || c == '.')
				{
					SmRes.Delete(i);
					if (c == '.')
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		SetDlgItemText(IDC_EDIT_minires, SmRes);
		BigRes = num;
		SetDlgItemText(IDC_EDIT_result, BigRes);
		signController = 0;

	}
}
void Ctoy6Dlg::OnBnClickedButton2()
{
	CString num = "2";
	signFlag = 0;
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	if (BigRes == war1 || BigRes == war2 || SmRes == war1 || SmRes == war2)
	{
		OnBnClickedButtonreset();
	}
	if (signController != 1)
	{
		if (BigRes == "0" || BigRes == "-0")
		{
			int index = BigRes.Find('0');
			BigRes.Delete(index);
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
		else
		{
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
	}
	else
	{
		GetDlgItemText(IDC_EDIT_result, SmRes);
		int index = SmRes.Find('.');
		if (index != -1)
		{
			for (int i = SmRes.GetLength() - 1; i >= index; i--)
			{
				char c = SmRes.GetAt(i);
				if (c == '0' || c == '.')
				{
					SmRes.Delete(i);
					if (c == '.')
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		SetDlgItemText(IDC_EDIT_minires, SmRes);
		BigRes = num;
		SetDlgItemText(IDC_EDIT_result, BigRes);
		signController = 0;

		/*GetDlgItemText(IDC_EDIT_result, SmRes);
		SetDlgItemText(IDC_EDIT_minires, SmRes);
		SetDlgItemText(IDC_EDIT_result, BigRes);
		BigRes = num;
		SetDlgItemText(IDC_EDIT_result, BigRes);
		signController = 0;*/
	}
}
void Ctoy6Dlg::OnBnClickedButton3()
{
	CString num = "3";
	signFlag = 0;
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	if (BigRes == war1 || BigRes == war2 || SmRes == war1 || SmRes == war2)
	{
		OnBnClickedButtonreset();
	}
	if (signController != 1)
	{
		if (BigRes == "0" || BigRes == "-0")
		{
			int index = BigRes.Find('0');
			BigRes.Delete(index);
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
		else
		{
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
	}
	else
	{
		GetDlgItemText(IDC_EDIT_result, SmRes);
		int index = SmRes.Find('.');
		if (index != -1)
		{
			for (int i = SmRes.GetLength() - 1; i >= index; i--)
			{
				char c = SmRes.GetAt(i);
				if (c == '0' || c == '.')
				{
					SmRes.Delete(i);
					if (c == '.')
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		SetDlgItemText(IDC_EDIT_minires, SmRes);
		BigRes = num;
		SetDlgItemText(IDC_EDIT_result, BigRes);
		signController = 0;
	}

}
void Ctoy6Dlg::OnBnClickedButton4()
{
	CString num = "4";
	signFlag = 0;
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	if (BigRes == war1 || BigRes == war2 || SmRes == war1 || SmRes == war2)
	{
		OnBnClickedButtonreset();
	}
	if (signController != 1)
	{
		if (BigRes == "0" || BigRes == "-0")
		{
			int index = BigRes.Find('0');
			BigRes.Delete(index);
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
		else
		{
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
	}
	else
	{
		GetDlgItemText(IDC_EDIT_result, SmRes);
		int index = SmRes.Find('.');
		if (index != -1)
		{
			for (int i = SmRes.GetLength() - 1; i >= index; i--)
			{
				char c = SmRes.GetAt(i);
				if (c == '0' || c == '.')
				{
					SmRes.Delete(i);
					if (c == '.')
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		SetDlgItemText(IDC_EDIT_minires, SmRes);
		BigRes = num;
		SetDlgItemText(IDC_EDIT_result, BigRes);
		signController = 0;
	}

}
void Ctoy6Dlg::OnBnClickedButton5()
{
	CString num = "5";
	signFlag = 0;
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	if (BigRes == war1 || BigRes == war2 || SmRes == war1 || SmRes == war2)
	{
		OnBnClickedButtonreset();
	}
	if (signController != 1)
	{
		if (BigRes == "0" || BigRes == "-0")
		{
			int index = BigRes.Find('0');
			BigRes.Delete(index);
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
		else
		{
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
	}
	else
	{
		GetDlgItemText(IDC_EDIT_result, SmRes);
		int index = SmRes.Find('.');
		if (index != -1)
		{
			for (int i = SmRes.GetLength() - 1; i >= index; i--)
			{
				char c = SmRes.GetAt(i);
				if (c == '0' || c == '.')
				{
					SmRes.Delete(i);
					if (c == '.')
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		SetDlgItemText(IDC_EDIT_minires, SmRes);
		BigRes = num;
		SetDlgItemText(IDC_EDIT_result, BigRes);
		signController = 0;
	}

}
void Ctoy6Dlg::OnBnClickedButton6()
{
	CString num = "6";
	signFlag = 0;
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	if (BigRes == war1 || BigRes == war2 || SmRes == war1 || SmRes == war2)
	{
		OnBnClickedButtonreset();
	}
	if (signController != 1)
	{
		if (BigRes == "0" || BigRes == "-0")
		{
			int index = BigRes.Find('0');
			BigRes.Delete(index);
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
		else
		{
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
	}
	else
	{
		GetDlgItemText(IDC_EDIT_result, SmRes);
		int index = SmRes.Find('.');
		if (index != -1)
		{
			for (int i = SmRes.GetLength() - 1; i >= index; i--)
			{
				char c = SmRes.GetAt(i);
				if (c == '0' || c == '.')
				{
					SmRes.Delete(i);
					if (c == '.')
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		SetDlgItemText(IDC_EDIT_minires, SmRes);
		BigRes = num;
		SetDlgItemText(IDC_EDIT_result, BigRes);
		signController = 0;
	}

}
void Ctoy6Dlg::OnBnClickedButton7()
{
	CString num = "7";
	signFlag = 0;
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	if (BigRes == war1 || BigRes == war2 || SmRes == war1 || SmRes == war2)
	{
		OnBnClickedButtonreset();
	}
	if (signController != 1)
	{
		if (BigRes == "0" || BigRes == "-0")
		{
			int index = BigRes.Find('0');
			BigRes.Delete(index);
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
		else
		{
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
	}
	else
	{
		GetDlgItemText(IDC_EDIT_result, SmRes);
		int index = SmRes.Find('.');
		if (index != -1)
		{
			for (int i = SmRes.GetLength() - 1; i >= index; i--)
			{
				char c = SmRes.GetAt(i);
				if (c == '0' || c == '.')
				{
					SmRes.Delete(i);
					if (c == '.')
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		SetDlgItemText(IDC_EDIT_minires, SmRes);
		BigRes = num;
		SetDlgItemText(IDC_EDIT_result, BigRes);
		signController = 0;
	}

}
void Ctoy6Dlg::OnBnClickedButton8()
{
	CString num = "8";
	signFlag = 0;
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	if (BigRes == war1 || BigRes == war2 || SmRes == war1 || SmRes == war2)
	{
		OnBnClickedButtonreset();
	}
	if (signController != 1)
	{
		if (BigRes == "0" || BigRes == "-0")
		{
			int index = BigRes.Find('0');
			BigRes.Delete(index);
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
		else
		{
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
	}
	else
	{
		GetDlgItemText(IDC_EDIT_result, SmRes);
		int index = SmRes.Find('.');
		if (index != -1)
		{
			for (int i = SmRes.GetLength() - 1; i >= index; i--)
			{
				char c = SmRes.GetAt(i);
				if (c == '0' || c == '.')
				{
					SmRes.Delete(i);
					if (c == '.')
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		SetDlgItemText(IDC_EDIT_minires, SmRes);
		BigRes = num;
		SetDlgItemText(IDC_EDIT_result, BigRes);
		signController = 0;
	}

}
void Ctoy6Dlg::OnBnClickedButton9()
{
	CString num = "9";
	signFlag = 0;
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	if (BigRes == war1 || BigRes == war2 || SmRes == war1 || SmRes == war2)
	{
		OnBnClickedButtonreset();
	}
	if (signController != 1)
	{
		if (BigRes == "0" || BigRes == "-0")
		{
			int index = BigRes.Find('0');
			BigRes.Delete(index);
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
		else
		{
			BigRes += num;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
	}
	else
	{
		GetDlgItemText(IDC_EDIT_result, SmRes);
		int index = SmRes.Find('.');
		if (index != -1)
		{
			for (int i = SmRes.GetLength() - 1; i >= index; i--)
			{
				char c = SmRes.GetAt(i);
				if (c == '0' || c == '.')
				{
					SmRes.Delete(i);
					if (c == '.')
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		SetDlgItemText(IDC_EDIT_minires, SmRes);
		BigRes = num;
		SetDlgItemText(IDC_EDIT_result, BigRes);
		signController = 0;
	}

}
void Ctoy6Dlg::OnBnClickedButton0()
{
	CString num = "0";
	signFlag = 0;
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	if (BigRes == war1 || BigRes == war2 || SmRes == war1 || SmRes == war2)
	{   // ��� war1, war2 ��� ������ ��ư�� �ʱ�ȭ ������ �Էµ�
		OnBnClickedButtonreset();
	}
	if (signController != 1)
	{
		if (BigRes != "-0" && BigRes != "0")
		{
			BigRes += num; // ���ڿ� ���ϴ� ������� �Է�
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
	}
	else
	{	// ��ȣ�� ������ ���ο� ���� �Է��Ҷ�
		// Ȯ������ ���� �Է°��� ����ó��
		GetDlgItemText(IDC_EDIT_result, SmRes);
		int index = SmRes.Find('.');
		if (index != -1)  
		{
			for (int i = SmRes.GetLength() - 1; i >= index; i--)
			{
				char c = SmRes.GetAt(i);
				if (c == '0' || c == '.')
				{
					SmRes.Delete(i);
					if (c == '.')
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		SetDlgItemText(IDC_EDIT_minires, SmRes);
		BigRes = num;
		SetDlgItemText(IDC_EDIT_result, BigRes);
		signController = 0;
	}

}
// ���� 0~9 end
// plus ��ư
void Ctoy6Dlg::OnBnClickedButtonplus()
{
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	sign = "+";
	SetDlgItemText(IDC_EDIT_sign, sign);
	// ��ȣ + ���� ���� ���¿��� ���� ��ȣ or �ٸ� ��ȣ �������� ���� ��ȣ ������ ���� ��ȣ ���� ���
	// ����� �Ͼ�� ���̸� �ѹ� �Ͼ �Ŀ��� signController�� 1�� �ö�
	if (BigRes != "0" || SmRes != "0")
	{ // 11 ���� + ��ȣ + ���� + ��ȣ �ѹ� ����� ����Ǵ� �κ�
		if (plusState > 0 || minusState > 0 || multiState > 0 || divideState > 0)
		{
			if (plusState > 0 && signController == 0)
			{
				Calculator(_SIGN::PLUS2);
				plusState = 2;
				minusState = 0;
				multiState = 0;
				divideState = 0;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
			if (minusState > 0 && signController == 0)
			{
				Calculator(_SIGN::MINUS2);
				plusState = 2;
				minusState = 0;
				multiState = 0;
				divideState = 0;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
			if (multiState > 0 && signController == 0)
			{
				Calculator(_SIGN::MULTI2);
				plusState = 2;
				minusState = 0;
				multiState = 0;
				divideState = 0;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
			if (divideState > 0 && signController == 0)
			{
				Calculator(_SIGN::DIVIDE2);
				plusState = 2;
				minusState = 0;
				multiState = 0;
				divideState = 0;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
		}
	}

	//if (plusState == 2 && signController == 0) // + ��ư���δ� �ȵ��´�??
	//{
	//	Calculator(_SIGN::PLUS2);
	//	plusState = 2;
	//}

	if (minusState > 0 || multiState > 0 || divideState > 0)
	{

		//if (minusState == 1 && signController == 1 && SmRes != "0")//1
		//{
		//	Calculator(_SIGN::MINUS2);
		//	signController = 2;
		//}
		//if (multiState == 1 && signController == 1 && SmRes != "0")//2
		//{
		//	Calculator(_SIGN::MULTI2);
		//	signController = 2;
		//}
		//if (divideState == 1 && signController == 1 && SmRes != "0")//3 1,2,3 �ᱸ���� �κ��ε� 
		//{
		//	Calculator(_SIGN::DIVIDE2);
		//	signController = 2;
		//}

		// 22 ��ȣ������ ������ 1ȸ ����ѵ� ī���Ͱ� signController�� 1 �ö������ =(eqauls) ��ư�� ���� �ൿ����
		if ((signController == 1 && minusState > 0) || (signController == 1 && multiState > 0) || (signController == 1 && divideState > 0))
		{
			plusState = 2;
			minusState = 0;
			multiState = 0;
			divideState = 0;
		}
	} 
	// �ʱ�ȭ, ���α׷� ������ ù ��ȣ �������� ��ġ�� �κ�
	if (plusState != 2 && signController == 0)
	{
		signController = 1;
		plusState = 1;
	}
}
// plus ��ư end
// minus ��ư
void Ctoy6Dlg::OnBnClickedButtonminus()
{
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	sign = "-";
	SetDlgItemText(IDC_EDIT_sign, sign);
	if (BigRes != "0" || SmRes != "0")
	{
		if (plusState > 0 || minusState > 0 || multiState > 0 || divideState > 0)
		{
			if (plusState > 0 && signController == 0)
			{
				Calculator(_SIGN::PLUS2);
				plusState = 0;
				minusState = 2;
				multiState = 0;
				divideState = 0;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
			if (minusState > 0 && signController == 0)
			{
				Calculator(_SIGN::MINUS2);
				plusState = 0;
				minusState = 2;
				multiState = 0;
				divideState = 0;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
			if (multiState > 0 && signController == 0)
			{
				Calculator(_SIGN::MULTI2);
				plusState = 0;
				minusState = 2;
				multiState = 0;
				divideState = 0;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
			if (divideState > 0 && signController == 0)
			{
				Calculator(_SIGN::DIVIDE2);
				plusState = 0;
				minusState = 2;
				multiState = 0;
				divideState = 0;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
		}
	}

	// ���� + ��ȣ �ݺ��������θ� �۵�
	/*if (minusState == 2 && signController == 0)
	{
		Calculator(_SIGN::MINUS2);
		minusState = 2;
	}*/


	if (plusState > 0 || multiState > 0 || divideState > 0)
	{
		/*if (plusState == 1 && signController == 1 && SmRes != "0")
		{
			Calculator(_SIGN::PLUS2);
			signController = 2;
		}

		if (multiState == 1 && signController == 1 && SmRes != "0")
		{
			Calculator(_SIGN::MULTI2);
			signController = 2;
		}
		if (divideState == 1 && signController == 1 && SmRes != "0")
		{
			Calculator(_SIGN::DIVIDE2);
			signController = 2;
		}*/
		if ((signController == 1 && plusState > 0) || (signController == 1 && multiState > 0) || (signController == 1 && divideState > 0))
		{
			plusState = 0;
			minusState = 2;
			multiState = 0;
			divideState = 0;
		}
	}

	if (minusState != 2 && signController == 0)
	{
		signController = 1;
		minusState = 1;
	}
}
// minus ��ưend
// multi ��ư
void Ctoy6Dlg::OnBnClickedButtonmulti()
{
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	sign = "x";
	SetDlgItemText(IDC_EDIT_sign, sign);
	if (BigRes != "0" || SmRes != "0")
	{
		if (plusState > 0 || minusState > 0 || multiState > 0 || divideState > 0)
		{
			if (plusState > 0 && signController == 0)
			{
				Calculator(_SIGN::PLUS2);
				plusState = 0;
				minusState = 0;
				multiState = 2;
				divideState = 0;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
			if (minusState > 0 && signController == 0)
			{
				Calculator(_SIGN::MINUS2);
				plusState = 0;
				minusState = 0;
				multiState = 2;
				divideState = 0;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
			if (multiState > 0 && signController == 0)
			{
				Calculator(_SIGN::MULTI2);
				plusState = 0;
				minusState = 0;
				multiState = 2;
				divideState = 0;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
			if (divideState > 0 && signController == 0)
			{
				Calculator(_SIGN::DIVIDE2);
				plusState = 0;
				minusState = 0;
				multiState = 2;
				divideState = 0;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
		}
	}
	/*if (multiState == 2 && signController == 1)
	{
		GetDlgItemText(IDC_EDIT_result, BigRes);
		SetDlgItemText(IDC_EDIT_minires, BigRes);
	}*/
	/*if (multiState == 2 && signController == 0)
	{
		Calculator(_SIGN::MULTI2);
		multiState = 2;
	}*/

	if (plusState > 0 || minusState > 0 || divideState > 0)
	{
		/*if (plusState == 1 && signController == 1 && SmRes != "0")
		{
			Calculator(_SIGN::PLUS2);
			signController = 2;
		}
		if (minusState == 1 && signController == 1 && SmRes != "0")
		{
			Calculator(_SIGN::MINUS2);
			signController = 2;
		}
		if (divideState == 1 && signController == 1 && SmRes != "0")
		{
			Calculator(_SIGN::DIVIDE2);
			signController = 2;
		}*/
		if ((signController == 1 && plusState > 0) || (signController == 1 && minusState > 0) || (signController == 1 && divideState > 0))
		{
			plusState = 0;
			minusState = 0;
			multiState = 2;
			divideState = 0;

		}
	}

	if (multiState != 2 && signController == 0)
	{
		signController = 1;
		multiState = 1;
	}
}
// multi ��ư end
// divide ��ư
void Ctoy6Dlg::OnBnClickedButtondivide()
{
	sign = "��";
	SetDlgItemText(IDC_EDIT_sign, sign);
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	if (BigRes == "0" && SmRes == "0" && divideState == 1)
	{
		result.Format("%s", war1);
		signFlag = 2;
		SetDlgItemText(IDC_EDIT_result, result);
		result.Empty();
	}

	if (BigRes != "0" || SmRes != "0")
	{
		if (plusState > 0 || minusState > 0 || multiState > 0 || divideState > 0)
		{
			if (plusState > 0 && signController == 0)
			{
				Calculator(_SIGN::PLUS2);
				plusState = 0;
				minusState = 0;
				multiState = 0;
				divideState = 2;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
			if (minusState > 0 && signController == 0)
			{
				Calculator(_SIGN::MINUS2);
				plusState = 0;
				minusState = 0;
				multiState = 0;
				divideState = 2;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
			if (multiState > 0 && signController == 0)
			{
				Calculator(_SIGN::MULTI2);
				plusState = 0;
				minusState = 0;
				multiState = 0;
				divideState = 2;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
			if (divideState > 0 && signController == 0)
			{
				Calculator(_SIGN::DIVIDE2);
				plusState = 0;
				minusState = 0;
				multiState = 0;
				divideState = 2;
				signController = 1;
				GetDlgItemText(IDC_EDIT_result, BigRes);
				SetDlgItemText(IDC_EDIT_minires, BigRes);
			}
		}
	}
	/*if (divideState == 2 && signController == 1)
	{
		GetDlgItemText(IDC_EDIT_result, BigRes);
		SetDlgItemText(IDC_EDIT_minires, BigRes);
	}*/
	if (divideState == 2 && signController == 0)
	{
		Calculator(_SIGN::DIVIDE2);
		divideState = 2;
	}

	if (plusState > 0 || minusState > 0 || multiState > 0)
	{
		if (plusState == 1 && signController == 1 && SmRes != "0")
		{
			Calculator(_SIGN::PLUS2);
			signController = 2;
		}
		if (minusState == 1 && signController == 1 && SmRes != "0")
		{
			Calculator(_SIGN::MINUS2);
			signController = 2;
		}
		if (multiState == 1 && signController == 1 && SmRes != "0")
		{
			Calculator(_SIGN::MULTI2);
			signController = 2;
		}
		if ((signController == 1 && plusState > 0) || (signController == 1 && minusState > 0) || (signController == 1 && multiState > 0))
		{
			plusState = 0;
			minusState = 0;
			multiState = 0;
			divideState = 2;
		}
	}
	if (divideState != 2 && signController == 0)
	{
		signController = 1;
		divideState = 1;
	}
}
// divide ��ư end
// ����
void Ctoy6Dlg::Calculator(int num)
{

	GetDlgItemText(IDC_EDIT_result, num1);
	GetDlgItemText(IDC_EDIT_minires, num2);


	double DNUM1 = atof(num1);
	double DNUM2 = atof(num2);
	switch (num)
	{
	case 1: //PLUS // ���̴� ���� ��ȯ ���� �״�� ����. �ݺ��۾���
	{	
		double sum = DNUM1 + DNUM2;
		result.Format("%f", sum);
		int index = result.Find('.');
		for (int i = result.GetLength() - 1; i >= index; i--)
		{
			char c = result.GetAt(i);
			if (c == '0' || c == '.')
			{
				result.Delete(i);
				if (c == '.')
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		signFlag = 2;
		plusState = 1;
		signController = 1;
		BigRes = result;
		SetDlgItemText(IDC_EDIT_minires, num2);
		SetDlgItemText(IDC_EDIT_result, BigRes);
		break;
	}
	case 2: //MINUS // ���̴� ���� ��ȯ ���� �״�� ����. �ݺ��۾���
	{
		double sum = DNUM1 - DNUM2;
		result.Format("%f", sum);
		int index = result.Find('.');
		for (int i = result.GetLength() - 1; i >= index; i--)
		{
			char c = result.GetAt(i);
			if (c == '0' || c == '.')
			{
				result.Delete(i);
				if (c == '.')
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		BigRes = result;
		signFlag = 2;
		minusState = 1;
		signController = 1;
		SetDlgItemText(IDC_EDIT_minires, num2);
		SetDlgItemText(IDC_EDIT_result, BigRes);
		break;
	}
	case 3: //MULTI // ���̴� ���� ��ȯ ���� �״�� ����. �ݺ��۾���
	{
		double sum = DNUM1 * DNUM2;
		if (sum == 0)
		{
			result.Format("%d", sum);
			signFlag = 2;
			BigRes = result;
			SetDlgItemText(IDC_EDIT_result, BigRes);
			SetDlgItemText(IDC_EDIT_minires, BigRes);
			break;
		}
		result.Format("%f", sum);
		int index = result.Find('.');
		for (int i = result.GetLength() - 1; i >= index; i--)
		{
			char c = result.GetAt(i);
			if (c == '0' || c == '.')
			{
				result.Delete(i);
				if (c == '.')
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		BigRes = result;
		signFlag = 2;
		multiState = 1;
		signController = 1;
		SetDlgItemText(IDC_EDIT_minires, num2);
		SetDlgItemText(IDC_EDIT_result, BigRes);
		break;
	}
	case 4: //DIVIDE // ���̴� ���� ��ȯ ���� �״�� ����. �ݺ��۾���
	{
		double sum = DNUM1 / DNUM2;
		if (DNUM1 == 0 && DNUM2 == 0)
		{
			result.Format("%s", war1);
			signFlag = 2;
			SetDlgItemText(IDC_EDIT_result, result);
			result.Empty();
			break;
		}
		if ((DNUM1 == 0 && DNUM2 != 0) || (DNUM1 != 0 && DNUM2 == 0))
		{
			result.Format("%s", war2);
			signFlag = 2;
			SetDlgItemText(IDC_EDIT_result, result);
			result.Empty();
			break;
		}
		if (sum > 0.000001)
			result.Format("%f", sum);
		else
			result.Format("%e", sum);

		int index = result.Find('.');

		for (int i = result.GetLength() - 1; i >= index; i--)
		{
			char c = result.GetAt(i);
			if (c == '0' || c == '.')
			{
				result.Delete(i);
				if (c == '.')
				{
					break;
				}
			}
			else
			{
				break;
			}

		}
		BigRes = result;
		signFlag = 2;
		divideState = 1;
		signController = 1;
		SetDlgItemText(IDC_EDIT_minires, num2);
		SetDlgItemText(IDC_EDIT_result, BigRes);
		break;
	}
	case 5: //PLUS2 // ���߿� �Էµ� ���� ������ ����â���� �̵�
	{
		double sum = DNUM1 + DNUM2;
		result.Format("%f", sum);
		int index = result.Find('.');
		for (int i = result.GetLength() - 1; i >= index; i--)
		{
			char c = result.GetAt(i);
			if (c == '0' || c == '.')
			{
				result.Delete(i);
				if (c == '.')
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		BigRes = result;
		signFlag = 2;
		plusState = 1;
		signController = 1;
		SetDlgItemText(IDC_EDIT_minires, num1);
		SetDlgItemText(IDC_EDIT_result, BigRes);
		break;
	}
	case 6: // MINUS2 // ���߿� �Էµ� ���� ������ ����â���� �̵�
	{
		double sum = DNUM2 - DNUM1;
		result.Format("%f", sum);
		int index = result.Find('.');
		for (int i = result.GetLength() - 1; i >= index; i--)
		{
			char c = result.GetAt(i);
			if (c == '0' || c == '.')
			{
				result.Delete(i);
				if (c == '.')
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		BigRes = result;
		signFlag = 2;
		minusState = 1;
		signController = 1;
		SetDlgItemText(IDC_EDIT_minires, num1);
		SetDlgItemText(IDC_EDIT_result, BigRes);
		break;
	}
	case 7: // MUNTI2 // ���߿� �Էµ� ���� ������ ����â���� �̵�
	{
		double sum = DNUM1 * DNUM2;
		if (sum == 0)
		{
			result.Format("%d", sum);
			signFlag = 2;
			BigRes = result;
			SetDlgItemText(IDC_EDIT_result, BigRes);
			SetDlgItemText(IDC_EDIT_minires, BigRes);
			break;
		}
		result.Format("%f", sum);
		int index = result.Find('.');
		for (int i = result.GetLength() - 1; i >= index; i--)
		{
			char c = result.GetAt(i);
			if (c == '0' || c == '.')
			{
				result.Delete(i);
				if (c == '.')
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		BigRes = result;
		signFlag = 2;
		multiState = 1;
		signController = 1;
		SetDlgItemText(IDC_EDIT_minires, num1);
		SetDlgItemText(IDC_EDIT_result, BigRes);
		break;
	}
	case 8: // DIVIDE2 // ���߿� �Էµ� ���� ������ ����â���� �̵�
	{
		double sum = DNUM2 / DNUM1;
		if (DNUM1 == 0 && DNUM2 == 0) {
			result.Format("%s", war1);
			signFlag = 2;
			SetDlgItemText(IDC_EDIT_result, result);
			result.Empty();
			break;
		}

		if ((DNUM1 == 0 && DNUM2 != 0) || (DNUM1 != 0 && DNUM2 == 0))
		{
			result.Format("%s", war2);
			signFlag = 2;
			SetDlgItemText(IDC_EDIT_result, result);
			result.Empty();
			break;
		}

		if (sum > 0.000001)
			result.Format("%f", sum);
		else
			result.Format("%e", sum);

		int index = result.Find('.');
		for (int i = result.GetLength() - 1; i >= index; i--)
		{
			char c = result.GetAt(i);
			if (c == '0' || c == '.')
			{
				result.Delete(i);
				if (c == '.')
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		BigRes = result;
		signFlag = 2;
		divideState = 1;
		signController = 1;
		SetDlgItemText(IDC_EDIT_minires, num1);
		SetDlgItemText(IDC_EDIT_result, BigRes);
		break;
	}
	}
}
// ���� end
// del
void Ctoy6Dlg::OnBnClickedButtondel()
{
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	if (signController == 0)
	{	// ���� ������ ����
		GetDlgItemText(IDC_EDIT_result, BigRes);
		if (strlen(BigRes) == 1) 
		{   // ���� 1���������� delete ��ư �����ϸ� Empty() �Լ��� ���� 0�����ʱ�ȭ
			BigRes.Empty();
			SetDlgItemText(IDC_EDIT_result, zero);
		}
		else
		{
			BigRes.Delete(BigRes.GetLength() - 1);
			if (BigRes.GetAt(BigRes.GetLength() - 1) == '.')
				BigRes.Delete(BigRes.GetLength() - 1);
			SetDlgItemText(IDC_EDIT_result, BigRes);
			if (BigRes == '-' || BigRes == "-0")
			{ // �ϳ� �����µ� -, -0 ������ 0���� �ʱ�ȭ
				BigRes.Empty();
				signFlag = 0;
				SetDlgItemText(IDC_EDIT_result, zero);
			}
		}
	}
	if (BigRes == "0" && SmRes == "0")
	{
		OnBnClickedButtonreset();
	}


}
// del end
// reset
void Ctoy6Dlg::OnBnClickedButtonreset()
{
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	GetDlgItemText(IDC_EDIT_sign, sign);
	BigRes.Empty();
	SmRes.Empty();
	sign.Empty();
	SetDlgItemText(IDC_EDIT_result, zero);
	SetDlgItemText(IDC_EDIT_minires, zero);
	SetDlgItemText(IDC_EDIT_sign, sign);
	signFlag = 0;
	signController = 0;
	plusState = 0;
	minusState = 0;
	multiState = 0;
	divideState = 0;
	signFlag = 0;
}
// reset end
// . dot
void Ctoy6Dlg::OnBnClickedButtondot()
{
	CString	dot = ".";
	if (signFlag != 2)
	{
		GetDlgItemText(IDC_EDIT_result, BigRes);
		int isDot = 0;
		isDot = BigRes.Find('.');
		if (isDot == -1)
		{
			BigRes += dot;
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
	}
}
// .dot end
//  +/- ��ư
void Ctoy6Dlg::OnBnClickedButtonreverse()
{
	CString min = "-";
	int index = BigRes.Find('-');
	GetDlgItemText(IDC_EDIT_result, BigRes);
	if (index == -1)
	{
		if (signFlag == 0)
		{
			BigRes = min + BigRes;
			SetDlgItemText(IDC_EDIT_result, BigRes);
			signFlag = 1;
		}
	}
	else if (signFlag == 1)
	{
		BigRes.Delete(index);
		SetDlgItemText(IDC_EDIT_result, BigRes);
		signFlag = 0;
	}

	if (signFlag == 2)
	{

	}


}
//  +/- ��ư end
// = 
void Ctoy6Dlg::OnBnClickedButtonequals()
{
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	//PLUS
	if (plusState == 1)
	{
		if (signController == 1) // ���� ���� plus ������ = �ٷ�����
		{
			GetDlgItemText(IDC_EDIT_result, BigRes);
			SetDlgItemText(IDC_EDIT_minires, BigRes);
			Calculator(_SIGN::PLUS2);
			plusState = 2;
			signController = 1;
		}
		else // ���� + plus + ���� + = ������ plusState==1 && signController == 0�ϰ�� ����
		{
			Calculator(_SIGN::PLUS2);
			plusState = 2;
			signController = 1;
		}
	}
	else if (plusState == 2 && signController == 1 && SmRes == "0") // ����+ �ٸ���ȣ+ plus + =
	{
		GetDlgItemText(IDC_EDIT_result, BigRes);
		SetDlgItemText(IDC_EDIT_minires, BigRes);
		Calculator(_SIGN::PLUS2);
		plusState = 2;
		signController = 1;
	}
	else if (plusState == 2 && signController == 1) // = + plus + = 
	{
		Calculator(_SIGN::PLUS);
		plusState = 2;
		signController = 1;
	}
	else if (plusState == 2 && signController == 0) // plus + ���� + = 
	{
		Calculator(_SIGN::PLUS2);
		plusState = 2;
		signController = 1;
	}
	//PLUS��
	//MINUS
	if (minusState == 1)
	{
		if (signController == 1) // ���� + minus + = 
		{
			GetDlgItemText(IDC_EDIT_result, BigRes);
			SetDlgItemText(IDC_EDIT_minires, BigRes);
			Calculator(_SIGN::MINUS2);
			minusState = 2;
			signController = 1;
		}
		else // ���� + minus + ���� + = ������ minusState==1 && signController == 0�ϰ�� ����
		{
			Calculator(_SIGN::MINUS2);
			minusState = 2;
			signController = 1;
		}
	}
	else if (minusState == 2 && signController == 1 && SmRes == "0") // ����+ �ٸ���ȣ+ minus + =
	{
		GetDlgItemText(IDC_EDIT_result, BigRes);
		SetDlgItemText(IDC_EDIT_minires, BigRes);
		Calculator(_SIGN::MINUS2);
		minusState = 2;
		signController = 1;
	}
	else if (minusState == 2 && signController == 1) // = + minus + =
	{
		Calculator(_SIGN::MINUS);
		minusState = 2;
		signController = 1;
	}
	else if (minusState == 2 && signController == 0) // minus + ���� + =
	{
		Calculator(_SIGN::MINUS2);
		minusState = 2;
		signController = 1;
	}
	
	//MINUS��
	//MULTI
	if (multiState == 1)
	{
		if (signController == 1) // ���� ���� + ������ = �ٷ�����
		{
			GetDlgItemText(IDC_EDIT_result, BigRes);
			SetDlgItemText(IDC_EDIT_minires, BigRes);
			Calculator(_SIGN::MULTI2);
			plusState = 2;
			signController = 1;
		}
		else
		{
			Calculator(_SIGN::MULTI2);
			multiState = 2;
			signController = 1;
		}
	}
	else if (multiState == 2 && signController == 1 && SmRes == "0") // ���� + �ٸ���ȣ + multi + =
	{
		GetDlgItemText(IDC_EDIT_result, BigRes);
		SetDlgItemText(IDC_EDIT_minires, BigRes);
		Calculator(_SIGN::MULTI);
		multiState = 2;
		signController = 1;
	}
	else if (multiState == 2) // ���� + multi + =
	{
		Calculator(_SIGN::MULTI);
		multiState = 2;
		signController = 1;
	}
	
	//MULTI��
	//DIVIDE
	if (divideState == 1)
	{
		if (signController == 1) // ���� + divide +  = 
		{
			GetDlgItemText(IDC_EDIT_result, BigRes);
			SetDlgItemText(IDC_EDIT_minires, BigRes);
			Calculator(_SIGN::DIVIDE2);
			divideState = 2;
			signController = 1;
		}
		else {	 // ���� + divide + ���� + =
			Calculator(_SIGN::DIVIDE2);
			divideState = 2;
			signController = 1;
		}
	}
	else if (divideState == 2 && signController == 1 && SmRes == "0") // ���� + �ٸ���ȣ + divide + =
	{
		GetDlgItemText(IDC_EDIT_result, BigRes);
		SetDlgItemText(IDC_EDIT_minires, BigRes);
		Calculator(_SIGN::DIVIDE2);
		divideState = 2;
		signController = 1;
	}
	else if (divideState == 2 && signController == 1) // ����+ divide + = 
	{
		Calculator(_SIGN::DIVIDE);
		divideState = 2;
		signController = 1;
	}
	else if (divideState == 2 && signController == 0)
	{
		Calculator(_SIGN::DIVIDE2);
		divideState = 2;
		signController = 1;
	}
	//DIVIDE��

	// . �����
	CString isDot;
	GetDlgItemText(IDC_EDIT_minires, isDot);
		int index = isDot.Find('.');
		if (index != -1)  
		{
			for (int i = isDot.GetLength() - 1; i >= index; i--)
			{
				char c = isDot.GetAt(i);
				if (c == '0' || c == '.')
				{
					isDot.Delete(i);
					if (c == '.')
					{
						break;
					}
				}
				else
				{
					break;
				}
			}
		}
		SetDlgItemText(IDC_EDIT_minires, isDot);


}
// = end

/// the end ///

//void Ctoy6Dlg::OnBnClickedButtonmulti()
//{
//	GetDlgItemText(IDC_EDIT_result, BigRes);
//	GetDlgItemText(IDC_EDIT_minires, SmRes);
//	sign = "x";
//	SetDlgItemText(IDC_EDIT_sign, sign);
//	if (BigRes != "0" || SmRes != "0")
//	{
//		if (plusState > 0 || minusState > 0 || multiState > 0 || divideState > 0)
//		{
//			if (plusState > 0 && signController == 0)
//			{
//				Calculator(_SIGN::PLUS2);
//				plusState = 0;
//				minusState = 0;
//				multiState = 2;
//				divideState = 0;
//				signController = 1;
//				GetDlgItemText(IDC_EDIT_result, BigRes);
//				SetDlgItemText(IDC_EDIT_minires, BigRes);
//			}
//			if (minusState > 0 && signController == 0)
//			{
//				Calculator(_SIGN::MINUS2);
//				plusState = 0;
//				minusState = 0;
//				multiState = 2;
//				divideState = 0;
//				signController = 1;
//				GetDlgItemText(IDC_EDIT_result, BigRes);
//				SetDlgItemText(IDC_EDIT_minires, BigRes);
//			}
//			if (multiState > 0 && signController == 0)
//			{
//				Calculator(_SIGN::MULTI2);
//				plusState = 0;
//				minusState = 0;
//				multiState = 2;
//				divideState = 0;
//				signController = 1;
//				GetDlgItemText(IDC_EDIT_result, BigRes);
//				SetDlgItemText(IDC_EDIT_minires, BigRes);
//			}
//			if (divideState > 0 && signController == 0)
//			{
//				Calculator(_SIGN::DIVIDE2);
//				plusState = 0;
//				minusState = 0;
//				multiState = 2;
//				divideState = 0;
//				signController = 1;
//				GetDlgItemText(IDC_EDIT_result, BigRes);
//				SetDlgItemText(IDC_EDIT_minires, BigRes);
//			}
//		}
//	}
//	/*if (multiState == 2 && signController == 1)
//	{
//		GetDlgItemText(IDC_EDIT_result, BigRes);
//		SetDlgItemText(IDC_EDIT_minires, BigRes);
//	}*/
//	if (multiState == 2 && signController == 0)
//	{
//		Calculator(_SIGN::MULTI2);
//		multiState = 2;
//	}
//
//	if (plusState > 0 || minusState > 0 || divideState > 0)
//	{
//		if (plusState == 1 && signController == 1 && SmRes != "0")
//		{
//			Calculator(_SIGN::PLUS2);
//			signController = 2;
//		}
//		if (minusState == 1 && signController == 1 && SmRes != "0")
//		{
//			Calculator(_SIGN::MINUS2);
//			signController = 2;
//		}
//		if (divideState == 1 && signController == 1 && SmRes != "0")
//		{
//			Calculator(_SIGN::DIVIDE2);
//			signController = 2;
//		}
//		if ((signController == 1 && plusState > 0) || (signController == 1 && minusState > 0) || (signController == 1 && divideState > 0))
//		{
//			plusState = 0;
//			minusState = 0;
//			multiState = 2;
//			divideState = 0;
//
//		}
//	}
//
//	if (multiState != 2 && signController == 0)
//	{
//		signController = 1;
//		multiState = 1;
//	}
//}
//void Ctoy6Dlg::OnBnClickedButtondivide()
//{
//	sign = "��";
//	SetDlgItemText(IDC_EDIT_sign, sign);
//	GetDlgItemText(IDC_EDIT_result, BigRes);
//	GetDlgItemText(IDC_EDIT_minires, SmRes);
//	if (BigRes == "0" && SmRes == "0" && divideState == 1)
//	{
//		result.Format("%s", war1);
//		signFlag = 2;
//		SetDlgItemText(IDC_EDIT_result, result);
//		result.Empty();
//	}
//
//	if (BigRes != "0" || SmRes != "0")
//	{
//		if (plusState > 0 || minusState > 0 || multiState > 0 || divideState > 0)
//		{
//			if (plusState > 0 && signController == 0)
//			{
//				Calculator(_SIGN::PLUS2);
//				plusState = 0;
//				minusState = 0;
//				multiState = 0;
//				divideState = 2;
//				signController = 1;
//				GetDlgItemText(IDC_EDIT_result, BigRes);
//				SetDlgItemText(IDC_EDIT_minires, BigRes);
//			}
//			if (minusState > 0 && signController == 0)
//			{
//				Calculator(_SIGN::MINUS2);
//				plusState = 0;
//				minusState = 0;
//				multiState = 0;
//				divideState = 2;
//				signController = 1;
//				GetDlgItemText(IDC_EDIT_result, BigRes);
//				SetDlgItemText(IDC_EDIT_minires, BigRes);
//			}
//			if (multiState > 0 && signController == 0)
//			{
//				Calculator(_SIGN::MULTI2);
//				plusState = 0;
//				minusState = 0;
//				multiState = 0;
//				divideState = 2;
//				signController = 1;
//				GetDlgItemText(IDC_EDIT_result, BigRes);
//				SetDlgItemText(IDC_EDIT_minires, BigRes);
//			}
//			if (divideState > 0 && signController == 0)
//			{
//				Calculator(_SIGN::DIVIDE2);
//				plusState = 0;
//				minusState = 0;
//				multiState = 0;
//				divideState = 2;
//				signController = 1;
//				GetDlgItemText(IDC_EDIT_result, BigRes);
//				SetDlgItemText(IDC_EDIT_minires, BigRes);
//			}
//		}
//	}
//	/*if (divideState == 2 && signController == 1)
//	{
//		GetDlgItemText(IDC_EDIT_result, BigRes);
//		SetDlgItemText(IDC_EDIT_minires, BigRes);
//	}*/
//	if (divideState == 2 && signController == 0)
//	{
//		Calculator(_SIGN::DIVIDE2);
//		divideState = 2;
//	}
//
//	if (plusState > 0 || minusState > 0 || multiState > 0)
//	{
//		if (plusState == 1 && signController == 1 && SmRes != "0")
//		{
//			Calculator(_SIGN::PLUS2);
//			signController = 2;
//		}
//		if (minusState == 1 && signController == 1 && SmRes != "0")
//		{
//			Calculator(_SIGN::MINUS2);
//			signController = 2;
//		}
//		if (multiState == 1 && signController == 1 && SmRes != "0")
//		{
//			Calculator(_SIGN::MULTI2);
//			signController = 2;
//		}
//		if ((signController == 1 && plusState > 0) || (signController == 1 && minusState > 0) || (signController == 1 && multiState > 0))
//		{
//			plusState = 0;
//			minusState = 0;
//			multiState = 0;
//			divideState = 2;
//		}
//	}
//	if (divideState != 2 && signController == 0)
//	{
//		signController = 1;
//		divideState = 1;
//	}
//}