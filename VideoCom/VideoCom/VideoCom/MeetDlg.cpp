// MeetDlg.cpp : implementation of the CUserInfoDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MeetDlg.h"
	
#ifdef DWMBLUR	//win7毛玻璃开关
#include <dwmapi.h>
#pragma comment(lib,"dwmapi.lib")
#endif
	
CMeetInfoDlg::CMeetInfoDlg() : SHostDialog(_T("LAYOUT:DLG_MEET_CREATE"))
{
	m_bLayoutInited = FALSE;
	m_nRetCode = 0;
}

CMeetInfoDlg::~CMeetInfoDlg()
{
}

int CMeetInfoDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	#ifdef DWMBLUR	//win7毛玻璃开关
	MARGINS mar = {5,5,30,5};
	DwmExtendFrameIntoClientArea ( m_hWnd, &mar );
	#endif

	SetMsgHandled(FALSE);
	return 0;
}

BOOL CMeetInfoDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;
	OnInitData();
	return 0;
}
//TODO:消息映射
void CMeetInfoDlg::OnClose()
{
	//SendMessage(WM_SYSCOMMAND, SC_CLOSE);
	 OnOK();
	//CSimpleWnd::DestroyWindow();
}

void CMeetInfoDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}
void CMeetInfoDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}
void CMeetInfoDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMeetInfoDlg::OnSize(UINT nType, CSize size)
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

void CMeetInfoDlg::OnBtnUserInfoSettingOK()
{
	SEdit *pEditName = FindChildByName2<SEdit>(L"edit_meet_name");
	SEdit *pEditStart = FindChildByName2<SEdit>(L"edit_meet_start_time");
	SEdit *pEditEnd = FindChildByName2<SEdit>(L"edit_meet_end_time");
	m_name = pEditName->GetWindowTextW();
	m_starttime = pEditStart->GetWindowTextW();
	m_endtime = pEditEnd->GetWindowTextW();

	m_nRetCode = 1;
	OnOK();
	//CSimpleWnd::DestroyWindow();
}

void CMeetInfoDlg::OnInitData()
{
	SEdit *pEditName = FindChildByName2<SEdit>(L"edit_meet_name");
	SEdit *pEditStart = FindChildByName2<SEdit>(L"edit_meet_start_time");
	SEdit *pEditEnd = FindChildByName2<SEdit>(L"edit_meet_end_time");
	pEditName->SetWindowTextW(m_name);
	pEditStart->SetWindowTextW(m_starttime);
	pEditEnd->SetWindowTextW(m_endtime);
	SCheckBox* pChkVideo= FindChildByName2<SCheckBox>(L"ck_video_meet");
	SCheckBox* pChkVoice = FindChildByName2<SCheckBox>(L"ck_voice_meet");
	SCheckBox* pChkLocal = FindChildByName2<SCheckBox>(L"ck_local_meet");
	if (m_type == 0)
	{
		pChkVideo->SetCheck(TRUE);
		pChkVoice->SetCheck(TRUE);
	}
	else if(m_type ==1)
	{
		pChkVoice->SetCheck(TRUE);
	}
	else if (m_type == 2)
	{
		pChkLocal->SetCheck(TRUE);
	}
	
	STileView *pTvGroupInviter = FindChildByName2<STileView>("tv_group_inviter");
	if (pTvGroupInviter)
	{
		SAdapterBase *pAdapter = new CGroupInviterTVAdapter(m_vec);
		
		pTvGroupInviter->SetAdapter(pAdapter);
		pAdapter->Release();
	}


}

void CMeetInfoDlg::updateData()
{

}

void CMeetInfoDlg::SetParam(SStringT name, SStringT start, SStringT end, int type, vector<SStringT> vec)
{

	m_name = name	 ;
	m_starttime = start	 ;
	m_endtime = end		 ;
	m_type = type	 ;
	m_vec = vec		 ;
	
	
}

void CMeetInfoDlg::GetParam(SStringT& name, SStringT& start, SStringT& end, int& type, vector<SStringT>& vec)
{
	
	name = m_name;
	start = m_starttime;
	end = m_endtime;
	type = m_type;
	vec = m_vec;
}

