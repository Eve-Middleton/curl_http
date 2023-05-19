#include <cvirte.h>
#include <userint.h>
#include "curl.h"

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

static int panelHandle;

CURL *curl = {0};
CURLcode res = {0};
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "curl.uir", PANEL)) < 0)
		return -1;
	DisplayPanel (panelHandle);
	init_curl();

	TLGB_curl_global_init(CURL_GLOBAL_DEFAULT);
	curl = TLGB_curl_easy_init();
	RunUserInterface ();
	TLGB_curl_global_cleanup();
	release_curl();


	DiscardPanel (panelHandle);
	return 0;
}

int CVICALLBACK btnExit (int panel, int event, void *callbackData,
						 int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_GOT_FOCUS:

			break;
		case EVENT_LOST_FOCUS:

			break;
		case EVENT_CLOSE:
			QuitUserInterface(0);
			break;
	}
	return 0;
}
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
	SetCtrlVal(panelHandle,PANEL_TEXTBOX,s->ptr);
	s->len = new_len;

	return size*nmemb;
}
int CVICALLBACK sendHttp (int panel, int control, int event,
						  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			if(curl)
			{
				struct curl_slist *headers = NULL;
				struct string s;
				init_string(&s);
				char url[100]="";
				GetCtrlVal(panel,PANEL_STRING,url);
				if (strcmp(url, "") == 0) 
				{
					MessagePopup("提示","地址为空");
					break;
				}
				TLGB_curl_easy_setopt(curl, CURLOPT_URL, url);//http://quan.suning.com/getSysTime.do
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
					//fprintf(stderr, "curl_easy_perform() failed: %s\n", TLGB_curl_easy_strerror(res));
					//SetCtrlVal(panelHandle,PANEL_TEXTBOX,s->ptr);
				}
				else
				{
					//printf("%s\n", s.ptr);
				}

				free(s.ptr);
				TLGB_curl_easy_cleanup(curl); // Clean up after yourself
			}


			break;
	}
	return 0;
}
