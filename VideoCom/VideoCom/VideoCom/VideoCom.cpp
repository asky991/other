// dui-demo.cpp : main source file
//

#include "stdafx.h"
#include "MainDlg.h"
#include "LoginDlg.h"
#include "STabCtrl2.h"
#include "SAnimImg.h"

#include "../controls.extend/SChromeTabCtrl.h"
#include "../controls.extend/simagemaskwnd.h"
#include "../controls.extend/SListboxex.h"

#include "extend.ctrls/SButtonEx.h"
#include "extend.ctrls/ExtendCtrls.h"
#include "extend.ctrls/imre/SImRichedit.h"
#include "extend.ctrls/SSplitBar.h"
#include "extend.ctrls/SImageView.h"

#include "extend.skins/ExtendSkins.h"
#include "extend.skins/SAntialiasSkin.h"
#include "extend.skins/SVscrollbar.h"
#include <control/SDateTimePicker.h>
#include "../controls.extend/SCalendar2.h"

//从PE文件加载，注意从文件加载路径位置
#define RES_TYPE 0   //从文件中加载资源
// #define RES_TYPE 1  //从PE资源中加载UI资源

#ifdef _DEBUG
#define SYS_NAMED_RESOURCE _T("soui-sys-resourced.dll")
#else
#define SYS_NAMED_RESOURCE _T("soui-sys-resource.dll")
#endif
	
//定义唯一的一个R,UIRES对象,ROBJ_IN_CPP是resource.h中定义的宏。
ROBJ_IN_CPP
	
int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int /*nCmdShow*/)
{
    HRESULT hRes = OleInitialize(NULL);
    SASSERT(SUCCEEDED(hRes));

    int nRet = 0;
	
    SComMgr *pComMgr = new SComMgr;
	//SComMgr *pComMgr = new SComMgr(_T("imgdecoder-gdip"));

    //将程序的运行路径修改到项目所在目录所在的目录
    TCHAR szCurrentDir[MAX_PATH] = { 0 };
    GetModuleFileName(NULL, szCurrentDir, sizeof(szCurrentDir));
    LPTSTR lpInsertPos = _tcsrchr(szCurrentDir, _T('\\'));
    _tcscpy(lpInsertPos + 1, _T("..\\VideoCom"));
    SetCurrentDirectory(szCurrentDir);
    {
        BOOL bLoaded=FALSE;
        CAutoRefPtr<SOUI::IImgDecoderFactory> pImgDecoderFactory;
        CAutoRefPtr<SOUI::IRenderFactory> pRenderFactory;
        bLoaded = pComMgr->CreateRender_GDI((IObjRef**)&pRenderFactory);
        SASSERT_FMT(bLoaded,_T("load interface [render] failed!"));
        bLoaded=pComMgr->CreateImgDecoder((IObjRef**)&pImgDecoderFactory);
        SASSERT_FMT(bLoaded,_T("load interface [%s] failed!"),_T("imgdecoder"));

        pRenderFactory->SetImgDecoderFactory(pImgDecoderFactory);
        SApplication *theApp = new SApplication(pRenderFactory, hInstance);
		g_theApp = theApp;
        //从DLL加载系统资源
        HMODULE hModSysResource = LoadLibrary(SYS_NAMED_RESOURCE);
        if (hModSysResource)
        {
            CAutoRefPtr<IResProvider> sysResProvider;
            CreateResProvider(RES_PE, (IObjRef**)&sysResProvider);
            sysResProvider->Init((WPARAM)hModSysResource, 0);
            theApp->LoadSystemNamedResource(sysResProvider);
            FreeLibrary(hModSysResource);
        }else
        {
            SASSERT(0);
        }

        CAutoRefPtr<IResProvider>   pResProvider;
#if (RES_TYPE == 0)
        CreateResProvider(RES_FILE, (IObjRef**)&pResProvider);
        if (!pResProvider->Init((LPARAM)_T("uires"), 0))
        {
            SASSERT(0);
            return 1;
        }
#else 
        CreateResProvider(RES_PE, (IObjRef**)&pResProvider);
        pResProvider->Init((WPARAM)hInstance, 0);
#endif

		theApp->RegisterWindowClass<STurn3dView>();

		// extened controls
		theApp->RegisterWindowClass<SChromeTabCtrl>();//注册ChromeTabCtrl
		theApp->RegisterWindowClass<SImageMaskWnd>();//注册SImageMaskWnd
		theApp->RegisterWindowClass<SButtonEx>();
		theApp->RegisterWindowClass<SWindowEx>();
		theApp->RegisterWindowClass<SImRichEdit>();
		theApp->RegisterWindowClass<SImageView>();
		theApp->RegisterWindowClass<SSplitBar>();
		theApp->RegisterWindowClass<SListBoxEx>();

		//extened skins
		theApp->RegisterSkinClass<SColorMask>();
		theApp->RegisterSkinClass<SAntialiasSkin>();
		theApp->RegisterSkinClass<SSkinVScrollbar>();

		theApp->RegisterWindowClass<STabPage2>();//注册STabPage2
		theApp->RegisterWindowClass<STabCtrl2>();//注册STabCtrl2
		theApp->RegisterWindowClass<SAnimImg>();//注册SAnimImg
		theApp->RegisterWindowClass<SStatic>();//注册SAnimImg
		theApp->RegisterWindowClass<SListCtrl>();//注册SAnimImg
		theApp->RegisterWindowClass<SDateTimePicker>();//

		
		theApp->InitXmlNamedID(namedXmlID,ARRAYSIZE(namedXmlID),TRUE);
        theApp->AddResProvider(pResProvider);

        
        // BLOCK: Run application
        {
			// login
			CLoginDlg dlgLogin;
			dlgLogin.Create(GetActiveWindow(), 0, 0, 0, 0);
			dlgLogin.SendMessage(WM_INITDIALOG);
			dlgLogin.CenterWindow(dlgLogin.m_hWnd);
			dlgLogin.AnimateHostWindow(200, AW_CENTER);
			nRet = theApp->Run(dlgLogin.m_hWnd);
			if(dlgLogin.GetReturnCode()==0)
			{
				CMainDlg dlgMain;
				dlgMain.Create(GetActiveWindow());
				dlgMain.SendMessage(WM_INITDIALOG);
				dlgMain.CenterWindow(dlgMain.m_hWnd);
				dlgMain.ShowWindow(SW_SHOWNORMAL);
				nRet = theApp->Run(dlgMain.m_hWnd);
			}

        }

        delete theApp;
    }
    
    delete pComMgr;
    
    OleUninitialize();
    return nRet;
}
