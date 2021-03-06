// MeetNoticeDlg.cpp : implementation of the CUserInfoDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MeetNoticeDlg.h"
	
#ifdef DWMBLUR	//win7毛玻璃开关
#include <dwmapi.h>
#pragma comment(lib,"dwmapi.lib")
#endif
	
CMeetNoticeDlg::CMeetNoticeDlg() : SHostDialog(_T("LAYOUT:DLG_MEET_NOTICE"))
{
	m_bLayoutInited = FALSE;
	m_nRetCode = 0;
}

CMeetNoticeDlg::~CMeetNoticeDlg()
{
}

int CMeetNoticeDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	#ifdef DWMBLUR	//win7毛玻璃开关
	MARGINS mar = {5,5,30,5};
	DwmExtendFrameIntoClientArea ( m_hWnd, &mar );
	#endif

	SetMsgHandled(FALSE);
	return 0;
}

BOOL CMeetNoticeDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;
	OnInitData();
	return 0;
}
//TODO:消息映射
void CMeetNoticeDlg::OnClose()
{
	//SendMessage(WM_SYSCOMMAND, SC_CLOSE);
	 OnOK();
	//CSimpleWnd::DestroyWindow();
}

void CMeetNoticeDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CMeetNoticeDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CMeetNoticeDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMeetNoticeDlg::OnSize(UINT nType, CSize size)
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

void CMeetNoticeDlg::OnBtnUserInfoSettingOK()
{
	SEdit *pEditName = FindChildByName2<SEdit>(L"edit_meet_name");
	SEdit *pEditStart = FindChildByName2<SEdit>(L"edit_meet_start");
	SEdit *pEditEnd = FindChildByName2<SEdit>(L"edit_meet_end");
	SEdit *pEditContent = FindChildByName2<SEdit>(L"edit_meet_content");
	m_name = pEditName->GetWindowTextW();
	m_starttime = pEditStart->GetWindowTextW();
	m_endtime = pEditEnd->GetWindowTextW();
	m_content = pEditContent->GetWindowTextW();
	m_nRetCode = 1;
	OnOK();
	//CSimpleWnd::DestroyWindow();
}

void CMeetNoticeDlg::OnInitData()
{
	SEdit *pEditName = FindChildByName2<SEdit>(L"edit_meet_name");
	SEdit *pEditStart = FindChildByName2<SEdit>(L"edit_meet_start");
	SEdit *pEditEnd = FindChildByName2<SEdit>(L"edit_meet_end");
	SEdit *pEditContent = FindChildByName2<SEdit>(L"edit_meet_content");
	pEditName->SetWindowTextW(m_name);
	pEditStart->SetWindowTextW(m_starttime);
	pEditEnd->SetWindowTextW(m_endtime);
	pEditContent->SetWindowTextW(m_content);

}

void CMeetNoticeDlg::updateData()
{

}

void CMeetNoticeDlg::SetParam(SStringT name, SStringT start, SStringT end, SStringT content)
{

	m_name = name	 ;
	m_starttime = start	 ;
	m_endtime = end		 ;
	m_content = content ;
	
	
}

void CMeetNoticeDlg::GetParam(SStringT& name, SStringT& start, SStringT& end, SStringT& content)
{
	
	name = m_name;
	start = m_starttime;
	end = m_endtime;
	content = m_content;
}

