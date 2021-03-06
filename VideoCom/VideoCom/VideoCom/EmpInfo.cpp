// MainDlg.cpp : implementation of the CUserInfoDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EmpInfo.h"
	
#ifdef DWMBLUR	//win7毛玻璃开关
#include <dwmapi.h>
#pragma comment(lib,"dwmapi.lib")
#endif
	
CEmpInfoDlg::CEmpInfoDlg() : SHostDialog(_T("LAYOUT:DLG_EMP_INFO"))
{
	m_bLayoutInited = FALSE;
	m_nRetCode = 0;
}

CEmpInfoDlg::~CEmpInfoDlg()
{
}

int CEmpInfoDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	#ifdef DWMBLUR	//win7毛玻璃开关
	MARGINS mar = {5,5,30,5};
	DwmExtendFrameIntoClientArea ( m_hWnd, &mar );
	#endif

	SetMsgHandled(FALSE);
	return 0;
}

BOOL CEmpInfoDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;
	OnInitData();
	//SEdit *pEditName = FindChildByName2<SEdit>(L"edit_name");
	//SEdit *pEditTel = FindChildByName2<SEdit>(L"edit_tel");
	//SEdit *pEditEmail = FindChildByName2<SEdit>(L"edit_email");
	//pEditName->SetWindowTextW(L"刘志强");
	//pEditTel->SetWindowTextW(L"110");
	//pEditEmail->SetWindowTextW(L"test@test.cn");
	return 0;
}
//TODO:消息映射
void CEmpInfoDlg::OnClose()
{
	//SendMessage(WM_SYSCOMMAND, SC_CLOSE);
	 OnOK();
	//CSimpleWnd::DestroyWindow();
}

void CEmpInfoDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CEmpInfoDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CEmpInfoDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CEmpInfoDlg::OnSize(UINT nType, CSize size)
{
	SetMsgHandled(FALSE);
	if (!m_bLayoutInited) return;
	
	SWindow *pBtnMax = FindChildByName(L"btn_max");
	SWindow *pBtnRestore = FindChildByName(L"btn_restore");
	if(!pBtnMax || !pBtnRestore) return;
	
	if (nType == SIZE_MAXIMIZED)
	{
		pBtnRestore->SetVisible(TRUE);
		pBtnMax->SetVisible(FALSE);
	}
	else if (nType == SIZE_RESTORED)
	{
		pBtnRestore->SetVisible(FALSE);
		pBtnMax->SetVisible(TRUE);
	}
}

void CEmpInfoDlg::OnBtnEmpInfoSettingOK()
{


	m_nRetCode = 1;
	OnOK();
	//CSimpleWnd::DestroyWindow();
}

void CEmpInfoDlg::OnInitData()
{
	SEdit *pEditName = FindChildByName2<SEdit>(L"edit_name");
	SEdit *pEditDept = FindChildByName2<SEdit>(L"edit_dept");
	SEdit *pEditTel = FindChildByName2<SEdit>(L"edit_tel");
	SEdit *pEditEmail = FindChildByName2<SEdit>(L"edit_email");
	pEditName->SetWindowTextW(m_name);
	pEditDept->SetWindowTextW(m_dept);
	pEditTel->SetWindowTextW(m_tel);
	pEditEmail->SetWindowTextW(m_email);
}



void CEmpInfoDlg::SetParam(SStringT name, SStringT dept, SStringT tel, SStringT email)
{
	m_name = name;
	m_tel = tel;
	m_email = email;
	m_dept = dept;
	
}



