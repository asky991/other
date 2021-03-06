// MainDlg.cpp : implementation of the CUserInfoDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "UserInfo.h"
	
#ifdef DWMBLUR	//win7毛玻璃开关
#include <dwmapi.h>
#pragma comment(lib,"dwmapi.lib")
#endif
	
CUserInfoDlg::CUserInfoDlg() : SHostDialog(_T("LAYOUT:DLG_USER_SETTING"))
{
	m_bLayoutInited = FALSE;
	m_nRetCode = 0;
}

CUserInfoDlg::~CUserInfoDlg()
{
}

int CUserInfoDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	#ifdef DWMBLUR	//win7毛玻璃开关
	MARGINS mar = {5,5,30,5};
	DwmExtendFrameIntoClientArea ( m_hWnd, &mar );
	#endif

	SetMsgHandled(FALSE);
	return 0;
}

BOOL CUserInfoDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
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
void CUserInfoDlg::OnClose()
{
	//SendMessage(WM_SYSCOMMAND, SC_CLOSE);
	 OnOK();
	//CSimpleWnd::DestroyWindow();
}

void CUserInfoDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CUserInfoDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CUserInfoDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CUserInfoDlg::OnSize(UINT nType, CSize size)
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

void CUserInfoDlg::OnBtnUserInfoSettingOK()
{
	SEdit *pEditName = FindChildByName2<SEdit>(L"edit_name");
	SEdit *pEditTel = FindChildByName2<SEdit>(L"edit_tel");
	SEdit *pEditEmail = FindChildByName2<SEdit>(L"edit_email");
	m_name = pEditName->GetWindowTextW();
	m_tel = pEditTel->GetWindowTextW();
	m_email = pEditEmail->GetWindowTextW();

	m_nRetCode = 1;
	OnOK();
	//CSimpleWnd::DestroyWindow();
}

void CUserInfoDlg::OnInitData()
{
	SEdit *pEditName = FindChildByName2<SEdit>(L"edit_name");
	SEdit *pEditTel = FindChildByName2<SEdit>(L"edit_tel");
	SEdit *pEditEmail = FindChildByName2<SEdit>(L"edit_email");
	pEditName->SetWindowTextW(m_name.c_str());
	pEditTel->SetWindowTextW(m_tel.c_str());
	pEditEmail->SetWindowTextW(m_email.c_str());
}

void CUserInfoDlg::updateData()
{
	//SEdit *pEditName = FindChildByName2<SEdit>(L"edit_name");
	//SEdit *pEditTel = FindChildByName2<SEdit>(L"edit_tel");
	//SEdit *pEditEmail = FindChildByName2<SEdit>(L"edit_email");
	//m_name = pEditName->GetWindowTextW();
	//m_tel = pEditTel->GetWindowTextW();
	//m_email = pEditEmail->GetWindowTextW();
}

void CUserInfoDlg::SetParam(wstring name, wstring tel, wstring email)
{
	m_name = name;
	m_tel = tel;
	m_email = email;
	
}

void CUserInfoDlg::GetParam(wstring& name, wstring& tel, wstring& email)
{
	updateData();
	name = m_name;
	tel = m_tel;
	email = m_email;
}

