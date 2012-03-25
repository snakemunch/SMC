
#include <CL/Security/MessageDigest>
#include <string>
#include "MD5MessageDigest.h"
#include "SHA1MessageDigest.h"

MessageDigest::MessageDigest() {
}

MessageDigest * MessageDigest::obtain(const char *algorithm) {
	
	typedef std::char_traits<char> char_traits;
	
	MessageDigest *instance = NULL;
	if (char_traits::compare(algorithm, "MD5", 3) == 0) {
		instance = new MD5MessageDigest();
	}
	else if (char_traits::compare(algorithm, "SHA1", 4) == 0) {
		instance = new SHA1MessageDigest();
	}
	return instance;
}