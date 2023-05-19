#include <curl/curl.h>    

int main(int argc, char* argv[]) {
	CURL* curl = 0;
	CURLcode res;
	curl = curl_easy_init();
	if (curl != 0) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://www.fkcoder.com/ip?ip=123.117.118.37");

		//www.baidu.com 可能会跳转，所以设置为跟随跳转
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		//发出请求
		res = curl_easy_perform(curl);
		if (res != CURLE_OK) {
			//输出可能是乱码，因为没配置UTF-8
			fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
		}

		//清理工作
		curl_easy_cleanup(curl);
	}

	return 0;
}