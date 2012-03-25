/*
 *  SHA1MessageDigest.h
 *  ChipLife
 *
 *  Created by WenBi on 11-6-14.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SOKO_SECURITY_SHA1_MESSAGE_DIGEST_H
#define SOKO_SECURITY_SHA1_MESSAGE_DIGEST_H

#include <CL/Security/MessageDigest>
#include "../3dparty/SHA1.h"

class SHA1MessageDigest : public MessageDigest
{
	
public:
	
	SHA1MessageDigest() {
		SHA1Init(&mContext);
	}
	
	virtual void update(const unsigned char *input, int offset, int length) {
		SHA1Update(&mContext, (unsigned char *)input + offset, length);
	}
	
	virtual void digest(std::vector<unsigned char> &result) {
		result.resize(20);
		SHA1Final(&result[0], &mContext);
	}
	
private:
	SHA1_CTX mContext;
	
};


#endif // SOKO_SECURITY_SHA1_MESSAGE_DIGEST_H