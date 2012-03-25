/*
 *  StringUtil.cpp
 *  ChipLife
 *
 *  Created by WenBi on 11-8-5.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <CL/StringUtil>
#include <CL/Charset>

void StringUtil::UTF8Encode(std::string &result, const std::wstring &string, int offset, int length) {
	CharsetPtr charset = Charset::forName("UTF-8");
	charset->encode(result, string, offset, length);
}

void StringUtil::UTF8Decode(std::wstring &result, const std::string &bytes, int offset, int length) {
	CharsetPtr charset = Charset::forName("UTF-8");
	charset->decode(result, bytes, offset, length);
}