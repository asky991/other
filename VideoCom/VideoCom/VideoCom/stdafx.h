// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//  are changed infrequently
//

#pragma once

#define  _CRT_SECURE_NO_WARNINGS
#define	 DLL_SOUI
#include <souistd.h>
#include <core/SHostDialog.h>
#include <control/SMessageBox.h>
#include <control/souictrls.h>
#include <res.mgr/sobjdefattr.h>
#include <com-cfg.h>
#include "resource.h"
#define R_IN_CPP	//定义这个开关来
#include "res\resource.h"
using namespace SOUI;
#include "layout/SouiLayout.h"
#include "..\controls.extend\STurn3DView.h"
#include "helper\SMenuEx.h"
#include "helper\SMenu.h"

#include <string>
#include <vector>
using namespace std;
#include <iostream>
extern SApplication *g_theApp;
#include <control\SCmnCtrl.h>
#include "STabCtrl2.h"
#include "control\SListCtrl.h"

#include "define.h"
#include "CDefAdapter.h""