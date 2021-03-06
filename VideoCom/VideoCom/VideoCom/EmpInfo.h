// EmpInfo.h : interface of the CUserInfoDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include <string>
using namespace std; 

class CEmpInfoDlg : public SHostDialog
{
public:
	CEmpInfoDlg();
	~CEmpInfoDlg();

	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();
		void OnSize(UINT nType, CSize size);
	
	void OnBtnEmpInfoSettingOK();
		int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);

	void OnInitData();
	
	void SetParam(SStringT name,SStringT dept, SStringT tel, SStringT email);
	int  GetReturnCode() { return m_nRetCode; }

	LRESULT OnLButtonClick(UINT uMsg, WPARAM wParam, LPARAM lParam)
	{
		//SMessageBox(this->m_hWnd, _T("1"), _T("2"), MB_OK);
		return 0;
	}
protected:
		//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		EVENT_NAME_COMMAND(L"btn_cancel", OnClose)
		EVENT_NAME_COMMAND(L"btn_send_video", OnBtnEmpInfoSettingOK)
			EVENT_MAP_END()
		
	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CEmpInfoDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		//MESSAGE_HANDLER_EX(WM_LBUTTONUP, OnLButtonClick)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;
	SStringT			m_name;
	SStringT			m_dept;
	SStringT			m_tel;
	SStringT			m_email;
	int				m_nRetCode;
	};
