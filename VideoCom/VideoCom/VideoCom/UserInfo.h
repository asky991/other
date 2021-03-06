// MainDlg.h : interface of the CUserInfoDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
using namespace std; 


class CUserInfoDlg : public SHostDialog
{
public:
	CUserInfoDlg();
	~CUserInfoDlg();

	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();
		void OnSize(UINT nType, CSize size);
	
	void OnBtnUserInfoSettingOK();
		int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);

	void OnInitData();
	void updateData();
	void SetParam(wstring name, wstring tel, wstring email);
	void GetParam(wstring& name, wstring& tel, wstring& email);
	int  GetReturnCode() { return m_nRetCode; }
protected:
		//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		EVENT_NAME_COMMAND(L"btn_cancel", OnClose)
		EVENT_NAME_COMMAND(L"btn_ok", OnBtnUserInfoSettingOK)
			EVENT_MAP_END()
		
	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CUserInfoDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;
	wstring			m_name;
	wstring			m_tel;
	wstring			m_email;
	int				m_nRetCode;
	};
