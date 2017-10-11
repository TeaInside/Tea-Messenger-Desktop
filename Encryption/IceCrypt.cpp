
/**
 * @author Ammar Faizi <ammarfaizi2@gmail.com>
 * @license MIT
 */
#include "../lib/base64/base64.h"
#include "../lib/base64/base64.cpp"
#include <ctime>
#include <cstring>

static inline std::string strrev(std::string str) {
   	int p= str.length();
   	std::string result = "";
 	for(int i=p-1; i>=0; i--){
 		result += str[i];
 	}
 	return result;
}

std::string encrypt(const char *a, const char *b) {
	std::string str(a);
	std::string key(b);
	std::string salt = "abcde";
	key = salt + key;
	std::string result = "";
	int i = 0;
	int j = 0;
	int s = key.length();
	int q = str.length();
	for(; j < q; j++)
	{
		char strtr = str[j];
		char keytr = key[i++];
		result += ((int)strtr ^ (int)keytr ^ 1);
		if (i == s){
			i = 0;
		}
	}
	result += salt;
	unsigned char *t = (unsigned char *) result.c_str();
	return strrev(base64_encode(t, result.length()));
}


std::string decrypt(const char *a, const char *b) {
	std::string str(a);
	std::string key(b);
	str = base64_decode(strrev(str));
	key = str.substr(str.length()-5) + key;
	str = str.substr(0, str.length() - 5);
	std::string result = "";
	int i = 0;
	int j = 0;
	int s = key.length();
	int q = str.length();
	for (; j < q; j++)
	{
		char strtr = str[j];
		char keytr = key[i++];
		int tc = ((int)strtr ^ (int)keytr ^ 1);
		result += tc;
		if (i == s){
			i = 0;
		}
	}
	return result;
}