// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MainDlg.h"
#include "UserInfo.h"
#include "MeetDlg.h"
#include "define.h"
#include "EmpInfo.h"
#include "MeetNoticeDlg.h"

#ifdef DWMBLUR	//win7毛玻璃开关
#include <dwmapi.h>
#pragma comment(lib,"dwmapi.lib")
#endif
	
CMainDlg::CMainDlg() : SHostWnd(_T("LAYOUT:XML_MAINWND"))
{
	m_bLayoutInited = FALSE;
	m_bWndDrawBoardvisible = FALSE;
	
}

CMainDlg::~CMainDlg()
{

}

int CMainDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	#ifdef DWMBLUR	//win7毛玻璃开关
	MARGINS mar = {5,5,30,5};
	DwmExtendFrameIntoClientArea ( m_hWnd, &mar );
	#endif

	SetMsgHandled(FALSE);
	return 0;
}

BOOL CMainDlg::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	m_bLayoutInited = TRUE;
	OnInitAllCtrl();
	return 0;
}
//TODO:消息映射
void CMainDlg::OnClose()
{
	CSimpleWnd::DestroyWindow();
}

void CMainDlg::OnMaximize()
{
	SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE);
}

void CMainDlg::OnRestore()
{
	SendMessage(WM_SYSCOMMAND, SC_RESTORE);
}

void CMainDlg::OnMinimize()
{
	SendMessage(WM_SYSCOMMAND, SC_MINIMIZE);
}

void CMainDlg::OnSize(UINT nType, CSize size)
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

void CMainDlg::OnBtnUserInfoSetting()
{
	CUserInfoDlg userinfo;
	//userinfo.Create(GetActiveWindow());
	//userinfo.SendMessage(WM_INITDIALOG);
	//userinfo.CenterWindow(userinfo.m_hWnd);
	//userinfo.ShowWindow(SW_SHOWNORMAL);
	userinfo.DoModal(this->m_hWnd);
	int ncode = userinfo.GetReturnCode();
	if (ncode==1)
	{
		// TODO:
		wstring name, tel, email;
		userinfo.GetParam(name, tel, email);
		MessageBox(NULL, name.c_str(), email.c_str(), MB_YESNO);
	}


}

void CMainDlg::OnInitAllCtrl()
{
	OnInitLeftCtrl();
	OnInitRigthCtrl();
}


void CMainDlg::OnInitLeftCtrl()
{
	// 初始化userinfo
	SImageWnd *pUserHead = FindChildByName2<SImageWnd>(L"img_head_view");
	if (pUserHead)
	{
		//pUserHead->SetImage();
		//pUserHead->SetIcon();
	}
	SStatic* pUserName = FindChildByName2<SStatic>(L"txt_username");
	if (pUserName)
	{
		//pUserName->
	}
	SStatic* pUserDept = FindChildByName2<SStatic>(L"txt_user_dept");
	if (pUserDept)
	{
		//pUserDept->
	}
	
	SStatic* pUserPos = FindChildByName2<SStatic>(L"txt_user_pos");
	if (pUserPos)
	{
		//pUserPos->GetWindowTextW();
	}

	// 初始化tabctrl2 
	
	//初始化 treectrl  listctrl
	STreeCtrl* pErpInfo = FindChildByName2<STreeCtrl>(L"tc_erp_info");
	if (pErpInfo)
	{
		pErpInfo->RemoveAllItems();
		HSTREEITEM hRoot = pErpInfo->InsertItem(_T("亮眼云视科技有限公司"), 0, 1);
		OnInitCampanyInfoTree(hRoot);
		pErpInfo->SetCheckState(hRoot, FALSE);
		bool bRes = pErpInfo->GetEventSet()->subscribeEvent(EVT_TC_DBCLICK, Subscriber(&CMainDlg::OntcEmpMouseRightClick, this));
	}
	SListCtrl* pchartStatus = FindChildByName2<SListCtrl>(L"list_mtstatus");
	if (pchartStatus)
	{
		pchartStatus->DeleteAllItems();
		SStringT strStatus[3] = { S_CW2T(GETSTRING(L"禁言")),S_CW2T(GETSTRING(L"在线")),S_CW2T(GETSTRING(L"离线")) };
		for (size_t i = 0; i < 10; i++)
		{
			pchartStatus->InsertItem(i, S_CW2T(_T("test")));
			pchartStatus->SetSubItemText(i,0,_T("李四"));
			pchartStatus->SetSubItemText(i,1, strStatus[rand() % 3]);
		}
		pchartStatus->GetEventSet()->subscribeEvent(EVT_LC_SELCHANGING, Subscriber(&CMainDlg::OntcChartClick, this));
	}

	SImageButton* pOperateImgBtn = FindChildByName2<SImageButton>(L"imgbtn_operate");
	if (pOperateImgBtn)
	{

	}

}

bool CMainDlg::OntcChartClick(EventArgs *pEvt)
{

	CPoint pt;
	GetCursorPos(&pt);
	//使用模拟菜单
	SMenuEx menu;
	menu.LoadMenu(_T("smenuex:menuex_meet_oper")); //
	menu.TrackPopupMenu(0, pt.x, pt.y, m_hWnd);
	return true;
}

bool CMainDlg::OntcEmpMouseRightClick(EventArgs *pEvt)
{
	// TODO : 修改为右键单击
	//SMessageBox(NULL, SStringT().Format(_T("treectrl OntcEmpMouseRightClick ")), _T("EventArgs"), MB_OK);
	CPoint pt;
	GetCursorPos(&pt);
	//使用模拟菜单
	SMenuEx menu;
	menu.LoadMenu(_T("smenuex:menuex_emp_oper")); //menuex_meet_oper
	menu.TrackPopupMenu(0, pt.x, pt.y, m_hWnd);
	return true;
}

void CMainDlg::OnTCRButtonDown(UINT nFlags, CPoint point)
{
	SMessageBox(NULL, SStringT().Format(_T("treectrl OnTCRButtonDown ")), _T("OnTCRButtonDown"), MB_OK);
}

bool CMainDlg::OnTCRBMenu(CPoint pt)
{
	SMessageBox(NULL, SStringT().Format(_T("treectrl OnTCRBMenu ")), _T("OnTCRBMenu"), MB_OK);
	return true;
}

LRESULT CMainDlg::OntcEmpMouseRightClick(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	CPoint pt;
	GetCursorPos(&pt);
	//使用模拟菜单
	SMenuEx menu;
	menu.LoadMenu(_T("smenuex:menuex_emp_oper"));
	menu.TrackPopupMenu(0, pt.x, pt.y, m_hWnd);
	return 0;
}

void CMainDlg::OnInitCampanyInfoTree(HSTREEITEM hTreeItem)
{
	SStringT strDept[4] = { S_CW2T(GETSTRING(L"技术研发部")),S_CW2T(GETSTRING(L"市场销售部")),S_CW2T(GETSTRING(L"产品设计部")),
		S_CW2T(GETSTRING(L"财务部")) };
	STreeCtrl* pPersonInfo = FindChildByName2<STreeCtrl>(L"tc_erp_info");
	for (size_t i = 0; i < 4; i++)
	{
		
		HSTREEITEM hItem = pPersonInfo->InsertItem(strDept[i], 0, 1, hTreeItem);
		pPersonInfo->InsertItem(SStringT().Format(_T("%d%d"), (i + 1) , 1), 0, 1, hItem);
		pPersonInfo->InsertItem(SStringT().Format(_T("%d%d"), (i + 1) , 2), 0, 1, hItem);
		pPersonInfo->InsertItem(SStringT().Format(_T("%d%d"), (i + 1) , 3), 0, 1, hItem);
		pPersonInfo->InsertItem(SStringT().Format(_T("%d%d"), (i + 1) , 4), 0, 1, hItem);
		pPersonInfo->InsertItem(SStringT().Format(_T("%d%d"), (i + 1) , 5), 0, 1, hItem);
	}
	
}

void CMainDlg::OnInitRigthCtrl()
{
	// 初始化tabctrl2 video

	// 初始化tabctrl2 file

	// 其他信息
	SMCListView* pMcListCall = FindChildByName2<SMCListView>(L"mclist_call");
	if (pMcListCall)
	{
		IMcAdapter *pAdapter = new CCallListMcAdapterFix();
		pMcListCall->SetAdapter(pAdapter);
		pAdapter->Release();
	}
	SMCListView* pMcListFile = FindChildByName2<SMCListView>(L"mclist_file");
	if (pMcListFile)
	{
		IMcAdapter *pAdapter = new CCurMeetFileListMcAdapterFix();
		pMcListFile->SetAdapter(pAdapter);
		pAdapter->Release();
	}
	SWindow* pDrawBoard = FindChildByName2<SWindow>(L"wnd_drawboard");
	if (pDrawBoard)
	{
		pDrawBoard->SetVisible(m_bWndDrawBoardvisible);
	}

	//tileView
	STileView *pTileView = FindChildByName2<STileView>("tv_meetlist");
	if (pTileView)
	{
		SAdapterBase *pAdapter = new CMeetListTileAdapter;
		pTileView->SetAdapter(pAdapter);
		pAdapter->Release();
	}
	
	//tileView
	STileView *pNoticeTileView = FindChildByName2<STileView>("tv_meet_notice");
	if (pNoticeTileView)
	{
		SAdapterBase *pAdapter = new CMeetNoticeTVAdapter;
		pNoticeTileView->SetAdapter(pAdapter);
		pAdapter->Release();
	}

	//tileView
	STileView *pVideoFileTileView = FindChildByName2<STileView>("tv_meet_video_file");
	if (pVideoFileTileView)
	{
		SAdapterBase *pAdapter = new CMeetVideoFileTVAdapter;
		pVideoFileTileView->SetAdapter(pAdapter);
		pAdapter->Release();
	}

	
}

void CMainDlg::OnBtnMeetFileStatus()
{
	SButton* pStatusbtn = FindChildByName2<SButton>(L"btn_MeetFileStatus");
	STabCtrl2* pRightTopTb2 = FindChildByName2<STabCtrl2>(L"tab_right_video");
	STabCtrl2* pRightBottomTb2 = FindChildByName2<STabCtrl2>(L"tab_main_file");
	if (pStatusbtn)
	{
		SStringT name= pStatusbtn->GetWindowTextW();
		CRect rct = pRightTopTb2->GetWindowRect();
		CRect rcb = pRightBottomTb2->GetWindowRect();
		CRect rcbtn= pStatusbtn->GetWindowRect();
		
		if (name == _T("隐藏"))
		{
			m_RightTabctr2offset = rcb.bottom - rct.bottom;
			int offset = m_RightTabctr2offset;
			rct.bottom += offset;
			rcb.top += offset;
			rcbtn.top += offset;
			rcbtn.bottom += offset;

			//pRightBottomTb2->SetVisible(FALSE, TRUE);
			pStatusbtn->SetWindowTextW(_T("显示"));
		}
		else
		{
			int offset = m_RightTabctr2offset;
			rct.bottom -= offset;
			rcb.top -= offset;
			rcbtn.top -= offset;
			rcbtn.bottom -= offset;
			//pRightBottomTb2->SetVisible(TRUE, TRUE);
			pStatusbtn->SetWindowTextW(_T("隐藏"));
		}
		pRightTopTb2->Move(&rct);
		pStatusbtn->Move(&rcbtn);
		
		pRightBottomTb2->Move(&rcb);
		
	}
}

void CMainDlg::OnBtnrec()
{
	// TODB: 录制
	SButton* pStatusbtn = FindChildByName2<SButton>(L"btn_rec");
	if (pStatusbtn)
	{
		SStringT name = pStatusbtn->GetWindowTextW();
		if (name == _T("录制"))
		{

			pStatusbtn->SetWindowTextW(_T("结束录制"));
		}
		else
		{
			pStatusbtn->SetWindowTextW(_T("录制"));
		}
	}
}

void CMainDlg::OnBtneleb()
{
	SButton* pElecbtn = FindChildByName2<SButton>(L"btn_eleb");
	if (m_bWndDrawBoardvisible)
	{
		m_bWndDrawBoardvisible = FALSE;
		pElecbtn->SetWindowTextW(_T("电子白板"));
	}
	else
	{
		m_bWndDrawBoardvisible = TRUE;
		pElecbtn->SetWindowTextW(_T("隐藏白板"));
	}
	SWindow* pDrawBoard = FindChildByName2<SWindow>(L"wnd_drawboard");
	if (pDrawBoard)
	{
		pDrawBoard->SetVisible(m_bWndDrawBoardvisible,TRUE);
	}
	
}

void CMainDlg::OnImgBtnOperMenu()
{
	CPoint pt;
	GetCursorPos(&pt);
	//使用模拟菜单
	SMenuEx menu;
	menu.LoadMenu(_T("smenuex:menuex_oper"));
	menu.TrackPopupMenu(0, pt.x, pt.y, m_hWnd);
}

void CMainDlg::OntcEmpoper()
{
	SMessageBox(NULL, SStringT().Format(_T("treectrl")), _T("menu"), MB_OK);

}

//演示如何响应菜单事件
void CMainDlg::OnCommand(UINT uNotifyCode, int nID, HWND wndCtl)
{
	if (uNotifyCode == 0)
	{
		if (nID == 1)
		{
			SStringT name, starttime, endtime;
			vector<SStringT> vec;
			int				type=0; //0 视频 1 语音 2 本地 
			GetGroupInviter(vec);
			CMeetInfoDlg MeetInfo;
			MeetInfo.SetParam(name, starttime, endtime, type, vec);
			MeetInfo.DoModal(this->m_hWnd);
			int ncode = MeetInfo.GetReturnCode();
			if (ncode == 1)
			{
				// TODO:
				vec.clear();
				MeetInfo.GetParam(name, starttime, endtime, type, vec);
			}
		}
		else if (nID == 2)
		{
			SMessageBox(NULL, SStringT().Format(_T("menu %d"), nID), _T("menu"), MB_OK);
		}
		else if (nID == 3)
		{
			SMessageBox(NULL, SStringT().Format(_T("menu %d"), nID), _T("menu"), MB_OK);
		}
		else if (nID == 4)
		{
			SMessageBox(NULL, SStringT().Format(_T("menu %d"), nID), _T("menu"), MB_OK);
		}
		else if (nID == 5)
		{
			SStringT name=_T("test"),dept=_T("研发部"),tel=_T("110"),email=_T("123@qq.com");
			STreeCtrl* pPersonInfo = FindChildByName2<STreeCtrl>(L"tc_erp_info");
			HSTREEITEM item= pPersonInfo->GetSelectedItem();
			pPersonInfo->GetItemText(item, name);
			HSTREEITEM childitem = pPersonInfo->GetChildItem(item);
			if (childitem)
			{
				return;
			}
			HSTREEITEM parentitem = pPersonInfo->GetParentItem(item);
			pPersonInfo->GetItemText(parentitem, dept);


			CEmpInfoDlg EmpInfo;
			EmpInfo.SetParam(name, dept, tel, email);
			EmpInfo.DoModal(this->m_hWnd);
			
			int ncode = EmpInfo.GetReturnCode();
			if (ncode == 1)
			{
				// TODO:
				//wstring name, tel, email;
				//MeetInfo.GetParam(name, tel, email);
				//MessageBox(NULL, name.c_str(), email.c_str(), MB_YESNO);
			}
			//SMessageBox(NULL, SStringT().Format(_T("menu %d"), nID), _T("menu"), MB_OK);
		}
		else if (nID == 11)
		{
			STabCtrl* pErpTc = FindChildByName2<STabCtrl>(L"tab_main_erp");
			if (pErpTc)
			{
				pErpTc->SetCurSel(0);
			}
		}
		else if (nID == 12)
		{

			
			STreeCtrl* pErpInfo = FindChildByName2<STreeCtrl>(L"tc_erp_info");
			CRect rect = pErpInfo->GetWindowRect();

			SStringT name, starttime, endtime,content;
			CMeetNoticeDlg MeetNotice;
			//MeetNotice.SetWindowPos(this->m_hWnd, rect.left, rect.top, rect.right, rect.bottom, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);
			MeetNotice.SetParam(name, starttime, endtime,content);
			MeetNotice.DoModal(this->m_hWnd);
			int ncode = MeetNotice.GetReturnCode();
			if (ncode == 1)
			{
				// TODO:
				MeetNotice.GetParam(name, starttime, endtime, content);
			}
		}
		else if (nID == 13)
		{
			SMessageBox(NULL, SStringT().Format(_T("menu %d"), nID), _T("menu"), MB_OK);
		}
		else if (nID == 13)
		{
			SMessageBox(NULL, SStringT().Format(_T("menu %d"), nID), _T("menu"), MB_OK);
		}
		else if (nID == 14)
		{
			SMessageBox(NULL, SStringT().Format(_T("menu %d"), nID), _T("menu"), MB_OK);
		}
		else if (nID == 21)
		{
			STabCtrl* pErpTc = FindChildByName2<STabCtrl>(L"tab_main_erp");
			if (pErpTc)
			{
				pErpTc->SetCurSel(0);
			}
			//SMessageBox(NULL, SStringT().Format(_T("menu %d"), nID), _T("menu"), MB_OK);
		}
		else if (nID == 22)
		{
			SMessageBox(NULL, SStringT().Format(_T("menu %d"), nID), _T("menu"), MB_OK);
		}
		else if (nID == 23)
		{
			SMessageBox(NULL, SStringT().Format(_T("menu %d"), nID), _T("menu"), MB_OK);
		}
		else if (nID == 24)
		{
			SMessageBox(NULL, SStringT().Format(_T("menu %d"), nID), _T("menu"), MB_OK);
		}
		
	
	}
	else
	{
		SMessageBox(NULL, SStringT().Format(_T("code:%d id %d"), uNotifyCode, nID), _T("comond"), MB_OK);
	}
}

void CMainDlg::GetGroupInviter(vector<SStringT>& vec)
{
	// TODO: 获取群邀请人员
	STreeCtrl* pErpInfo = FindChildByName2<STreeCtrl>(L"tc_erp_info");
	if (pErpInfo)
	{

		HSTREEITEM hRoot = pErpInfo->GetRootItem();
		FindSelecteduser(hRoot, vec);
	}
}

void CMainDlg::FindSelecteduser(HSTREEITEM item, vector<SStringT>& vec)
{
	STreeCtrl* pErpInfo = FindChildByName2<STreeCtrl>(L"tc_erp_info");
	HSTREEITEM hchilditem = pErpInfo->GetChildItem(item);
	if (hchilditem)
	{
		while (hchilditem)
		{
			FindSelecteduser(hchilditem, vec);
			hchilditem = pErpInfo->GetNextSiblingItem(hchilditem);
		}
	}
	else
	{
		if (pErpInfo->GetCheckState(item))
		{
			SStringT text;
			pErpInfo->GetItemText(item, text);
			vec.push_back(text);
		}
	}

}

