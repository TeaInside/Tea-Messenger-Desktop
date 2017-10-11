

#include "Encryption/IceCrypt.cpp"
#include <iostream>

using namespace std;

int main()
{
	const char* encrypted = "==QZkNmYhZwDSsQFItQCOYAC";
	const char* key		= "ice";
	cout << "Decrypted data : " << (decrypt(encrypted, key)) << endl << endl;

	
	const char* input = "hello world";
	cout << "Encrypted data : " << (encrypt(input, key)) << endl;
}