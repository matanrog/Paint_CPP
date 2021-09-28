#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"

class CMFCprojectApp : public CWinApp
{
public:
	CMFCprojectApp();

public:
	virtual BOOL InitInstance();
	
	DECLARE_MESSAGE_MAP()
};

extern CMFCprojectApp theApp;
