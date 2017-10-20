
/**
 * @author Ammar Faizi <ammarfaizi2@gmail.com>
 * @license MIT
 */

#include "Auth.h"

namespace IceCrypt {

/**
 * @param const char *a  Data.
 * @param const	char *b	 Key.
 */
std::string Auth::encrypt(const char* data, const char* authKey) {
    std::string str(data);
    std::string key(authKey);
    std::string salt = "";
    struct timeval time;
    gettimeofday(&time, NULL);
    long microsec1 = ((unsigned long long)time.tv_sec * 1000000) + time.tv_usec;
    salt += microsec1;

    gettimeofday(&time, NULL);
    long microsec2 = ((unsigned long long)time.tv_sec * 1000000) + time.tv_usec;
    salt += microsec2;

    gettimeofday(&time, NULL);
    long microsec3 = ((unsigned long long)time.tv_sec * 1000000) + time.tv_usec;
    salt += microsec3;

    gettimeofday(&time, NULL);
    long microsec4 = ((unsigned long long)time.tv_sec * 1000000) + time.tv_usec;
    salt += microsec4;

    gettimeofday(&time, NULL);
    long microsec5 = ((unsigned long long)time.tv_sec * 1000000) + time.tv_usec;
    salt += microsec5;

    key = salt + key;
    std::string result = "";
    int i = 0;
    int j = 0;
    int s = key.length();
    int k = s - 1;
    int q = str.length();
    for(; j < q; j++) {
        char strtr = str[j];
        char keytr = key[i++];
        char key2tr = key[k--];
        result += ((int)strtr ^ (int)keytr ^ 0x00f ^ (int)key2tr ^ (j % (i+k)) ^ 0x01a);
        if (i == s) i = 0;
        if (k == 0) k = s - 1;
    };

    result += salt;
    unsigned char *t = (unsigned char *) result.c_str();
    return str_replace("=", "", strrev(base64_encode(t, result.length())));
};

/**
 * @param const char *a	 Encrypted data.
 * @param const char *b	 Key.
 * @return std::string
 */
std::string Auth::decrypt(const char* dataa, const char* authKey) {
    std::string str(dataa);
    std::string key(authKey);
    str = base64_decode(strrev(str));
    key = str.substr(str.length()-5) + key;
    str = str.substr(0, str.length() - 5);
    std::string result = "";
    int i = 0;
    int j = 0;
    int s = key.length();
    int k = s - 1;
    int q = str.length();
    for (; j < q; j++) {
        char strtr = str[j];
        char keytr = key[i++];
        char key2tr = key[k--];
        int tc = ((int)strtr ^ (int)keytr ^ 0x00f ^ (int)key2tr ^ (j % (i+k)) ^ 0x01a);
        result += tc;
        if (i == s) i = 0;
        if (k == 0) k = s - 1;
    }
    return result;
};

}; // NS IceCrypt
