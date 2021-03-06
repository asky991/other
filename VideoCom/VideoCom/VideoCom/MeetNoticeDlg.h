// MeetNoticeDlg.h : interface of the CUserInfoDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
using namespace std; 
#include <vector>

class CMeetNoticeDlg : public SHostDialog
{
public:
	CMeetNoticeDlg();
	~CMeetNoticeDlg();

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
	void SetParam(SStringT name, SStringT start, SStringT end, SStringT content);
	void GetParam(SStringT& name, SStringT& start, SStringT& end, SStringT& content);
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
	BEGIN_MSG_MAP_EX(CMeetInfoDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;
	SStringT		m_name;
	SStringT		m_starttime;
	SStringT		m_endtime;
	SStringT		m_content;
	int				m_nRetCode;
	};
