//==============================================================================
//
// Title:		main
// Purpose:		A short description of the command-line tool.
//
// Created on:	16/02/2022 at 13:34:48 by Hewlett-Packard Company.
// Copyright:	Hewlett-Packard Company. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

// NI
#include <ansi_c.h>

// UIR

// TLGB
#include <TLGB_curl.h>

//==============================================================================
// Constants

//==============================================================================
// Types

struct string
{
	char *ptr;
	size_t len;
};

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

/// HIFN Document your function here.
/// HIFN You may use multiple lines for documentation.
/// HIPAR s/Document parameter here.
static void init_string(struct string *s)
{
	s->len = 0;
	s->ptr = malloc(s->len+1);
	if (s->ptr == NULL)
	{
		fprintf(stderr, "malloc() failed\n");
		exit(EXIT_FAILURE);
	}
	s->ptr[0] = '\0';
}

/// HIFN Document your function here.
/// HIFN You may use multiple lines for documentation.
/// HIRET Document return value here.
/// HIRET You may use multiple lines for documentation.
/// HIPAR ptr/Document parameter here.
/// HIPAR size/Document parameter here.
/// HIPAR nmemb/Document parameter here.
/// HIPAR s/Document parameter here.
static size_t writefunc(void *ptr, size_t size, size_t nmemb, struct string *s)
{
	size_t new_len = s->len + size*nmemb;
	s->ptr = realloc(s->ptr, new_len+1);
	if (s->ptr == NULL)
	{
		fprintf(stderr, "realloc() failed\n");
		exit(EXIT_FAILURE);
	}
	memcpy(s->ptr+s->len, ptr, size*nmemb);
	s->ptr[new_len] = '\0';
	s->len = new_len;

	return size*nmemb;
}

//==============================================================================
// Global variables

//==============================================================================
// Global functions

/// HIFN  The main entry-point function.
/// HIPAR argc/The number of command-line arguments.
/// HIPAR argc/This number includes the name of the command-line tool.
/// HIPAR argv/An array of command-line arguments.
/// HIPAR argv/Element 0 contains the name of the command-line tool.
/// HIRET Returns 0 if successful.
int main(int argc, char *argv[])
{
	CURL *curl = {0};
	CURLcode res = {0};
	
	init_curl();
	
	TLGB_curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = TLGB_curl_easy_init();
	if(curl)
	{
		struct curl_slist *headers = NULL;
		struct string s;
		init_string(&s);
		
		TLGB_curl_easy_setopt(curl, CURLOPT_URL, "https://www.baidu.com");//http://quan.suning.com/getSysTime.do
		//TLGB_curl_easy_setopt(curl, CURLOPT_TIMEOUT_MS, 10000L);
		TLGB_curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L); // if redirected, tell libcurl to follow redirection
		//TLGB_curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, "https");
		//TLGB_curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		TLGB_curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); // disabilita verifica SSL
		TLGB_curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L); // disabilita verifica SSL
		TLGB_curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);//return callbck
		//TLGB_curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
		
		res = TLGB_curl_easy_perform(curl); // Perform the request, res will get the return code
		if (res != CURLE_OK)
		{
			fprintf(stderr, "curl_easy_perform() failed: %s\n", TLGB_curl_easy_strerror(res));
			
		}
		else
		{
			printf("%s\n", s.ptr);
		}
		
		free(s.ptr);
		TLGB_curl_easy_cleanup(curl); // Clean up after yourself
	}
	
	TLGB_curl_global_cleanup();
	release_curl();
	return (int)res;
}
