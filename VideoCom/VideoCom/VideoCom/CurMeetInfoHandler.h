#pragma once

//#include "CodeLineCounter.h"
//#include "FolderHander.h"


class CCurMeetInfoHandler :public SHostWnd
{
    friend class CMainDlg;
    struct FILEINFO
    {
        SOUI::SStringW strFileName;
        DWORD    dwSize;
        //SOUI::CCodeConfig cfg;
    };
public:
	CCurMeetInfoHandler(void);
    ~CCurMeetInfoHandler(void);

    void OnInit(SOUI::SWindow *pRoot);
protected:
    
   // void OnBtnGo();

    EVENT_MAP_BEGIN()
        EVENT_CHECK_SENDER_ROOT(m_pPageRoot)
       // EVENT_NAME_COMMAND(L"btn_go", OnBtnGo)
       // CHAIN_EVENT_MAP(CFolderHander)
    EVENT_MAP_END()

	SOUI::SWindow * m_pPageRoot;
//protected:
	//typedef SOUI::SMap<SOUI::SStringW, SOUI::CCodeConfig> CODECFGMAP;

	//DWORD EnumFileInfo(const CODECFGMAP &cfg, const SOUI::SStringW & strPath, HSTREEITEM hItem, SOUI::SList<FILEINFO> & lstFileInfo, int &nDirs);
   // CODECFGMAP m_mapCodeCfg;
};
