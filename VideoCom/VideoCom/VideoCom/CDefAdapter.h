#pragma once
#include <helper/SAdapterBase.h>
#include "stdafx.h"

class CCallListMcAdapterFix : public SMcAdapterBase
{
public:


	SArray<CallListPersionInfo> m_callpersioninfo;

public:
	CCallListMcAdapterFix()
	{
		SStringT strStatus[3] = { S_CW2T(GETSTRING(L"连接中")),S_CW2T(GETSTRING(L"拒绝")),S_CW2T(GETSTRING(L"挂断")) };
		SStringT strDept[3] = { S_CW2T(GETSTRING(L"技术部")),S_CW2T(GETSTRING(L"产品部")),S_CW2T(GETSTRING(L"行政部")) };

		for (int i = 0; i<100; i++)
		{
			CallListPersionInfo cp;
			_stprintf(cp.szName, _T("刘老_%d"), i + 1);
			_tcscpy(cp.szStatus, strStatus[rand() % 3]);
			_tcscpy(cp.szDept, strDept[rand() % 3]);
			m_callpersioninfo.Add(cp);
		}
	}

	virtual int getCount()
	{
		return m_callpersioninfo.GetCount();
	}


	virtual void getView(int position, SWindow * pItem, pugi::xml_node xmlTemplate)
	{
		if (pItem->GetChildrenCount() == 0)
		{
			pItem->InitFromXml(xmlTemplate);
		}

		CallListPersionInfo & cp = m_callpersioninfo[position];
		pItem->FindChildByName(L"txt_name")->SetWindowText(cp.szName);
		pItem->FindChildByName(L"txt_status")->SetWindowText(cp.szStatus);
		pItem->FindChildByName(L"txt_dept")->SetWindowText(cp.szDept);
	}

	virtual SStringW GetColumnName(int iCol) const override
	{
		return SStringW().Format(L"col%d", iCol + 1);
	}

	struct SORTCTX
	{
		int iCol;
		SHDSORTFLAG stFlag;
	};

	bool OnSort(int iCol, SHDSORTFLAG * stFlags, int nCols)
	{
		if (iCol == 5) //最后一列“操作”不支持排序
			return false;

		SHDSORTFLAG stFlag = stFlags[iCol];
		switch (stFlag)
		{
		case ST_NULL:stFlag = ST_UP; break;
		case ST_DOWN:stFlag = ST_UP; break;
		case ST_UP:stFlag = ST_DOWN; break;
		}
		for (int i = 0; i<nCols; i++)
		{
			stFlags[i] = ST_NULL;
		}
		stFlags[iCol] = stFlag;

		SORTCTX ctx = { iCol,stFlag };
		qsort_s(m_callpersioninfo.GetData(), m_callpersioninfo.GetCount(), sizeof(CallListPersionInfo), SortCmp, &ctx);
		return true;
	}

	static int __cdecl SortCmp(void *context, const void * p1, const void * p2)
	{
		SORTCTX *pctx = (SORTCTX*)context;
		const CallListPersionInfo *pSI1 = (const CallListPersionInfo*)p1;
		const CallListPersionInfo *pSI2 = (const CallListPersionInfo*)p2;
		int nRet = 0;
		switch (pctx->iCol)
		{
		case 0://name
			nRet = _tcscmp(pSI1->szName, pSI2->szName);
			break;
		case 1://status
			nRet = _tcscmp(pSI1->szStatus, pSI2->szStatus);
			break;
		case 2://dept
			nRet = _tcscmp(pSI1->szDept, pSI2->szDept);
			break;
		}
		if (pctx->stFlag == ST_UP)
			nRet = -nRet;
		return nRet;
	}
};

class CCurMeetFileListMcAdapterFix : public SMcAdapterBase
{
public:

	SArray<CurMeetFileListInfo> m_curMeetFileArray;

public:
	CCurMeetFileListMcAdapterFix()
	{
		SStringT strUploader[3] = { S_CW2T(GETSTRING(L"张三")),S_CW2T(GETSTRING(L"王五")),S_CW2T(GETSTRING(L"李四")) };
		SStringT strFileExt[3] = { S_CW2T(GETSTRING(L"word")),S_CW2T(GETSTRING(L"txt")),S_CW2T(GETSTRING(L"视频")) };
		SStringT strFileStatus[2] = { S_CW2T(GETSTRING(L"下载")),S_CW2T(GETSTRING(L"打开")) };
		for (int i = 0; i<30; i++)
		{
			CurMeetFileListInfo cp;
			_stprintf(cp.szFileName, _T("会议文件_%d"), i + 1);
			_tcscpy(cp.szUploader, strUploader[rand() % 3]);
			_tcscpy(cp.szFileExt, strFileExt[rand() % 3]);
			_stprintf(cp.szTime, _T("%s%d"),_T("今天14:"),rand()%59);
			_tcscpy(cp.szDownLoad, strFileStatus[rand() % 2]);
			_tcscpy(cp.szPreview, _T("预览"));
			m_curMeetFileArray.Add(cp);
		}
	}

	virtual int getCount()
	{
		return m_curMeetFileArray.GetCount();
	}


	virtual void getView(int position, SWindow * pItem, pugi::xml_node xmlTemplate)
	{
		if (pItem->GetChildrenCount() == 0)
		{
			pItem->InitFromXml(xmlTemplate);
		}

		CurMeetFileListInfo & cp = m_curMeetFileArray[position];
		pItem->FindChildByName(L"txt_filename")->SetWindowText(cp.szFileName);
		pItem->FindChildByName(L"txt_uploader")->SetWindowText(cp.szUploader);
		pItem->FindChildByName(L"txt_fileext")->SetWindowText(cp.szFileExt);
		pItem->FindChildByName(L"txt_uploadtime")->SetWindowText(cp.szTime);
		//pItem->FindChildByName(L"txt_download")->SetWindowText(cp.szDownLoad);
		//pItem->FindChildByName(L"txt_preview")->SetWindowText(cp.szPreview);
	}

	virtual SStringW GetColumnName(int iCol) const override
	{
		//return L"";
		return SStringW().Format(L"col%d", iCol + 1);
	}

	struct SORTCTX
	{
		int iCol;
		SHDSORTFLAG stFlag;
	};

	bool OnSort(int iCol, SHDSORTFLAG * stFlags, int nCols)
	{
		if (iCol == 5) //最后一列“操作”不支持排序
			return false;

		SHDSORTFLAG stFlag = stFlags[iCol];
		switch (stFlag)
		{
		case ST_NULL:stFlag = ST_UP; break;
		case ST_DOWN:stFlag = ST_UP; break;
		case ST_UP:stFlag = ST_DOWN; break;
		}
		for (int i = 0; i<nCols; i++)
		{
			stFlags[i] = ST_NULL;
		}
		stFlags[iCol] = stFlag;

		SORTCTX ctx = { iCol,stFlag };
		qsort_s(m_curMeetFileArray.GetData(), m_curMeetFileArray.GetCount(), sizeof(CurMeetFileListInfo), SortCmp, &ctx);
		return true;
	}

	static int __cdecl SortCmp(void *context, const void * p1, const void * p2)
	{
		SORTCTX *pctx = (SORTCTX*)context;
		const CurMeetFileListInfo *pSI1 = (const CurMeetFileListInfo*)p1;
		const CurMeetFileListInfo *pSI2 = (const CurMeetFileListInfo*)p2;
		int nRet = 0;
		switch (pctx->iCol)
		{
		case 0://name
			nRet = _tcscmp(pSI1->szFileName, pSI2->szFileName);
			break;
		case 1://status
			nRet = _tcscmp(pSI1->szUploader, pSI2->szUploader);
			break;
		case 2://dept
			nRet = _tcscmp(pSI1->szFileExt, pSI2->szFileExt);
			break;
		case 3://name
			nRet = _tcscmp(pSI1->szTime, pSI2->szTime);
			break;
		case 4://status
			//nRet = _tcscmp(pSI1->szDownLoad, pSI2->szDownLoad);
			break;
		case 5://dept
			//nRet = _tcscmp(pSI1->szPreview, pSI2->szPreview);
			break;
		}
		if (pctx->stFlag == ST_UP)
			nRet = -nRet;
		return nRet;
	}
};

class CMeetListTileAdapter : public SAdapterBase
{
public:
	CMeetListTileAdapter()
	{
		strMeetStatus[0] = _T("未开始");
		strMeetStatus[1] = _T("正在进行");
		strMeetStatus[2] = _T("已结束");
	}
	virtual int getCount()
	{
		return 7;
	}

	virtual void getView(int position, SWindow *pItem, pugi::xml_node xmlTemplate)
	{
		if (pItem->GetChildrenCount() == 0)
		{
			pItem->InitFromXml(xmlTemplate);
		}
		
		//SImageWnd *pImg = pItem->FindChildByName2<SImageWnd>(L"img_meet_icon");
		//pImg->SetSkin(GETSKIN(skins[position % 5], pImg->GetScale()));
		SStatic *pTxtTitle = pItem->FindChildByName2<SStatic>(L"txt_meettitle");
		pTxtTitle->SetWindowText(SStringT().Format(_T("第%d次常委扩大会议"), position+1));
		pTxtTitle->GetRoot()->SetUserData(position);

		SStatic *pTxtStartTime = pItem->FindChildByName2<SStatic>(L"txt_meetstarttime");
		pTxtStartTime->SetWindowText(SStringT().Format(_T("%d：00"), position+7));
		pTxtStartTime->GetRoot()->SetUserData(position);

		SStatic *pTxtEndTime = pItem->FindChildByName2<SStatic>(L"txt_meetendtime");
		pTxtEndTime->SetWindowText(SStringT().Format(_T("%d：30"), position+7));
		pTxtEndTime->GetRoot()->SetUserData(position);

		//srand(time(NULL));
		int nstatus = rand() % 3;
		SStatic *pTxtStatus = pItem->FindChildByName2<SStatic>(L"txt_meetstatus");
		pTxtStatus->SetWindowText(strMeetStatus[nstatus]);
		pTxtStatus->GetRoot()->SetUserData(position);


		SButton *pBtn = pItem->FindChildByName2<SButton>(L"btn_join");
		//pBtn->SetWindowText(SStringT().Format(_T("加入 %d"), nstatus));
		if (nstatus == 2)
		{
			pBtn->EnableWindow(FALSE, TRUE);
		}
		else
		{
			pBtn->EnableWindow(TRUE, TRUE);
		}
		pBtn->GetRoot()->SetUserData(position);
		pBtn->GetEventSet()->subscribeEvent(EVT_CMD, Subscriber(&CMeetListTileAdapter::OnButtonClick, this));
	}

	bool OnButtonClick(EventArgs *pEvt)
	{

		SButton *pBtn = sobj_cast<SButton>(pEvt->sender);
		int iItem = pBtn->GetRoot()->GetUserData();
		SWindow *pItem= pBtn->GetRoot()->GetWindow(iItem);
		SStatic *pTxtTitle= pItem->FindChildByName2<SStatic>(L"txt_meettitle");
		SStringT strTitle;
		if (pTxtTitle)
		{
			strTitle = pTxtTitle->GetWindowTextW();
		}
		
		SMessageBox(NULL, SStringT().Format(_T("%s 进入会议中……"), strTitle), strTitle, MB_OK);
		return true;
	}

	SStringT strMeetStatus[3];
};

class CMeetNoticeTVAdapter : public SAdapterBase
{
public:
	CMeetNoticeTVAdapter()
	{

	}
	virtual int getCount()
	{
		return 5;
	}

	virtual void getView(int position, SWindow *pItem, pugi::xml_node xmlTemplate)
	{
		if (pItem->GetChildrenCount() == 0)
		{
			pItem->InitFromXml(xmlTemplate);
		}

		//SImageWnd *pImg = pItem->FindChildByName2<SImageWnd>(L"img_meet_icon");
		//pImg->SetSkin(GETSKIN(skins[position % 5], pImg->GetScale()));
		SStatic *pTxtTitle = pItem->FindChildByName2<SStatic>(L"txt_meet_notice_title");
		pTxtTitle->SetWindowText(SStringT().Format(_T("第三代产品第%d次会议"), position + 1));
		pTxtTitle->GetRoot()->SetUserData(position);

		SStatic *pTxtStartTime = pItem->FindChildByName2<SStatic>(L"txt_meet_rest_time");
		pTxtStartTime->SetWindowText(SStringT().Format(_T("%d:02%d20"), position +1,rand()%60));
		pTxtStartTime->GetRoot()->SetUserData(position);
	
	}

	bool OnButtonClick(EventArgs *pEvt)
	{

		/*
		SButton *pBtn = sobj_cast<SButton>(pEvt->sender);
		int iItem = pBtn->GetRoot()->GetUserData();
		SWindow *pItem = pBtn->GetRoot()->GetWindow(iItem);
		SStatic *pTxtTitle = pItem->FindChildByName2<SStatic>(L"txt_meettitle");
		SStringT strTitle;
		if (pTxtTitle)
		{
			strTitle = pTxtTitle->GetWindowTextW();
		}

		SMessageBox(NULL, SStringT().Format(_T("%s 进入会议中……"), strTitle), strTitle, MB_OK);
		*/
		return true;
	}

	
};

class CMeetVideoFileTVAdapter : public SAdapterBase
{
public:
	CMeetVideoFileTVAdapter()
	{

	}
	virtual int getCount()
	{
		return 7;
	}

	virtual void getView(int position, SWindow *pItem, pugi::xml_node xmlTemplate)
	{
		if (pItem->GetChildrenCount() == 0)
		{
			pItem->InitFromXml(xmlTemplate);
		}

		//SImageWnd *pImg = pItem->FindChildByName2<SImageWnd>(L"img_meet_icon");
		//pImg->SetSkin(GETSKIN(skins[position % 5], pImg->GetScale()));
		SStatic *pTxtVideoName = pItem->FindChildByName2<SStatic>(L"txt_meet_video_name");
		pTxtVideoName->SetWindowText(SStringT().Format(_T("关于第三代产品设计之前的事项研讨%d"), position + 1));
		pTxtVideoName->GetRoot()->SetUserData(position);

		SStatic *pTxtVideoDate = pItem->FindChildByName2<SStatic>(L"txt_meet_video_date");
		pTxtVideoDate->SetWindowText(SStringT().Format(_T("2017/%d/%d"), rand()%12+1,rand()%30+1));
		pTxtVideoDate->GetRoot()->SetUserData(position);

		SButton *pPlayBtn = pItem->FindChildByName2<SButton>(L"btn_video_play");
		//pBtn->SetWindowText(SStringT().Format(_T("加入 %d"), nstatus));
		pPlayBtn->GetRoot()->SetUserData(position);
		pPlayBtn->GetEventSet()->subscribeEvent(EVT_CMD, Subscriber(&CMeetVideoFileTVAdapter::OnButtonClickPlay , this));

		SButton *pOpenDirBtn = pItem->FindChildByName2<SButton>(L"btn_video_filedir_open");
		//pBtn->SetWindowText(SStringT().Format(_T("加入 %d"), nstatus));
		pOpenDirBtn->GetRoot()->SetUserData(position);
		pOpenDirBtn->GetEventSet()->subscribeEvent(EVT_CMD, Subscriber(&CMeetVideoFileTVAdapter::OnButtonClickOpenDir, this));

	}

	bool OnButtonClickPlay(EventArgs *pEvt)
	{

		SButton *pBtn = sobj_cast<SButton>(pEvt->sender);
		int iItem = pBtn->GetRoot()->GetUserData();
		//SWindow *pItem = pBtn->GetRoot()->GetWindow(iItem);
		//SStatic *pTxtTitle = pItem->FindChildByName2<SStatic>(L"txt_meet_video_name");
		SStringT strTitle;
		//if (pTxtTitle)
		{
			//strTitle = pTxtTitle->GetWindowTextW();
		}

		SMessageBox(NULL, SStringT().Format(_T("%s 播放"), strTitle), _T("haha"), MB_OK);
		return true;
	}

	bool OnButtonClickOpenDir(EventArgs *pEvt)
	{

		SButton *pBtn = sobj_cast<SButton>(pEvt->sender);
		int iItem = pBtn->GetRoot()->GetUserData();
		//SWindow *pItem = pBtn->GetRoot()->GetWindow(iItem);
		//SStatic *pTxtTitle = pItem->FindChildByName2<SStatic>(L"txt_meet_video_name");
		SStringT strTitle;
		//if (pTxtTitle)
		{
			//strTitle = pTxtTitle->GetWindowTextW();
		}

		SMessageBox(NULL, SStringT().Format(_T("%s 打开文件夹"), strTitle), strTitle, MB_OK);
		return true;
	}

};

class CGroupInviterTVAdapter : public SAdapterBase
{
public:
	CGroupInviterTVAdapter(vector<SStringT> vec)
	{
		m_vec = vec;
	}
	virtual int getCount()
	{
		return m_vec.size();
	}
	void SetParam(vector<SStringT> vec)
	{
		m_vec = vec;
	}

	virtual void getView(int position, SWindow *pItem, pugi::xml_node xmlTemplate)
	{
		if (pItem->GetChildrenCount() == 0)
		{
			pItem->InitFromXml(xmlTemplate);
		}
		if (position >= m_vec.size()) return;
		
		SStatic *pTxtVideoName = pItem->FindChildByName2<SStatic>(L"txt_staff_name");
		pTxtVideoName->SetWindowText(m_vec[position]);
		pTxtVideoName->GetRoot()->SetUserData(position);

		
		SImageButton *pPlayBtn = pItem->FindChildByName2<SImageButton>(L"img_staff_del");
		pPlayBtn->GetRoot()->SetUserData(position);
		pPlayBtn->GetEventSet()->subscribeEvent(EVT_CMD, Subscriber(&CGroupInviterTVAdapter::OnButtonClickDel, this));

	}

	bool OnButtonClickDel(EventArgs *pEvt)
	{

		SButton *pBtn = sobj_cast<SButton>(pEvt->sender);
		int iItem = pBtn->GetRoot()->GetUserData();
		// TODO : 删除当前参会人员
		return true;
	}

private:
	vector<SStringT> m_vec;

};
