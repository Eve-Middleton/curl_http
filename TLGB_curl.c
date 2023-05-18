//==============================================================================
//
// Title:		TLGB_curl.c
// Purpose:		A short description of the implementation.
//
// Copyright:	Hewlett-Packard Company. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

// NI
#include <windows.h> 
#include <userint.h>

// UIR

// TLGB
#include "TLGB_curl.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

static HINSTANCE hinstLib = {0};

//==============================================================================
// Static functions

//==============================================================================
// Global variables

curl_easy_cleanup TLGB_curl_easy_cleanup = {0};
curl_easy_duphandle TLGB_curl_easy_duphandle = {0};
curl_easy_escape TLGB_curl_easy_escape = {0};
curl_easy_getinfo TLGB_curl_easy_getinfo = {0};
curl_easy_init TLGB_curl_easy_init = {0};
curl_easy_option_by_id TLGB_curl_easy_option_by_id = {0};
curl_easy_option_by_name TLGB_curl_easy_option_by_name = {0};
curl_easy_option_next TLGB_curl_easy_option_next = {0};
curl_easy_pause TLGB_curl_easy_pause = {0};
curl_easy_perform TLGB_curl_easy_perform = {0};
curl_easy_recv TLGB_curl_easy_recv = {0};
curl_easy_reset TLGB_curl_easy_reset = {0};
curl_easy_send TLGB_curl_easy_send = {0};
curl_easy_setopt TLGB_curl_easy_setopt = {0};
curl_easy_strerror TLGB_curl_easy_strerror = {0};
curl_easy_unescape TLGB_curl_easy_unescape = {0};
curl_easy_upkeep TLGB_curl_easy_upkeep = {0};
curl_escape TLGB_curl_escape = {0};
curl_formadd TLGB_curl_formadd = {0};
curl_formfree TLGB_curl_formfree = {0};
curl_formget TLGB_curl_formget = {0};
curl_free TLGB_curl_free = {0};
curl_getdate TLGB_curl_getdate = {0};
curl_getenv TLGB_curl_getenv = {0};
curl_global_cleanup TLGB_curl_global_cleanup = {0};
curl_global_init TLGB_curl_global_init = {0};
curl_global_init_mem TLGB_curl_global_init_mem = {0};
curl_global_sslset TLGB_curl_global_sslset = {0};
curl_maprintf TLGB_curl_maprintf = {0};
curl_mfprintf TLGB_curl_mfprintf = {0};
curl_mime_addpart TLGB_curl_mime_addpart = {0};
curl_mime_data TLGB_curl_mime_data = {0};
curl_mime_data_cb TLGB_curl_mime_data_cb = {0};
curl_mime_encoder TLGB_curl_mime_encoder = {0};
curl_mime_filedata TLGB_curl_mime_filedata = {0};
curl_mime_filename TLGB_curl_mime_filename = {0};
curl_mime_free TLGB_curl_mime_free = {0};
curl_mime_headers TLGB_curl_mime_headers = {0};
curl_mime_init TLGB_curl_mime_init = {0};
curl_mime_name TLGB_curl_mime_name = {0};
curl_mime_subparts TLGB_curl_mime_subparts = {0};
curl_mime_type TLGB_curl_mime_type = {0};
curl_mprintf TLGB_curl_mprintf = {0};
curl_msnprintf TLGB_curl_msnprintf = {0};
curl_msprintf TLGB_curl_msprintf = {0};
curl_multi_add_handle TLGB_curl_multi_add_handle = {0};
curl_multi_assign TLGB_curl_multi_assign = {0};
curl_multi_cleanup TLGB_curl_multi_cleanup = {0};
curl_multi_fdset TLGB_curl_multi_fdset = {0};
curl_multi_info_read TLGB_curl_multi_info_read = {0};
curl_multi_init TLGB_curl_multi_init = {0};
curl_multi_perform TLGB_curl_multi_perform = {0};
curl_multi_poll TLGB_curl_multi_poll = {0};
curl_multi_remove_handle TLGB_curl_multi_remove_handle = {0};
curl_multi_setopt TLGB_curl_multi_setopt = {0};
curl_multi_socket TLGB_curl_multi_socket = {0};
curl_multi_socket_action TLGB_curl_multi_socket_action = {0};
curl_multi_socket_all TLGB_curl_multi_socket_all = {0};
curl_multi_strerror TLGB_curl_multi_strerror = {0};
curl_multi_timeout TLGB_curl_multi_timeout = {0};
curl_multi_wait TLGB_curl_multi_wait = {0};
curl_multi_wakeup TLGB_curl_multi_wakeup = {0};
curl_mvaprintf TLGB_curl_mvaprintf = {0};
curl_mvfprintf TLGB_curl_mvfprintf = {0};
curl_mvprintf TLGB_curl_mvprintf = {0};
curl_mvsnprintf TLGB_curl_mvsnprintf = {0};
curl_mvsprintf TLGB_curl_mvsprintf = {0};
curl_pushheader_byname TLGB_curl_pushheader_byname = {0};
curl_pushheader_bynum TLGB_curl_pushheader_bynum = {0};
curl_share_cleanup TLGB_curl_share_cleanup = {0};
curl_share_init TLGB_curl_share_init = {0};
curl_share_setopt TLGB_curl_share_setopt = {0};
curl_share_strerror TLGB_curl_share_strerror = {0};
curl_slist_append TLGB_curl_slist_append = {0};
curl_slist_free_all TLGB_curl_slist_free_all = {0};
curl_strequal TLGB_curl_strequal = {0};
curl_strnequal TLGB_curl_strnequal = {0};
curl_unescape TLGB_curl_unescape = {0};
curl_url TLGB_curl_url = {0};
curl_url_cleanup TLGB_curl_url_cleanup = {0};
curl_url_dup TLGB_curl_url_dup = {0};
curl_url_get TLGB_curl_url_get = {0};
curl_url_set TLGB_curl_url_set = {0};
curl_url_strerror TLGB_curl_url_strerror = {0};
curl_version TLGB_curl_version = {0};
curl_version_info TLGB_curl_version_info = {0};

//==============================================================================
// Global functions

/// HIFN Document your function here.
/// HIFN You may use multiple lines for documentation.
void init_curl(void)
{
	// Get a handle to the DLL module.
	hinstLib = LoadLibrary("libcurl.dll");
	
	// If the handle is invalid, give error and exit
	if(hinstLib == NULL)
	{
		MessagePopup(__FUNCTION__, "Error LoadLibrary()");
		return;
	}

	// If the handle is valid, try to get the function address.
	TLGB_curl_easy_cleanup = (curl_easy_cleanup) GetProcAddress(hinstLib, "curl_easy_cleanup");
	if(TLGB_curl_easy_cleanup == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_cleanup\")");
		return;
	}
	
	TLGB_curl_easy_duphandle = (curl_easy_duphandle) GetProcAddress(hinstLib, "curl_easy_duphandle");
	if(TLGB_curl_easy_duphandle == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_duphandle\")");
		return;
	}
	
	TLGB_curl_easy_escape = (curl_easy_escape) GetProcAddress(hinstLib, "curl_easy_escape");
	if(TLGB_curl_easy_escape == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_escape\")");
		return;
	}
	
	TLGB_curl_easy_getinfo = (curl_easy_getinfo) GetProcAddress(hinstLib, "curl_easy_getinfo");
	if(TLGB_curl_easy_getinfo == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_getinfo\")");
		return;
	}
	
	TLGB_curl_easy_init = (curl_easy_init) GetProcAddress(hinstLib, "curl_easy_init");
	if(TLGB_curl_easy_init == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_init\")");
		return;
	}
	
	TLGB_curl_easy_option_by_id = (curl_easy_option_by_id) GetProcAddress(hinstLib, "curl_easy_option_by_id");
	if(TLGB_curl_easy_option_by_id == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_option_by_id\")");
		return;
	}
	
	TLGB_curl_easy_option_by_name = (curl_easy_option_by_name) GetProcAddress(hinstLib, "curl_easy_option_by_name");
	if(TLGB_curl_easy_option_by_name == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_option_by_name\")");
		return;
	}
	
	TLGB_curl_easy_option_next = (curl_easy_option_next) GetProcAddress(hinstLib, "curl_easy_option_next");
	if(TLGB_curl_easy_option_next == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_option_next\")");
		return;
	}
	
	TLGB_curl_easy_pause = (curl_easy_pause) GetProcAddress(hinstLib, "curl_easy_pause");
	if(TLGB_curl_easy_pause == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_pause\")");
		return;
	}
	
	TLGB_curl_easy_perform = (curl_easy_perform) GetProcAddress(hinstLib, "curl_easy_perform");
	if(TLGB_curl_easy_perform == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_perform\")");
		return;
	}
	
	TLGB_curl_easy_recv = (curl_easy_recv) GetProcAddress(hinstLib, "curl_easy_recv");
	if(TLGB_curl_easy_recv == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_recv\")");
		return;
	}
	
	TLGB_curl_easy_reset = (curl_easy_reset) GetProcAddress(hinstLib, "curl_easy_reset");
	if(TLGB_curl_easy_reset == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_reset\")");
		return;
	}
	
	TLGB_curl_easy_send = (curl_easy_send) GetProcAddress(hinstLib, "curl_easy_send");
	if(TLGB_curl_easy_send == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_send\")");
		return;
	}
	
	TLGB_curl_easy_setopt = (curl_easy_setopt) GetProcAddress(hinstLib, "curl_easy_setopt");
	if(TLGB_curl_easy_setopt == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_setopt\")");
		return;
	}
	
	TLGB_curl_easy_strerror = (curl_easy_strerror) GetProcAddress(hinstLib, "curl_easy_strerror");
	if(TLGB_curl_easy_strerror == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_strerror\")");
		return;
	}
	
	TLGB_curl_easy_unescape = (curl_easy_unescape) GetProcAddress(hinstLib, "curl_easy_unescape");
	if(TLGB_curl_easy_unescape == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_unescape\")");
		return;
	}
	
	TLGB_curl_easy_upkeep = (curl_easy_upkeep) GetProcAddress(hinstLib, "curl_easy_upkeep");
	if(TLGB_curl_easy_upkeep == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_easy_upkeep\")");
		return;
	}
	
	TLGB_curl_escape = (curl_escape) GetProcAddress(hinstLib, "curl_escape");
	if(TLGB_curl_escape == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_escape\")");
		return;
	}
	
	TLGB_curl_formadd = (curl_formadd) GetProcAddress(hinstLib, "curl_formadd");
	if(TLGB_curl_formadd == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_formadd\")");
		return;
	}
	
	TLGB_curl_formfree = (curl_formfree) GetProcAddress(hinstLib, "curl_formfree");
	if(TLGB_curl_formfree == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_formfree\")");
		return;
	}
	
	TLGB_curl_formget = (curl_formget) GetProcAddress(hinstLib, "curl_formget");
	if(TLGB_curl_formget == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_formget\")");
		return;
	}
	
	TLGB_curl_free = (curl_free) GetProcAddress(hinstLib, "curl_free");
	if(TLGB_curl_free == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_free\")");
		return;
	}
	
	TLGB_curl_getdate = (curl_getdate) GetProcAddress(hinstLib, "curl_getdate");
	if(TLGB_curl_getdate == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_getdate\")");
		return;
	}
	
	TLGB_curl_getenv = (curl_getenv) GetProcAddress(hinstLib, "curl_getenv");
	if(TLGB_curl_getenv == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_getenv\")");
		return;
	}
	
	TLGB_curl_global_cleanup = (curl_global_cleanup) GetProcAddress(hinstLib, "curl_global_cleanup");
	if(TLGB_curl_global_cleanup == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_global_cleanup\")");
		return;
	}
	
	TLGB_curl_global_init = (curl_global_init) GetProcAddress(hinstLib, "curl_global_init");
	if(TLGB_curl_global_init == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_global_init\")");
		return;
	}
	
	TLGB_curl_global_init_mem = (curl_global_init_mem) GetProcAddress(hinstLib, "curl_global_init_mem");
	if(TLGB_curl_global_init_mem == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_global_init_mem\")");
		return;
	}
	
	TLGB_curl_global_sslset = (curl_global_sslset) GetProcAddress(hinstLib, "curl_global_sslset");
	if(TLGB_curl_global_sslset == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_global_sslset\")");
		return;
	}
	
	TLGB_curl_maprintf = (curl_maprintf) GetProcAddress(hinstLib, "curl_maprintf");
	if(TLGB_curl_maprintf == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_maprintf\")");
		return;
	}
	
	TLGB_curl_mfprintf = (curl_mfprintf) GetProcAddress(hinstLib, "curl_mfprintf");
	if(TLGB_curl_mfprintf == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mfprintf\")");
		return;
	}
	
	TLGB_curl_mime_addpart = (curl_mime_addpart) GetProcAddress(hinstLib, "curl_mime_addpart");
	if(TLGB_curl_mime_addpart == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mime_addpart\")");
		return;
	}
	
	TLGB_curl_mime_data = (curl_mime_data) GetProcAddress(hinstLib, "curl_mime_data");
	if(TLGB_curl_mime_data == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mime_data\")");
		return;
	}
	
	TLGB_curl_mime_data_cb = (curl_mime_data_cb) GetProcAddress(hinstLib, "curl_mime_data_cb");
	if(TLGB_curl_mime_data_cb == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mime_data_cb\")");
		return;
	}
	
	TLGB_curl_mime_encoder = (curl_mime_encoder) GetProcAddress(hinstLib, "curl_mime_encoder");
	if(TLGB_curl_mime_encoder == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mime_encoder\")");
		return;
	}
	
	TLGB_curl_mime_filedata = (curl_mime_filedata) GetProcAddress(hinstLib, "curl_mime_filedata");
	if(TLGB_curl_mime_filedata == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mime_filedata\")");
		return;
	}
	
	TLGB_curl_mime_filename = (curl_mime_filename) GetProcAddress(hinstLib, "curl_mime_filename");
	if(TLGB_curl_mime_filename == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mime_filename\")");
		return;
	}
	
	TLGB_curl_mime_free = (curl_mime_free) GetProcAddress(hinstLib, "curl_mime_free");
	if(TLGB_curl_mime_free == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mime_free\")");
		return;
	}
	
	TLGB_curl_mime_headers = (curl_mime_headers) GetProcAddress(hinstLib, "curl_mime_headers");
	if(TLGB_curl_mime_headers == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mime_headers\")");
		return;
	}
	
	TLGB_curl_mime_init = (curl_mime_init) GetProcAddress(hinstLib, "curl_mime_init");
	if(TLGB_curl_mime_init == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mime_init\")");
		return;
	}
	
	TLGB_curl_mime_name = (curl_mime_name) GetProcAddress(hinstLib, "curl_mime_name");
	if(TLGB_curl_mime_name == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mime_name\")");
		return;
	}
	
	TLGB_curl_mime_subparts = (curl_mime_subparts) GetProcAddress(hinstLib, "curl_mime_subparts");
	if(TLGB_curl_mime_subparts == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mime_subparts\")");
		return;
	}
	
	TLGB_curl_mime_type = (curl_mime_type) GetProcAddress(hinstLib, "curl_mime_type");
	if(TLGB_curl_mime_type == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mime_type\")");
		return;
	}
	
	TLGB_curl_mprintf = (curl_mprintf) GetProcAddress(hinstLib, "curl_mprintf");
	if(TLGB_curl_mprintf == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mprintf\")");
		return;
	}
	
	TLGB_curl_msnprintf = (curl_msnprintf) GetProcAddress(hinstLib, "curl_msnprintf");
	if(TLGB_curl_msnprintf == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_msnprintf\")");
		return;
	}
	
	TLGB_curl_msprintf = (curl_msprintf) GetProcAddress(hinstLib, "curl_msprintf");
	if(TLGB_curl_msprintf == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_msprintf\")");
		return;
	}
	
	TLGB_curl_multi_add_handle = (curl_multi_add_handle) GetProcAddress(hinstLib, "curl_multi_add_handle");
	if(TLGB_curl_multi_add_handle == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_add_handle\")");
		return;
	}
	
	TLGB_curl_multi_assign = (curl_multi_assign) GetProcAddress(hinstLib, "curl_multi_assign");
	if(TLGB_curl_multi_assign == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_assign\")");
		return;
	}
	
	TLGB_curl_multi_cleanup = (curl_multi_cleanup) GetProcAddress(hinstLib, "curl_multi_cleanup");
	if(TLGB_curl_multi_cleanup == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_cleanup\")");
		return;
	}
	
	TLGB_curl_multi_fdset = (curl_multi_fdset) GetProcAddress(hinstLib, "curl_multi_fdset");
	if(TLGB_curl_multi_fdset == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_fdset\")");
		return;
	}
	
	TLGB_curl_multi_info_read = (curl_multi_info_read) GetProcAddress(hinstLib, "curl_multi_info_read");
	if(TLGB_curl_multi_info_read == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_info_read\")");
		return;
	}
	
	TLGB_curl_multi_init = (curl_multi_init) GetProcAddress(hinstLib, "curl_multi_init");
	if(TLGB_curl_multi_init == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_init\")");
		return;
	}
	
	TLGB_curl_multi_perform = (curl_multi_perform) GetProcAddress(hinstLib, "curl_multi_perform");
	if(TLGB_curl_multi_perform == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_perform\")");
		return;
	}
	
	TLGB_curl_multi_poll = (curl_multi_poll) GetProcAddress(hinstLib, "curl_multi_poll");
	if(TLGB_curl_multi_poll == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_poll\")");
		return;
	}
	
	TLGB_curl_multi_remove_handle = (curl_multi_remove_handle) GetProcAddress(hinstLib, "curl_multi_remove_handle");
	if(TLGB_curl_multi_remove_handle == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_remove_handle\")");
		return;
	}
	
	TLGB_curl_multi_setopt = (curl_multi_setopt) GetProcAddress(hinstLib, "curl_multi_setopt");
	if(TLGB_curl_multi_setopt == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_setopt\")");
		return;
	}
	
	TLGB_curl_multi_socket = (curl_multi_socket) GetProcAddress(hinstLib, "curl_multi_socket");
	if(TLGB_curl_multi_socket == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_socket\")");
		return;
	}
	
	TLGB_curl_multi_socket_action = (curl_multi_socket_action) GetProcAddress(hinstLib, "curl_multi_socket_action");
	if(TLGB_curl_multi_socket_action == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_socket_action\")");
		return;
	}
	
	TLGB_curl_multi_socket_all = (curl_multi_socket_all) GetProcAddress(hinstLib, "curl_multi_socket_all");
	if(TLGB_curl_multi_socket_all == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_socket_all\")");
		return;
	}
	
	TLGB_curl_multi_strerror = (curl_multi_strerror) GetProcAddress(hinstLib, "curl_multi_strerror");
	if(TLGB_curl_multi_strerror == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_strerror\")");
		return;
	}
	
	TLGB_curl_multi_timeout = (curl_multi_timeout) GetProcAddress(hinstLib, "curl_multi_timeout");
	if(TLGB_curl_multi_timeout == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_timeout\")");
		return;
	}
	
	TLGB_curl_multi_wait = (curl_multi_wait) GetProcAddress(hinstLib, "curl_multi_wait");
	if(TLGB_curl_multi_wait == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_wait\")");
		return;
	}
	
	TLGB_curl_multi_wakeup = (curl_multi_wakeup) GetProcAddress(hinstLib, "curl_multi_wakeup");
	if(TLGB_curl_multi_wakeup == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_multi_wakeup\")");
		return;
	}
	
	TLGB_curl_mvaprintf = (curl_mvaprintf) GetProcAddress(hinstLib, "curl_mvaprintf");
	if(TLGB_curl_mvaprintf == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mvaprintf\")");
		return;
	}
	
	TLGB_curl_mvfprintf = (curl_mvfprintf) GetProcAddress(hinstLib, "curl_mvfprintf");
	if(TLGB_curl_mvfprintf == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mvfprintf\")");
		return;
	}
	
	TLGB_curl_mvprintf = (curl_mvprintf) GetProcAddress(hinstLib, "curl_mvprintf");
	if(TLGB_curl_mvprintf == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mvprintf\")");
		return;
	}
	
	TLGB_curl_mvsnprintf = (curl_mvsnprintf) GetProcAddress(hinstLib, "curl_mvsnprintf");
	if(TLGB_curl_mvsnprintf == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mvsnprintf\")");
		return;
	}
	
	TLGB_curl_mvsprintf = (curl_mvsprintf) GetProcAddress(hinstLib, "curl_mvsprintf");
	if(TLGB_curl_mvsprintf == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_mvsprintf\")");
		return;
	}
	
	TLGB_curl_pushheader_byname = (curl_pushheader_byname) GetProcAddress(hinstLib, "curl_pushheader_byname");
	if(TLGB_curl_pushheader_byname == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_pushheader_byname\")");
		return;
	}
	
	TLGB_curl_pushheader_bynum = (curl_pushheader_bynum) GetProcAddress(hinstLib, "curl_pushheader_bynum");
	if(TLGB_curl_pushheader_bynum == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_pushheader_bynum\")");
		return;
	}
	
	TLGB_curl_share_cleanup = (curl_share_cleanup) GetProcAddress(hinstLib, "curl_share_cleanup");
	if(TLGB_curl_share_cleanup == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_share_cleanup\")");
		return;
	}
	
	TLGB_curl_share_init = (curl_share_init) GetProcAddress(hinstLib, "curl_share_init");
	if(TLGB_curl_share_init == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_share_init\")");
		return;
	}
	
	TLGB_curl_share_setopt = (curl_share_setopt) GetProcAddress(hinstLib, "curl_share_setopt");
	if(TLGB_curl_share_setopt == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_share_setopt\")");
		return;
	}
	
	TLGB_curl_share_strerror = (curl_share_strerror) GetProcAddress(hinstLib, "curl_share_strerror");
	if(TLGB_curl_share_strerror == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_share_strerror\")");
		return;
	}
	
	TLGB_curl_slist_append = (curl_slist_append) GetProcAddress(hinstLib, "curl_slist_append");
	if(TLGB_curl_slist_append == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_slist_append\")");
		return;
	}
	
	TLGB_curl_slist_free_all = (curl_slist_free_all) GetProcAddress(hinstLib, "curl_slist_free_all");
	if(TLGB_curl_slist_free_all == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_slist_free_all\")");
		return;
	}
	
	TLGB_curl_strequal = (curl_strequal) GetProcAddress(hinstLib, "curl_strequal");
	if(TLGB_curl_strequal == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_strequal\")");
		return;
	}
	
	TLGB_curl_strnequal = (curl_strnequal) GetProcAddress(hinstLib, "curl_strnequal");
	if(TLGB_curl_strnequal == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_strnequal\")");
		return;
	}
	
	TLGB_curl_unescape = (curl_unescape) GetProcAddress(hinstLib, "curl_unescape");
	if(TLGB_curl_unescape == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_unescape\")");
		return;
	}
	
	TLGB_curl_url = (curl_url) GetProcAddress(hinstLib, "curl_url");
	if(TLGB_curl_url == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_url\")");
		return;
	}
	
	TLGB_curl_url_cleanup = (curl_url_cleanup) GetProcAddress(hinstLib, "curl_url_cleanup");
	if(TLGB_curl_url_cleanup == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_url_cleanup\")");
		return;
	}
	
	TLGB_curl_url_dup = (curl_url_dup) GetProcAddress(hinstLib, "curl_url_dup");
	if(TLGB_curl_url_dup == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_url_dup\")");
		return;
	}
	
	TLGB_curl_url_get = (curl_url_get) GetProcAddress(hinstLib, "curl_url_get");
	if(TLGB_curl_url_get == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_url_get\")");
		return;
	}
	
	TLGB_curl_url_set = (curl_url_set) GetProcAddress(hinstLib, "curl_url_set");
	if(TLGB_curl_url_set == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_url_set\")");
		return;
	}
	
	TLGB_curl_url_strerror = (curl_url_strerror) GetProcAddress(hinstLib, "curl_url_strerror");
	if(TLGB_curl_url_strerror == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_url_strerror\")");
		return;
	}
	
	TLGB_curl_version = (curl_version) GetProcAddress(hinstLib, "curl_version");
	if(TLGB_curl_version == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_version\")");
		return;
	}
	
	TLGB_curl_version_info = (curl_version_info) GetProcAddress(hinstLib, "curl_version_info");
	if(TLGB_curl_version_info == NULL)
	{
		MessagePopup(__FUNCTION__, "Error GetProcAddress(hinstLib, \"curl_version_info\")");
		return;
	}
}

/// HIFN Document your function here.
/// HIFN You may use multiple lines for documentation.
void release_curl(void)
{
	if(hinstLib != NULL)
	{
		// Free the DLL module
		FreeLibrary(hinstLib);
		hinstLib = 0;
	}
}
