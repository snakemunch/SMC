/*
 *  MD5MessageDigest.h
 *  ChipLife
 *
 *  Created by WenBi on 11-6-14.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef SOKO_SECURITY_MD5_MESSAGE_DIGEST_H
#define SOKO_SECURITY_MD5_MESSAGE_DIGEST_H

#include <CL/Security/MessageDigest>
#include "../3dparty/MD5.h"

class MD5MessageDigest : public MessageDigest
{

public:
	
	MD5MessageDigest() {
		MD5Init(&mContext);
	}
	
	virtual void update(const unsigned char *input, int offset, int length) {
		MD5Update(&mContext, (unsigned char *)input + offset, length);
	}
	
	virtual void digest(std::vector<unsigned char> &result) {
		MD5Final(&mContext);
		result.assign(mContext.digest, mContext.digest + 16);
	}
	
private:
	MD5_CTX mContext;
	
};

#endif // SOKO_SECURITY_MD5_MESSAGE_DIGEST_H
