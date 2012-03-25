//
//  URLEncoding.m
//  ChipLife
//
//  Created by WenBi on 11-8-5.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <CL/URLEncoding>

URLEncodingPtr URLEncoding::obtain() {
	return URLEncodingPtr(new URLEncoding());
}

bool URLEncoding::encode(const unichar *string, std::string &result) {
	return false;
}

bool URLEncoding::decode(const char *bytes, std::wstring &result) {
	return false;
}