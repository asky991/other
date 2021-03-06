// LoginDlg.h : interface of the CLoginDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include "..\controls.extend\STurn3DView.h"

class CLoginDlg : public SHostDialog
{
public:
    CLoginDlg();
    ~CLoginDlg();

    void OnClose()
    {
        AnimateHostWindow(200, AW_CENTER | AW_HIDE);
        DestroyWindow();
    }
    void OnMaximize()
    {
        SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
    }
    void OnRestore()
    {
        SendMessage(WM_SYSCOMMAND, SC_RESTORE);
    }
    void OnMinimize()
    {
        SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
    }
	void OnSize(UINT nType, CSize size)
	{
		SetMsgHandled(FALSE);
		if (!m_bLayoutInited) return;

		SWindow *pBtnMax = FindChildByName(L"btn_max");
		SWindow *pBtnRestore = FindChildByName(L"btn_restore");
		if (!pBtnMax || !pBtnRestore) return;

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
    int OnCreate(LPCREATESTRUCT lpCreateStruct);
    BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);

    void OnBtnSetting();
    void OnBtnSettingOK();
    void OnBtnSettingCancel();
    BOOL OnTurn3D(EventArgs *pEvt);
    BOOL OnUserChanged(EventArgs *pEvt);
    void OnBtnLogin();

    int  GetReturnCode() { return m_nRetCode; }

protected:

    EVENT_MAP_BEGIN()
        EVENT_NAME_COMMAND(L"btn_close", OnClose)
        EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
        EVENT_NAME_COMMAND(L"btn_setting", OnBtnSetting)
        EVENT_NAME_COMMAND(L"btn_setting_ok", OnBtnSettingOK)
        EVENT_NAME_COMMAND(L"btn_setting_cancel", OnBtnSettingCancel)
        EVENT_NAME_COMMAND(L"btn_login", OnBtnLogin)
        EVENT_NAME_HANDLER(L"turn3d", EventTurn3d::EventID, OnTurn3D);
    EVENT_NAME_HANDLER(L"cbx_account", EventCBSelChange::EventID, OnUserChanged)
        EVENT_MAP_END()

        BEGIN_MSG_MAP_EX(CLoginDlg)
        MSG_WM_CREATE(OnCreate)
        MSG_WM_INITDIALOG(OnInitDialog)
        MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
        CHAIN_MSG_MAP(SHostWnd)
        REFLECT_NOTIFICATIONS_EX()
        END_MSG_MAP()
private:
    BOOL			m_bLayoutInited;
    int             m_nRetCode;
};
