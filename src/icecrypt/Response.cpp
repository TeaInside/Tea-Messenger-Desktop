#include "Response.h"
#include <iostream>
#include <string>
#include <curl/curl.h>

namespace IceCrypt {

bool Response::send( std::string data ) {
    return 0;
};

std::string Response::get( ) {
    cURL = curl_easy_init();
    if( cURL ) {
        curl_easy_setopt(cURL, CURLOPT_URL, TEA_CHAT_API);
	curl_easy_setopt(cURL, CURLOPT_WRITEFUNCTION, WriteCallback);
	result = curl_easy_perform(cURL);
	curl_easy_cleanup(cURL);

	std::cout << readBuffer << std::endl;

	return "true";
    } else {
        return "false";
    }
};

};
