
// toy6Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "toy6.h"
#include "toy6Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// Ctoy6Dlg 대화 상자



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


// Ctoy6Dlg 메시지 처리기


BOOL Ctoy6Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	sign = "";
	zero = "0";
	SetDlgItemText(IDC_EDIT_result, zero);
	SetDlgItemText(IDC_EDIT_minires, zero);
	result = "0";
	signController = 0; // 부호 카운트
	plusState = 0; // 컨트롤스위치
	minusState = 0; // 
	multiState = 0; // 
	divideState = 0; //
	signFlag = 0;
	war1 = "정의되지 않은 결과입니다.";
	war2 = "0으로 나눌수 없습니다.";


	// 폰트 설정
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
	// 폰트 설정 end

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void Ctoy6Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR Ctoy6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

// 숫자 0~9 // 공통부분 Button0에 정리함
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
	{   // 경고문 war1, war2 뜬뒤 누르는 버튼은 초기화 진행후 입력됨
		OnBnClickedButtonreset();
	}
	if (signController != 1)
	{
		if (BigRes != "-0" && BigRes != "0")
		{
			BigRes += num; // 문자열 더하는 방식으로 입력
			SetDlgItemText(IDC_EDIT_result, BigRes);
		}
	}
	else
	{	// 부호를 누른뒤 새로운 값을 입력할때
		// 확실하지 않은 입력값은 예외처리
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
// 숫자 0~9 end
// plus 버튼
void Ctoy6Dlg::OnBnClickedButtonplus()
{
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	sign = "+";
	SetDlgItemText(IDC_EDIT_sign, sign);
	// 부호 + 숫자 누른 상태에서 이전 부호 or 다른 부호 눌렀을시 이전 부호 동작후 다음 부호 동작 대기
	// 계산이 일어나기 전이며 한번 일어난 후에는 signController가 1로 올라감
	if (BigRes != "0" || SmRes != "0")
	{ // 11 숫자 + 부호 + 숫자 + 부호 한번 결과가 도출되는 부분
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

	//if (plusState == 2 && signController == 0) // + 버튼으로는 안들어온다??
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
		//if (divideState == 1 && signController == 1 && SmRes != "0")//3 1,2,3 잠구려던 부분인데 
		//{
		//	Calculator(_SIGN::DIVIDE2);
		//	signController = 2;
		//}

		// 22 부호끼리만 눌러서 1회 계산한뒤 카운터가 signController가 1 올라갔을경우 =(eqauls) 버튼의 다음 행동조절
		if ((signController == 1 && minusState > 0) || (signController == 1 && multiState > 0) || (signController == 1 && divideState > 0))
		{
			plusState = 2;
			minusState = 0;
			multiState = 0;
			divideState = 0;
		}
	} 
	// 초기화, 프로그램 시작후 첫 부호 눌렀을때 거치는 부분
	if (plusState != 2 && signController == 0)
	{
		signController = 1;
		plusState = 1;
	}
}
// plus 버튼 end
// minus 버튼
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

	// 숫자 + 부호 반복동작으로만 작동
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
// minus 버튼end
// multi 버튼
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
// multi 버튼 end
// divide 버튼
void Ctoy6Dlg::OnBnClickedButtondivide()
{
	sign = "÷";
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
// divide 버튼 end
// 계산기
void Ctoy6Dlg::Calculator(int num)
{

	GetDlgItemText(IDC_EDIT_result, num1);
	GetDlgItemText(IDC_EDIT_minires, num2);


	double DNUM1 = atof(num1);
	double DNUM2 = atof(num2);
	switch (num)
	{
	case 1: //PLUS // 보이는 값의 교환 없이 그대로 진행. 반복작업용
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
	case 2: //MINUS // 보이는 값의 교환 없이 그대로 진행. 반복작업용
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
	case 3: //MULTI // 보이는 값의 교환 없이 그대로 진행. 반복작업용
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
	case 4: //DIVIDE // 보이는 값의 교환 없이 그대로 진행. 반복작업용
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
	case 5: //PLUS2 // 나중에 입력된 값이 연산후 작은창으로 이동
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
	case 6: // MINUS2 // 나중에 입력된 값이 연산후 작은창으로 이동
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
	case 7: // MUNTI2 // 나중에 입력된 값이 연산후 작은창으로 이동
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
	case 8: // DIVIDE2 // 나중에 입력된 값이 연산후 작은창으로 이동
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
// 계산기 end
// del
void Ctoy6Dlg::OnBnClickedButtondel()
{
	GetDlgItemText(IDC_EDIT_result, BigRes);
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	if (signController == 0)
	{	// 수정 가능한 상태
		GetDlgItemText(IDC_EDIT_result, BigRes);
		if (strlen(BigRes) == 1) 
		{   // 숫자 1개남았을때 delete 버튼 동작하면 Empty() 함수로 비우고 0으로초기화
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
			{ // 하나 지웠는데 -, -0 남으면 0으로 초기화
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
//  +/- 버튼
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
//  +/- 버튼 end
// = 
void Ctoy6Dlg::OnBnClickedButtonequals()
{
	GetDlgItemText(IDC_EDIT_minires, SmRes);
	//PLUS
	if (plusState == 1)
	{
		if (signController == 1) // 숫자 다음 plus 누른뒤 = 바로진입
		{
			GetDlgItemText(IDC_EDIT_result, BigRes);
			SetDlgItemText(IDC_EDIT_minires, BigRes);
			Calculator(_SIGN::PLUS2);
			plusState = 2;
			signController = 1;
		}
		else // 숫자 + plus + 숫자 + = 눌러서 plusState==1 && signController == 0일경우 진입
		{
			Calculator(_SIGN::PLUS2);
			plusState = 2;
			signController = 1;
		}
	}
	else if (plusState == 2 && signController == 1 && SmRes == "0") // 숫자+ 다른부호+ plus + =
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
	else if (plusState == 2 && signController == 0) // plus + 숫자 + = 
	{
		Calculator(_SIGN::PLUS2);
		plusState = 2;
		signController = 1;
	}
	//PLUS끝
	//MINUS
	if (minusState == 1)
	{
		if (signController == 1) // 숫자 + minus + = 
		{
			GetDlgItemText(IDC_EDIT_result, BigRes);
			SetDlgItemText(IDC_EDIT_minires, BigRes);
			Calculator(_SIGN::MINUS2);
			minusState = 2;
			signController = 1;
		}
		else // 숫자 + minus + 숫자 + = 눌러서 minusState==1 && signController == 0일경우 진입
		{
			Calculator(_SIGN::MINUS2);
			minusState = 2;
			signController = 1;
		}
	}
	else if (minusState == 2 && signController == 1 && SmRes == "0") // 숫자+ 다른부호+ minus + =
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
	else if (minusState == 2 && signController == 0) // minus + 숫자 + =
	{
		Calculator(_SIGN::MINUS2);
		minusState = 2;
		signController = 1;
	}
	
	//MINUS끝
	//MULTI
	if (multiState == 1)
	{
		if (signController == 1) // 숫자 다음 + 누른뒤 = 바로진입
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
	else if (multiState == 2 && signController == 1 && SmRes == "0") // 숫자 + 다른부호 + multi + =
	{
		GetDlgItemText(IDC_EDIT_result, BigRes);
		SetDlgItemText(IDC_EDIT_minires, BigRes);
		Calculator(_SIGN::MULTI);
		multiState = 2;
		signController = 1;
	}
	else if (multiState == 2) // 숫자 + multi + =
	{
		Calculator(_SIGN::MULTI);
		multiState = 2;
		signController = 1;
	}
	
	//MULTI끝
	//DIVIDE
	if (divideState == 1)
	{
		if (signController == 1) // 숫자 + divide +  = 
		{
			GetDlgItemText(IDC_EDIT_result, BigRes);
			SetDlgItemText(IDC_EDIT_minires, BigRes);
			Calculator(_SIGN::DIVIDE2);
			divideState = 2;
			signController = 1;
		}
		else {	 // 숫자 + divide + 숫자 + =
			Calculator(_SIGN::DIVIDE2);
			divideState = 2;
			signController = 1;
		}
	}
	else if (divideState == 2 && signController == 1 && SmRes == "0") // 숫자 + 다른부호 + divide + =
	{
		GetDlgItemText(IDC_EDIT_result, BigRes);
		SetDlgItemText(IDC_EDIT_minires, BigRes);
		Calculator(_SIGN::DIVIDE2);
		divideState = 2;
		signController = 1;
	}
	else if (divideState == 2 && signController == 1) // 숫자+ divide + = 
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
	//DIVIDE끝

	// . 지우기
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
//	sign = "÷";
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