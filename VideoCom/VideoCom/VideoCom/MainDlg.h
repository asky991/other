// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once
//#include <CurMeetInfoHandler.h>
#include <vector>
class CMainDlg : public SHostWnd
{
public:
	CMainDlg();
	~CMainDlg();

	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();
	void OnSize(UINT nType, CSize size);
	
	void OnBtnUserInfoSetting();
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);
	
	void OnInitAllCtrl();
	void OnInitLeftCtrl();
	void OnInitRigthCtrl();
	void OnBtnMeetFileStatus();
	void OnBtnrec();
	void OnBtneleb();
	void OnInitCampanyInfoTree(HSTREEITEM hTreeItem);

	void OnImgBtnOperMenu();
	void OnCommand(UINT uNotifyCode, int nID, HWND wndCtl);
	void OntcEmpoper();
	bool OnTCRBMenu(CPoint pt);
	bool OntcEmpMouseRightClick(EventArgs *pEvt);
	bool OntcChartClick(EventArgs *pEvt);


	LRESULT OntcEmpMouseRightClick(UINT uMsg, WPARAM wParam, LPARAM lParam);
	void OnTCRButtonDown(UINT nFlags, CPoint point);

 
protected:
		//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		EVENT_NAME_COMMAND(L"btn_userinfo_setting", OnBtnUserInfoSetting)
		EVENT_NAME_COMMAND(L"btn_MeetFileStatus", OnBtnMeetFileStatus)
		EVENT_NAME_COMMAND(L"btn_rec", OnBtnrec)
		EVENT_NAME_COMMAND(L"btn_eleb", OnBtneleb)
		//EVENT_ID_CONTEXTMENU(R.id.tc_erp_info, OnTCRBMenu)
		
		EVENT_NAME_COMMAND(_T("imgbtn_operate_menu"), OnImgBtnOperMenu)
		//EVENT_NAME_COMMAND(_T("tc_erp_info"), OntcEmpoper);
		//CHAIN_EVENT_MAP_MEMBER(m_main_curmeetinfo)
	EVENT_MAP_END()

	//SOUI_MSG_MAP_BEGIN()
	//	MSG_WM_RBUTTONDOWN(OnTCRButtonDown)
	//SOUI_MSG_MAP_END()

	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		MSG_WM_COMMAND(OnCommand)
		CHAIN_MSG_MAP(SHostWnd)

		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()

protected:
	void GetGroupInviter(vector<SStringT>& vec);
	void FindSelecteduser(HSTREEITEM item, vector<SStringT>& vec);
private:
	BOOL			m_bLayoutInited;
	int				m_RightTabctr2offset;
	BOOL			m_bWndDrawBoardvisible;
private:
	STUserInfo m_userinfo;
	//CCurMeetInfoHandler m_main_curmeetinfo;
};
