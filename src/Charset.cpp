/*
 *  Charset.cpp
 *  ChipLife
 *
 *  Created by WenBi on 11-7-2.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <CL/Charset>
#include <CL/StringUtil>
#include "UTF8Charset.h"

CharsetPtr Charset::forName(const char *charsetName) {
	
	Charset *charset = 0;
	
	std::string name(charsetName);
	StringUtil::toLowerCase(name);
	
	if (name.compare("utf-8") == 0) {
		charset = new UTF8Charset();
	}
	
	return CharsetPtr(charset);
	
}
