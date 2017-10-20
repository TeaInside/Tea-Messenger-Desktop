
#include "src/icecrypt/Auth.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	const char* input 		= "Hello world";
	const char* key   		= "mytea123";

	string encrypted = IceCrypt::Auth::encrypt(input, key);
	cout << "Encrypted Data : " << encrypted << endl;


	// Comment out Flag B and uncomment this declaration to get the real test.
	// const char* encrypted_data = encrypted.c_str();


	// Flag B (Provided encrypted data).
	const char* encrypted_data= "A0P7czLTo3aTGZpsM1E6Yp"; // Hello world


	string decrypted = IceCrypt::Auth::decrypt(encrypted_data, key);
	cout << "Decrypted Data : " << decrypted << endl;
	return 0;
}
