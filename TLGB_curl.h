//==============================================================================
//
// Title:		TLGB_curl.h
// Purpose:		A short description of the interface.
//
// Copyright:	Hewlett-Packard Company. All Rights Reserved.
//
//==============================================================================

#ifndef __TLGB_curl_H__
#define __TLGB_curl_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

// NI
#include "cvidef.h"
#include "winsock.h"
		
// UIR
		
// TLGB
#include "curl/curl.h"
#include "curl/curlver.h"
#include "curl/easy.h"
#include "curl/mprintf.h"
#include "curl/multi.h"
#include "curl/options.h"
#include "curl/stdcheaders.h"
#include "curl/system.h"
//#include "curl/typecheck-gcc.h"
#include "curl/urlapi.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// External variables

extern curl_easy_cleanup TLGB_curl_easy_cleanup;
extern curl_easy_duphandle TLGB_curl_easy_duphandle;
extern curl_easy_escape TLGB_curl_easy_escape;
extern curl_easy_getinfo TLGB_curl_easy_getinfo;
extern curl_easy_init TLGB_curl_easy_init;
extern curl_easy_option_by_id TLGB_curl_easy_option_by_id;
extern curl_easy_option_by_name TLGB_curl_easy_option_by_name;
extern curl_easy_option_next TLGB_curl_easy_option_next;
extern curl_easy_pause TLGB_curl_easy_pause;
extern curl_easy_perform TLGB_curl_easy_perform;
extern curl_easy_recv TLGB_curl_easy_recv;
extern curl_easy_reset TLGB_curl_easy_reset;
extern curl_easy_send TLGB_curl_easy_send;
extern curl_easy_setopt TLGB_curl_easy_setopt;
extern curl_easy_strerror TLGB_curl_easy_strerror;
extern curl_easy_unescape TLGB_curl_easy_unescape;
extern curl_easy_upkeep TLGB_curl_easy_upkeep;
extern curl_escape TLGB_curl_escape;
extern curl_formadd TLGB_curl_formadd;
extern curl_formfree TLGB_curl_formfree;
extern curl_formget TLGB_curl_formget;
extern curl_free TLGB_curl_free;
extern curl_getdate TLGB_curl_getdate;
extern curl_getenv TLGB_curl_getenv;
extern curl_global_cleanup TLGB_curl_global_cleanup;
extern curl_global_init TLGB_curl_global_init;
extern curl_global_init_mem TLGB_curl_global_init_mem;
extern curl_global_sslset TLGB_curl_global_sslset;
extern curl_maprintf TLGB_curl_maprintf;
extern curl_mfprintf TLGB_curl_mfprintf;
extern curl_mime_addpart TLGB_curl_mime_addpart;
extern curl_mime_data TLGB_curl_mime_data;
extern curl_mime_data_cb TLGB_curl_mime_data_cb;
extern curl_mime_encoder TLGB_curl_mime_encoder;
extern curl_mime_filedata TLGB_curl_mime_filedata;
extern curl_mime_filename TLGB_curl_mime_filename;
extern curl_mime_free TLGB_curl_mime_free;
extern curl_mime_headers TLGB_curl_mime_headers;
extern curl_mime_init TLGB_curl_mime_init;
extern curl_mime_name TLGB_curl_mime_name;
extern curl_mime_subparts TLGB_curl_mime_subparts;
extern curl_mime_type TLGB_curl_mime_type;
extern curl_mprintf TLGB_curl_mprintf;
extern curl_msnprintf TLGB_curl_msnprintf;
extern curl_msprintf TLGB_curl_msprintf;
extern curl_multi_add_handle TLGB_curl_multi_add_handle;
extern curl_multi_assign TLGB_curl_multi_assign;
extern curl_multi_cleanup TLGB_curl_multi_cleanup;
extern curl_multi_fdset TLGB_curl_multi_fdset;
extern curl_multi_info_read TLGB_curl_multi_info_read;
extern curl_multi_init TLGB_curl_multi_init;
extern curl_multi_perform TLGB_curl_multi_perform;
extern curl_multi_poll TLGB_curl_multi_poll;
extern curl_multi_remove_handle TLGB_curl_multi_remove_handle;
extern curl_multi_setopt TLGB_curl_multi_setopt;
extern curl_multi_socket TLGB_curl_multi_socket;
extern curl_multi_socket_action TLGB_curl_multi_socket_action;
extern curl_multi_socket_all TLGB_curl_multi_socket_all;
extern curl_multi_strerror TLGB_curl_multi_strerror;
extern curl_multi_timeout TLGB_curl_multi_timeout;
extern curl_multi_wait TLGB_curl_multi_wait;
extern curl_multi_wakeup TLGB_curl_multi_wakeup;
extern curl_mvaprintf TLGB_curl_mvaprintf;
extern curl_mvfprintf TLGB_curl_mvfprintf;
extern curl_mvprintf TLGB_curl_mvprintf;
extern curl_mvsnprintf TLGB_curl_mvsnprintf;
extern curl_mvsprintf TLGB_curl_mvsprintf;
extern curl_pushheader_byname TLGB_curl_pushheader_byname;
extern curl_pushheader_bynum TLGB_curl_pushheader_bynum;
extern curl_share_cleanup TLGB_curl_share_cleanup;
extern curl_share_init TLGB_curl_share_init;
extern curl_share_setopt TLGB_curl_share_setopt;
extern curl_share_strerror TLGB_curl_share_strerror;
extern curl_slist_append TLGB_curl_slist_append;
extern curl_slist_free_all TLGB_curl_slist_free_all;
extern curl_strequal TLGB_curl_strequal;
extern curl_strnequal TLGB_curl_strnequal;
extern curl_unescape TLGB_curl_unescape;
extern curl_url TLGB_curl_url;
extern curl_url_cleanup TLGB_curl_url_cleanup;
extern curl_url_dup TLGB_curl_url_dup;
extern curl_url_get TLGB_curl_url_get;
extern curl_url_set TLGB_curl_url_set;
extern curl_url_strerror TLGB_curl_url_strerror;
extern curl_version TLGB_curl_version;
extern curl_version_info TLGB_curl_version_info;

//==============================================================================
// Global functions
		
void init_curl(void);
void release_curl(void);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __TLGB_curl_H__ */
