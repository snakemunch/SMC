/*
 *  UTF8Charset.h
 *  ChipLife
 *
 *  Created by WenBi on 11-7-2.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <CL/Charset>

class UTF8Charset : public Charset {

	virtual bool decode(std::wstring &result, const std::string &bytes, int offset, int length);
	virtual bool encode(std::string &result, const std::wstring &string, int offset, int length);
	
};
