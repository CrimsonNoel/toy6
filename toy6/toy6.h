
// toy6.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// Ctoy6App:
// �� Ŭ������ ������ ���ؼ��� toy6.cpp�� �����Ͻʽÿ�.
//

class Ctoy6App : public CWinApp
{
public:
	Ctoy6App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern Ctoy6App theApp;