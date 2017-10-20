
/**
 * @author Ammar Faizi <ammarfaizi2@gmail.com>
 * @license MIT
 */

#include <sys/time.h>
#include "lib/base64/base64.h"

namespace IceCrypt {

static inline std::string strrev(std::string str);
static inline std::string str_replace(const std::string search, const std::string replace, std::string subject);

static inline std::string strrev(std::string str) {
   	int p = str.length();
   	int i = p-1;
   	std::string result = "";
 	for(; i>=0; i--){
 		result += str[i];
 	}
 	return result;
}

static inline std::string str_replace(const std::string search, const std::string replace, std::string subject)
{
    std::string buffer;
    int sealeng = search.length();
    int strleng = subject.length();
    if (sealeng==0)
    {
        return subject;
    } 	
 	int i=0;
 	int j=0;
    for(; i<strleng; j=0)
    {
        while (i+j<strleng && j<sealeng && subject[i+j]==search[j])
        {
            j++;
        }
        if (j==sealeng)
        {
            buffer.append(replace);
            i+=sealeng;
        } else {
            buffer.append(&subject[i++],1);
        }
    }
    subject = buffer;
    return subject;
}

class Auth {
public:
    static std::string encrypt( const char* data, const char* authKey );
    static std::string decrypt( const char* data, const char* authKey );
};

};
