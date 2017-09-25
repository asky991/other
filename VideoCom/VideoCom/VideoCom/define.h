#pragma once
#include <string/tstring.h>

struct STUserInfo
{
	SStringT name;
	SStringT Tel;
	SStringT Email;
	SStringT Dept;
	SStringT Pos;
	SStringT HeadImgFile;
};

struct CallListPersionInfo
{
	TCHAR  szName[50];
	TCHAR  szDept[10];
	TCHAR  szStatus[20];
};

struct CurMeetFileListInfo
{
	TCHAR  szFileName[100];
	TCHAR  szUploader[10];
	TCHAR  szFileExt[20];
	TCHAR  szTime[30];
	TCHAR  szDownLoad[30];
	TCHAR szPreview[30];
};

enum emMeetStatusType
{
	MEET_NONE,
	MEET_BEGIN,
	MEET_END,
	MEET_CLOSE

};

struct MeetStatusInfo
{
	SStringT strMeetTitle;
	SStringT strMeetStartTime;
	SStringT strMeetEndTime;
	emMeetStatusType type;
};

struct MeetNoticeInfo
{
	SStringT strNoticeTitle;
	SStringT strRestTime;
};

struct MeetVideoFileInfo
{
	SStringT strFileName;
	SStringT strTime;
	SStringT strFilePath; // 可能不需要，把文件归类放到不同的文件夹，通过名字去查找

};
