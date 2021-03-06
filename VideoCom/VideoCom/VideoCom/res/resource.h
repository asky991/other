//stamp:17b8212133f4eb94
/*<------------------------------------------------------------------------------------------------->*/
/*该文件由uiresbuilder生成，请不要手动修改*/
/*<------------------------------------------------------------------------------------------------->*/
#pragma once
#include <res.mgr/snamedvalue.h>
#define ROBJ_IN_CPP \
namespace SOUI \
{\
    const _R R;\
    const _UIRES UIRES;\
}
namespace SOUI
{
	class _UIRES{
		public:
		class _UIDEF{
			public:
			_UIDEF(){
				XML_INIT = _T("UIDEF:XML_INIT");
			}
			const TCHAR * XML_INIT;
		}UIDEF;
		class _LAYOUT{
			public:
			_LAYOUT(){
				XML_LOGIN = _T("LAYOUT:XML_LOGIN");
				PAGE_LOGIN = _T("LAYOUT:PAGE_LOGIN");
				PAGE_SETTINGS = _T("LAYOUT:PAGE_SETTINGS");
				XML_MAINWND = _T("LAYOUT:XML_MAINWND");
				PAGE_MAIN_1 = _T("LAYOUT:PAGE_MAIN_1");
				DLG_USER_SETTING = _T("LAYOUT:DLG_USER_SETTING");
				DLG_MEET_CREATE = _T("LAYOUT:DLG_MEET_CREATE");
				DLG_EMP_INFO = _T("LAYOUT:DLG_EMP_INFO");
				DLG_MEET_NOTICE = _T("LAYOUT:DLG_MEET_NOTICE");
			}
			const TCHAR * XML_LOGIN;
			const TCHAR * PAGE_LOGIN;
			const TCHAR * PAGE_SETTINGS;
			const TCHAR * XML_MAINWND;
			const TCHAR * PAGE_MAIN_1;
			const TCHAR * DLG_USER_SETTING;
			const TCHAR * DLG_MEET_CREATE;
			const TCHAR * DLG_EMP_INFO;
			const TCHAR * DLG_MEET_NOTICE;
		}LAYOUT;
		class _SMENUEX{
			public:
			_SMENUEX(){
				menuex_oper = _T("SMENUEX:menuex_oper");
				menuex_emp_oper = _T("SMENUEX:menuex_emp_oper");
				menuex_meet_oper = _T("SMENUEX:menuex_meet_oper");
			}
			const TCHAR * menuex_oper;
			const TCHAR * menuex_emp_oper;
			const TCHAR * menuex_meet_oper;
		}SMENUEX;
		class _IMGX{
			public:
			_IMGX(){
				IMG_LOGIN_BORDER = _T("IMGX:IMG_LOGIN_BORDER");
				BTN_LOGIN_SETTING = _T("IMGX:BTN_LOGIN_SETTING");
				BTN_USERLISTCLOSE = _T("IMGX:BTN_USERLISTCLOSE");
				BTN_REGISTER = _T("IMGX:BTN_REGISTER");
				BTN_GETPSWBACK = _T("IMGX:BTN_GETPSWBACK");
				BTN_KEYBOARD = _T("IMGX:BTN_KEYBOARD");
				BTN_LOGIN = _T("IMGX:BTN_LOGIN");
				BTN_LOGIN2 = _T("IMGX:BTN_LOGIN2");
				BTN_LOGIN_2DCODE = _T("IMGX:BTN_LOGIN_2DCODE");
				IMG_HEAD_MASK = _T("IMGX:IMG_HEAD_MASK");
				IMG_HEAD = _T("IMGX:IMG_HEAD");
				IMG_AVATARS = _T("IMGX:IMG_AVATARS");
			}
			const TCHAR * IMG_LOGIN_BORDER;
			const TCHAR * BTN_LOGIN_SETTING;
			const TCHAR * BTN_USERLISTCLOSE;
			const TCHAR * BTN_REGISTER;
			const TCHAR * BTN_GETPSWBACK;
			const TCHAR * BTN_KEYBOARD;
			const TCHAR * BTN_LOGIN;
			const TCHAR * BTN_LOGIN2;
			const TCHAR * BTN_LOGIN_2DCODE;
			const TCHAR * IMG_HEAD_MASK;
			const TCHAR * IMG_HEAD;
			const TCHAR * IMG_AVATARS;
		}IMGX;
		class _jpg{
			public:
			_jpg(){
				IMG_HEAD_SMALL = _T("jpg:IMG_HEAD_SMALL");
			}
			const TCHAR * IMG_HEAD_SMALL;
		}jpg;
		class _ICON{
			public:
			_ICON(){
				ICON_LOGO = _T("ICON:ICON_LOGO");
			}
			const TCHAR * ICON_LOGO;
		}ICON;
		class _PNG{
			public:
			_PNG(){
				ID_SYSBTN_CLOSE = _T("PNG:ID_SYSBTN_CLOSE");
				ID_SYSBTN_MAX = _T("PNG:ID_SYSBTN_MAX");
				ID_SYSBTN_MIN = _T("PNG:ID_SYSBTN_MIN");
				ID_SYSBTN_RESTORE = _T("PNG:ID_SYSBTN_RESTORE");
				ID_TAB_FADE_EFF = _T("PNG:ID_TAB_FADE_EFF");
				ID_SHADOW = _T("PNG:ID_SHADOW");
				ID_TAB_SCROLL = _T("PNG:ID_TAB_SCROLL");
				ID_TABBTN_CLOSE = _T("PNG:ID_TABBTN_CLOSE");
				ID_SPLITBAR_VER = _T("PNG:ID_SPLITBAR_VER");
				ID_TABBTN = _T("PNG:ID_TABBTN");
				ID_ICON1 = _T("PNG:ID_ICON1");
				ID_ICON2 = _T("PNG:ID_ICON2");
				ID_ICON3 = _T("PNG:ID_ICON3");
				ID_ICON4 = _T("PNG:ID_ICON4");
				ID_ICON5 = _T("PNG:ID_ICON5");
				ID_ICON_MASK = _T("PNG:ID_ICON_MASK");
				ID_GROUP_TOPTOOLBAR = _T("PNG:ID_GROUP_TOPTOOLBAR");
				ID_GROUP_TABBTN = _T("PNG:ID_GROUP_TABBTN");
				ID_AD = _T("PNG:ID_AD");
				ID_EMPTY = _T("PNG:ID_EMPTY");
				ID_NO_ANNOUCE = _T("PNG:ID_NO_ANNOUCE");
				ID_GROUP_APP1 = _T("PNG:ID_GROUP_APP1");
				ID_GROUP_APP2 = _T("PNG:ID_GROUP_APP2");
				ID_GROUP_APP3 = _T("PNG:ID_GROUP_APP3");
				ID_GROUP_APP4 = _T("PNG:ID_GROUP_APP4");
				ID_GROUP_APP5 = _T("PNG:ID_GROUP_APP5");
				ID_GROUP_APP6 = _T("PNG:ID_GROUP_APP6");
				ID_GROUP_APP_TABICON = _T("PNG:ID_GROUP_APP_TABICON");
				ID_GROUP_APP_TABBTN = _T("PNG:ID_GROUP_APP_TABBTN");
				ID_GROUP_EXPAND_BTN = _T("PNG:ID_GROUP_EXPAND_BTN");
				ID_GROUP_SEARCH_CHK = _T("PNG:ID_GROUP_SEARCH_CHK");
				ID_SENDBTN_LEFT = _T("PNG:ID_SENDBTN_LEFT");
				ID_SENDBTN_RIGHT = _T("PNG:ID_SENDBTN_RIGHT");
				ID_SENDBTN_SPLITLINE = _T("PNG:ID_SENDBTN_SPLITLINE");
				ID_SENDBTN_ARROW = _T("PNG:ID_SENDBTN_ARROW");
				ID_CHATBTN_CLOSE = _T("PNG:ID_CHATBTN_CLOSE");
				ID_CHATBTN_FONT = _T("PNG:ID_CHATBTN_FONT");
				ID_CHAT_TOOLBAT_BK = _T("PNG:ID_CHAT_TOOLBAT_BK");
				ID_CHATBTN_CUT = _T("PNG:ID_CHATBTN_CUT");
				ID_CHAT_TOOLBTN_ARROW = _T("PNG:ID_CHAT_TOOLBTN_ARROW");
				ID_CHAT_QUICKBAR_UPLOADFILE = _T("PNG:ID_CHAT_QUICKBAR_UPLOADFILE");
				ID_CHAT_QUICKBAR_SENDPIC = _T("PNG:ID_CHAT_QUICKBAR_SENDPIC");
				ID_RICH_FILE_BK = _T("PNG:ID_RICH_FILE_BK");
				ID_FILE_ICON_TEXT = _T("PNG:ID_FILE_ICON_TEXT");
				ID_FETCH_MORE = _T("PNG:ID_FETCH_MORE");
				ID_LOADING = _T("PNG:ID_LOADING");
				ID_NEW_BG = _T("PNG:ID_NEW_BG");
				ID_NEWS_BG_ALPHA = _T("PNG:ID_NEWS_BG_ALPHA");
				ID_MENU_BKG = _T("PNG:ID_MENU_BKG");
				ID_SMALL_ICON = _T("PNG:ID_SMALL_ICON");
				ID_BKGND_MASK = _T("PNG:ID_BKGND_MASK");
				ID_BACKGROUND = _T("PNG:ID_BACKGROUND");
				ID_RICH_WARNING = _T("PNG:ID_RICH_WARNING");
				ID_RICH_LEFT_BUBBLE = _T("PNG:ID_RICH_LEFT_BUBBLE");
				ID_RICH_RIGHT_BUBBLE = _T("PNG:ID_RICH_RIGHT_BUBBLE");
				ID_RICH_SYSMSG_BK = _T("PNG:ID_RICH_SYSMSG_BK");
				ID_DEF_VSCROLL = _T("PNG:ID_DEF_VSCROLL");
				images_zdh_png = _T("PNG:images_zdh_png");
			}
			const TCHAR * ID_SYSBTN_CLOSE;
			const TCHAR * ID_SYSBTN_MAX;
			const TCHAR * ID_SYSBTN_MIN;
			const TCHAR * ID_SYSBTN_RESTORE;
			const TCHAR * ID_TAB_FADE_EFF;
			const TCHAR * ID_SHADOW;
			const TCHAR * ID_TAB_SCROLL;
			const TCHAR * ID_TABBTN_CLOSE;
			const TCHAR * ID_SPLITBAR_VER;
			const TCHAR * ID_TABBTN;
			const TCHAR * ID_ICON1;
			const TCHAR * ID_ICON2;
			const TCHAR * ID_ICON3;
			const TCHAR * ID_ICON4;
			const TCHAR * ID_ICON5;
			const TCHAR * ID_ICON_MASK;
			const TCHAR * ID_GROUP_TOPTOOLBAR;
			const TCHAR * ID_GROUP_TABBTN;
			const TCHAR * ID_AD;
			const TCHAR * ID_EMPTY;
			const TCHAR * ID_NO_ANNOUCE;
			const TCHAR * ID_GROUP_APP1;
			const TCHAR * ID_GROUP_APP2;
			const TCHAR * ID_GROUP_APP3;
			const TCHAR * ID_GROUP_APP4;
			const TCHAR * ID_GROUP_APP5;
			const TCHAR * ID_GROUP_APP6;
			const TCHAR * ID_GROUP_APP_TABICON;
			const TCHAR * ID_GROUP_APP_TABBTN;
			const TCHAR * ID_GROUP_EXPAND_BTN;
			const TCHAR * ID_GROUP_SEARCH_CHK;
			const TCHAR * ID_SENDBTN_LEFT;
			const TCHAR * ID_SENDBTN_RIGHT;
			const TCHAR * ID_SENDBTN_SPLITLINE;
			const TCHAR * ID_SENDBTN_ARROW;
			const TCHAR * ID_CHATBTN_CLOSE;
			const TCHAR * ID_CHATBTN_FONT;
			const TCHAR * ID_CHAT_TOOLBAT_BK;
			const TCHAR * ID_CHATBTN_CUT;
			const TCHAR * ID_CHAT_TOOLBTN_ARROW;
			const TCHAR * ID_CHAT_QUICKBAR_UPLOADFILE;
			const TCHAR * ID_CHAT_QUICKBAR_SENDPIC;
			const TCHAR * ID_RICH_FILE_BK;
			const TCHAR * ID_FILE_ICON_TEXT;
			const TCHAR * ID_FETCH_MORE;
			const TCHAR * ID_LOADING;
			const TCHAR * ID_NEW_BG;
			const TCHAR * ID_NEWS_BG_ALPHA;
			const TCHAR * ID_MENU_BKG;
			const TCHAR * ID_SMALL_ICON;
			const TCHAR * ID_BKGND_MASK;
			const TCHAR * ID_BACKGROUND;
			const TCHAR * ID_RICH_WARNING;
			const TCHAR * ID_RICH_LEFT_BUBBLE;
			const TCHAR * ID_RICH_RIGHT_BUBBLE;
			const TCHAR * ID_RICH_SYSMSG_BK;
			const TCHAR * ID_DEF_VSCROLL;
			const TCHAR * images_zdh_png;
		}PNG;
		class _img{
			public:
			_img(){
				IMG_HEAD_DEFAULT = _T("img:IMG_HEAD_DEFAULT");
				img_bg_png = _T("img:img_bg_png");
				img_play_bmp = _T("img:img_play_bmp");
				img_open_bmp = _T("img:img_open_bmp");
				img_staff_del_png = _T("img:img_staff_del_png");
				img_bg_main_jpg = _T("img:img_bg_main_jpg");
			}
			const TCHAR * IMG_HEAD_DEFAULT;
			const TCHAR * img_bg_png;
			const TCHAR * img_play_bmp;
			const TCHAR * img_open_bmp;
			const TCHAR * img_staff_del_png;
			const TCHAR * img_bg_main_jpg;
		}img;
		class _imgs{
			public:
			_imgs(){
				images_cz_g_png = _T("imgs:images_cz_g_png");
				images_dbx_1_png = _T("imgs:images_dbx_1_png");
				images_dbx_2_png = _T("imgs:images_dbx_2_png");
				images_dbx_3_png = _T("imgs:images_dbx_3_png");
				images_df_header_b_png = _T("imgs:images_df_header_b_png");
				images_df_header_m_png = _T("imgs:images_df_header_m_png");
				images_hysgl_png = _T("imgs:images_hysgl_png");
				images_logo_png = _T("imgs:images_logo_png");
				images_rl_png = _T("imgs:images_rl_png");
				images_syj_png = _T("imgs:images_syj_png");
				images_sz_png = _T("imgs:images_sz_png");
				images_wj_png = _T("imgs:images_wj_png");
				images_xz_png = _T("imgs:images_xz_png");
				images_xz2_png = _T("imgs:images_xz2_png");
				images_yjjx_png = _T("imgs:images_yjjx_png");
				images_yjjx2_png = _T("imgs:images_yjjx2_png");
				images_yl_png = _T("imgs:images_yl_png");
				images_zdh_png = _T("imgs:images_zdh_png");
			}
			const TCHAR * images_cz_g_png;
			const TCHAR * images_dbx_1_png;
			const TCHAR * images_dbx_2_png;
			const TCHAR * images_dbx_3_png;
			const TCHAR * images_df_header_b_png;
			const TCHAR * images_df_header_m_png;
			const TCHAR * images_hysgl_png;
			const TCHAR * images_logo_png;
			const TCHAR * images_rl_png;
			const TCHAR * images_syj_png;
			const TCHAR * images_sz_png;
			const TCHAR * images_wj_png;
			const TCHAR * images_xz_png;
			const TCHAR * images_xz2_png;
			const TCHAR * images_yjjx_png;
			const TCHAR * images_yjjx2_png;
			const TCHAR * images_yl_png;
			const TCHAR * images_zdh_png;
		}imgs;
	};
	const SNamedID::NAMEDVALUE namedXmlID[]={
		{L"_name_start",65535},
		{L"btn_MeetFileStatus",65590},
		{L"btn_cancel",65617},
		{L"btn_close",65541},
		{L"btn_eleb",65571},
		{L"btn_join",65576},
		{L"btn_login",65546},
		{L"btn_max",65612},
		{L"btn_min",65542},
		{L"btn_ok",65616},
		{L"btn_rec",65570},
		{L"btn_reg",65547},
		{L"btn_send_video",65632},
		{L"btn_setting",65543},
		{L"btn_setting_cancel",65556},
		{L"btn_setting_ok",65557},
		{L"btn_test_net_set",136},
		{L"btn_upload_head",65618},
		{L"btn_userinfo_setting",65560},
		{L"btn_video_filedir_open",65589},
		{L"btn_video_play",65588},
		{L"cap_login_head",65540},
		{L"cap_login_main",65539},
		{L"cbx_account",65545},
		{L"ck_local_meet",65626},
		{L"ck_video_meet",65624},
		{L"ck_voice_meet",65625},
		{L"col1",65593},
		{L"col2",65595},
		{L"col3",65597},
		{L"col4",65604},
		{L"col5",65606},
		{L"col6",65608},
		{L"dlg_userinfo",65610},
		{L"dtp_meet_end",65635},
		{L"dtp_meet_end_time",65621},
		{L"dtp_meet_start",65634},
		{L"dtp_meet_start_time",65620},
		{L"edit_dept",65633},
		{L"edit_email",65615},
		{L"edit_meet_content",65638},
		{L"edit_meet_end",65637},
		{L"edit_meet_end_time",65623},
		{L"edit_meet_name",65619},
		{L"edit_meet_start",65636},
		{L"edit_meet_start_time",65622},
		{L"edit_name",65613},
		{L"edit_tel",65614},
		{L"img_avatar",65544},
		{L"img_down_icon",65607},
		{L"img_emp_head",65631},
		{L"img_head_view",65559},
		{L"img_meet_icon",65574},
		{L"img_preview_icon",65609},
		{L"img_staff_del",65630},
		{L"img_wj_icon",65600},
		{L"imgbtn_operate_menu",65564},
		{L"list_mtstatus",65563},
		{L"lk_meet_notice_more",65580},
		{L"lk_meet_video_more",65581},
		{L"main_left_dlg",65558},
		{L"main_right_dlg",65568},
		{L"mclist_call",65592},
		{L"mclist_file",65599},
		{L"net_cfg_addr_edt",137},
		{L"net_cfg_field_edt",65553},
		{L"net_cfg_port_edt",65552},
		{L"net_cfg_pswd_edt",65551},
		{L"net_cfg_type_cmb",65549},
		{L"net_cfg_user_edt",65550},
		{L"serv_cfg_addr_edt",65554},
		{L"serv_cfg_port_edt",65555},
		{L"set_form",65548},
		{L"tab_main",65537},
		{L"tab_main_erp",65561},
		{L"tab_main_file",65591},
		{L"tab_right_video",65569},
		{L"tc_erp_info",65562},
		{L"turn3d",65538},
		{L"tv_group_inviter",65628},
		{L"tv_meet_notice",65582},
		{L"tv_meet_video_file",65585},
		{L"tv_meetlist",65573},
		{L"txt_dept",65598},
		{L"txt_fileext",65603},
		{L"txt_filename",65601},
		{L"txt_meet_notice_title",65583},
		{L"txt_meet_rest_time",65584},
		{L"txt_meet_video_date",65587},
		{L"txt_meet_video_name",65586},
		{L"txt_meetendtime",65578},
		{L"txt_meetstarttime",65577},
		{L"txt_meetstatus",65579},
		{L"txt_meettitle",65575},
		{L"txt_name",65594},
		{L"txt_staff",65627},
		{L"txt_staff_name",65629},
		{L"txt_status",65596},
		{L"txt_title",65611},
		{L"txt_uploader",65602},
		{L"txt_uploadtime",65605},
		{L"txt_user_dept",65566},
		{L"txt_user_pos",65567},
		{L"txt_username",65565},
		{L"win_login",65536},
		{L"wnd_drawboard",65572}		};
	class _R{
	public:
		class _name{
		public:
		_name(){
			_name_start = namedXmlID[0].strName;
			btn_MeetFileStatus = namedXmlID[1].strName;
			btn_cancel = namedXmlID[2].strName;
			btn_close = namedXmlID[3].strName;
			btn_eleb = namedXmlID[4].strName;
			btn_join = namedXmlID[5].strName;
			btn_login = namedXmlID[6].strName;
			btn_max = namedXmlID[7].strName;
			btn_min = namedXmlID[8].strName;
			btn_ok = namedXmlID[9].strName;
			btn_rec = namedXmlID[10].strName;
			btn_reg = namedXmlID[11].strName;
			btn_send_video = namedXmlID[12].strName;
			btn_setting = namedXmlID[13].strName;
			btn_setting_cancel = namedXmlID[14].strName;
			btn_setting_ok = namedXmlID[15].strName;
			btn_test_net_set = namedXmlID[16].strName;
			btn_upload_head = namedXmlID[17].strName;
			btn_userinfo_setting = namedXmlID[18].strName;
			btn_video_filedir_open = namedXmlID[19].strName;
			btn_video_play = namedXmlID[20].strName;
			cap_login_head = namedXmlID[21].strName;
			cap_login_main = namedXmlID[22].strName;
			cbx_account = namedXmlID[23].strName;
			ck_local_meet = namedXmlID[24].strName;
			ck_video_meet = namedXmlID[25].strName;
			ck_voice_meet = namedXmlID[26].strName;
			col1 = namedXmlID[27].strName;
			col2 = namedXmlID[28].strName;
			col3 = namedXmlID[29].strName;
			col4 = namedXmlID[30].strName;
			col5 = namedXmlID[31].strName;
			col6 = namedXmlID[32].strName;
			dlg_userinfo = namedXmlID[33].strName;
			dtp_meet_end = namedXmlID[34].strName;
			dtp_meet_end_time = namedXmlID[35].strName;
			dtp_meet_start = namedXmlID[36].strName;
			dtp_meet_start_time = namedXmlID[37].strName;
			edit_dept = namedXmlID[38].strName;
			edit_email = namedXmlID[39].strName;
			edit_meet_content = namedXmlID[40].strName;
			edit_meet_end = namedXmlID[41].strName;
			edit_meet_end_time = namedXmlID[42].strName;
			edit_meet_name = namedXmlID[43].strName;
			edit_meet_start = namedXmlID[44].strName;
			edit_meet_start_time = namedXmlID[45].strName;
			edit_name = namedXmlID[46].strName;
			edit_tel = namedXmlID[47].strName;
			img_avatar = namedXmlID[48].strName;
			img_down_icon = namedXmlID[49].strName;
			img_emp_head = namedXmlID[50].strName;
			img_head_view = namedXmlID[51].strName;
			img_meet_icon = namedXmlID[52].strName;
			img_preview_icon = namedXmlID[53].strName;
			img_staff_del = namedXmlID[54].strName;
			img_wj_icon = namedXmlID[55].strName;
			imgbtn_operate_menu = namedXmlID[56].strName;
			list_mtstatus = namedXmlID[57].strName;
			lk_meet_notice_more = namedXmlID[58].strName;
			lk_meet_video_more = namedXmlID[59].strName;
			main_left_dlg = namedXmlID[60].strName;
			main_right_dlg = namedXmlID[61].strName;
			mclist_call = namedXmlID[62].strName;
			mclist_file = namedXmlID[63].strName;
			net_cfg_addr_edt = namedXmlID[64].strName;
			net_cfg_field_edt = namedXmlID[65].strName;
			net_cfg_port_edt = namedXmlID[66].strName;
			net_cfg_pswd_edt = namedXmlID[67].strName;
			net_cfg_type_cmb = namedXmlID[68].strName;
			net_cfg_user_edt = namedXmlID[69].strName;
			serv_cfg_addr_edt = namedXmlID[70].strName;
			serv_cfg_port_edt = namedXmlID[71].strName;
			set_form = namedXmlID[72].strName;
			tab_main = namedXmlID[73].strName;
			tab_main_erp = namedXmlID[74].strName;
			tab_main_file = namedXmlID[75].strName;
			tab_right_video = namedXmlID[76].strName;
			tc_erp_info = namedXmlID[77].strName;
			turn3d = namedXmlID[78].strName;
			tv_group_inviter = namedXmlID[79].strName;
			tv_meet_notice = namedXmlID[80].strName;
			tv_meet_video_file = namedXmlID[81].strName;
			tv_meetlist = namedXmlID[82].strName;
			txt_dept = namedXmlID[83].strName;
			txt_fileext = namedXmlID[84].strName;
			txt_filename = namedXmlID[85].strName;
			txt_meet_notice_title = namedXmlID[86].strName;
			txt_meet_rest_time = namedXmlID[87].strName;
			txt_meet_video_date = namedXmlID[88].strName;
			txt_meet_video_name = namedXmlID[89].strName;
			txt_meetendtime = namedXmlID[90].strName;
			txt_meetstarttime = namedXmlID[91].strName;
			txt_meetstatus = namedXmlID[92].strName;
			txt_meettitle = namedXmlID[93].strName;
			txt_name = namedXmlID[94].strName;
			txt_staff = namedXmlID[95].strName;
			txt_staff_name = namedXmlID[96].strName;
			txt_status = namedXmlID[97].strName;
			txt_title = namedXmlID[98].strName;
			txt_uploader = namedXmlID[99].strName;
			txt_uploadtime = namedXmlID[100].strName;
			txt_user_dept = namedXmlID[101].strName;
			txt_user_pos = namedXmlID[102].strName;
			txt_username = namedXmlID[103].strName;
			win_login = namedXmlID[104].strName;
			wnd_drawboard = namedXmlID[105].strName;
		}
		 const wchar_t * _name_start;
		 const wchar_t * btn_MeetFileStatus;
		 const wchar_t * btn_cancel;
		 const wchar_t * btn_close;
		 const wchar_t * btn_eleb;
		 const wchar_t * btn_join;
		 const wchar_t * btn_login;
		 const wchar_t * btn_max;
		 const wchar_t * btn_min;
		 const wchar_t * btn_ok;
		 const wchar_t * btn_rec;
		 const wchar_t * btn_reg;
		 const wchar_t * btn_send_video;
		 const wchar_t * btn_setting;
		 const wchar_t * btn_setting_cancel;
		 const wchar_t * btn_setting_ok;
		 const wchar_t * btn_test_net_set;
		 const wchar_t * btn_upload_head;
		 const wchar_t * btn_userinfo_setting;
		 const wchar_t * btn_video_filedir_open;
		 const wchar_t * btn_video_play;
		 const wchar_t * cap_login_head;
		 const wchar_t * cap_login_main;
		 const wchar_t * cbx_account;
		 const wchar_t * ck_local_meet;
		 const wchar_t * ck_video_meet;
		 const wchar_t * ck_voice_meet;
		 const wchar_t * col1;
		 const wchar_t * col2;
		 const wchar_t * col3;
		 const wchar_t * col4;
		 const wchar_t * col5;
		 const wchar_t * col6;
		 const wchar_t * dlg_userinfo;
		 const wchar_t * dtp_meet_end;
		 const wchar_t * dtp_meet_end_time;
		 const wchar_t * dtp_meet_start;
		 const wchar_t * dtp_meet_start_time;
		 const wchar_t * edit_dept;
		 const wchar_t * edit_email;
		 const wchar_t * edit_meet_content;
		 const wchar_t * edit_meet_end;
		 const wchar_t * edit_meet_end_time;
		 const wchar_t * edit_meet_name;
		 const wchar_t * edit_meet_start;
		 const wchar_t * edit_meet_start_time;
		 const wchar_t * edit_name;
		 const wchar_t * edit_tel;
		 const wchar_t * img_avatar;
		 const wchar_t * img_down_icon;
		 const wchar_t * img_emp_head;
		 const wchar_t * img_head_view;
		 const wchar_t * img_meet_icon;
		 const wchar_t * img_preview_icon;
		 const wchar_t * img_staff_del;
		 const wchar_t * img_wj_icon;
		 const wchar_t * imgbtn_operate_menu;
		 const wchar_t * list_mtstatus;
		 const wchar_t * lk_meet_notice_more;
		 const wchar_t * lk_meet_video_more;
		 const wchar_t * main_left_dlg;
		 const wchar_t * main_right_dlg;
		 const wchar_t * mclist_call;
		 const wchar_t * mclist_file;
		 const wchar_t * net_cfg_addr_edt;
		 const wchar_t * net_cfg_field_edt;
		 const wchar_t * net_cfg_port_edt;
		 const wchar_t * net_cfg_pswd_edt;
		 const wchar_t * net_cfg_type_cmb;
		 const wchar_t * net_cfg_user_edt;
		 const wchar_t * serv_cfg_addr_edt;
		 const wchar_t * serv_cfg_port_edt;
		 const wchar_t * set_form;
		 const wchar_t * tab_main;
		 const wchar_t * tab_main_erp;
		 const wchar_t * tab_main_file;
		 const wchar_t * tab_right_video;
		 const wchar_t * tc_erp_info;
		 const wchar_t * turn3d;
		 const wchar_t * tv_group_inviter;
		 const wchar_t * tv_meet_notice;
		 const wchar_t * tv_meet_video_file;
		 const wchar_t * tv_meetlist;
		 const wchar_t * txt_dept;
		 const wchar_t * txt_fileext;
		 const wchar_t * txt_filename;
		 const wchar_t * txt_meet_notice_title;
		 const wchar_t * txt_meet_rest_time;
		 const wchar_t * txt_meet_video_date;
		 const wchar_t * txt_meet_video_name;
		 const wchar_t * txt_meetendtime;
		 const wchar_t * txt_meetstarttime;
		 const wchar_t * txt_meetstatus;
		 const wchar_t * txt_meettitle;
		 const wchar_t * txt_name;
		 const wchar_t * txt_staff;
		 const wchar_t * txt_staff_name;
		 const wchar_t * txt_status;
		 const wchar_t * txt_title;
		 const wchar_t * txt_uploader;
		 const wchar_t * txt_uploadtime;
		 const wchar_t * txt_user_dept;
		 const wchar_t * txt_user_pos;
		 const wchar_t * txt_username;
		 const wchar_t * win_login;
		 const wchar_t * wnd_drawboard;
		}name;

		class _id{
		public:
		const static int _name_start	=	65535;
		const static int btn_MeetFileStatus	=	65590;
		const static int btn_cancel	=	65617;
		const static int btn_close	=	65541;
		const static int btn_eleb	=	65571;
		const static int btn_join	=	65576;
		const static int btn_login	=	65546;
		const static int btn_max	=	65612;
		const static int btn_min	=	65542;
		const static int btn_ok	=	65616;
		const static int btn_rec	=	65570;
		const static int btn_reg	=	65547;
		const static int btn_send_video	=	65632;
		const static int btn_setting	=	65543;
		const static int btn_setting_cancel	=	65556;
		const static int btn_setting_ok	=	65557;
		const static int btn_test_net_set	=	136;
		const static int btn_upload_head	=	65618;
		const static int btn_userinfo_setting	=	65560;
		const static int btn_video_filedir_open	=	65589;
		const static int btn_video_play	=	65588;
		const static int cap_login_head	=	65540;
		const static int cap_login_main	=	65539;
		const static int cbx_account	=	65545;
		const static int ck_local_meet	=	65626;
		const static int ck_video_meet	=	65624;
		const static int ck_voice_meet	=	65625;
		const static int col1	=	65593;
		const static int col2	=	65595;
		const static int col3	=	65597;
		const static int col4	=	65604;
		const static int col5	=	65606;
		const static int col6	=	65608;
		const static int dlg_userinfo	=	65610;
		const static int dtp_meet_end	=	65635;
		const static int dtp_meet_end_time	=	65621;
		const static int dtp_meet_start	=	65634;
		const static int dtp_meet_start_time	=	65620;
		const static int edit_dept	=	65633;
		const static int edit_email	=	65615;
		const static int edit_meet_content	=	65638;
		const static int edit_meet_end	=	65637;
		const static int edit_meet_end_time	=	65623;
		const static int edit_meet_name	=	65619;
		const static int edit_meet_start	=	65636;
		const static int edit_meet_start_time	=	65622;
		const static int edit_name	=	65613;
		const static int edit_tel	=	65614;
		const static int img_avatar	=	65544;
		const static int img_down_icon	=	65607;
		const static int img_emp_head	=	65631;
		const static int img_head_view	=	65559;
		const static int img_meet_icon	=	65574;
		const static int img_preview_icon	=	65609;
		const static int img_staff_del	=	65630;
		const static int img_wj_icon	=	65600;
		const static int imgbtn_operate_menu	=	65564;
		const static int list_mtstatus	=	65563;
		const static int lk_meet_notice_more	=	65580;
		const static int lk_meet_video_more	=	65581;
		const static int main_left_dlg	=	65558;
		const static int main_right_dlg	=	65568;
		const static int mclist_call	=	65592;
		const static int mclist_file	=	65599;
		const static int net_cfg_addr_edt	=	137;
		const static int net_cfg_field_edt	=	65553;
		const static int net_cfg_port_edt	=	65552;
		const static int net_cfg_pswd_edt	=	65551;
		const static int net_cfg_type_cmb	=	65549;
		const static int net_cfg_user_edt	=	65550;
		const static int serv_cfg_addr_edt	=	65554;
		const static int serv_cfg_port_edt	=	65555;
		const static int set_form	=	65548;
		const static int tab_main	=	65537;
		const static int tab_main_erp	=	65561;
		const static int tab_main_file	=	65591;
		const static int tab_right_video	=	65569;
		const static int tc_erp_info	=	65562;
		const static int turn3d	=	65538;
		const static int tv_group_inviter	=	65628;
		const static int tv_meet_notice	=	65582;
		const static int tv_meet_video_file	=	65585;
		const static int tv_meetlist	=	65573;
		const static int txt_dept	=	65598;
		const static int txt_fileext	=	65603;
		const static int txt_filename	=	65601;
		const static int txt_meet_notice_title	=	65583;
		const static int txt_meet_rest_time	=	65584;
		const static int txt_meet_video_date	=	65587;
		const static int txt_meet_video_name	=	65586;
		const static int txt_meetendtime	=	65578;
		const static int txt_meetstarttime	=	65577;
		const static int txt_meetstatus	=	65579;
		const static int txt_meettitle	=	65575;
		const static int txt_name	=	65594;
		const static int txt_staff	=	65627;
		const static int txt_staff_name	=	65629;
		const static int txt_status	=	65596;
		const static int txt_title	=	65611;
		const static int txt_uploader	=	65602;
		const static int txt_uploadtime	=	65605;
		const static int txt_user_dept	=	65566;
		const static int txt_user_pos	=	65567;
		const static int txt_username	=	65565;
		const static int win_login	=	65536;
		const static int wnd_drawboard	=	65572;
		}id;

		class _string{
		public:
		const static int title	=	0;
		const static int ver	=	1;
		}string;

		class _color{
		public:
		}color;

	};

#ifdef R_IN_CPP
	 extern const _R R;
	 extern const _UIRES UIRES;
#else
	 extern const __declspec(selectany) _R & R = _R();
	 extern const __declspec(selectany) _UIRES & UIRES = _UIRES();
#endif//R_IN_CPP
}
