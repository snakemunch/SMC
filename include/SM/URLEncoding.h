//
//  URLEncoding.h
//  ChipLife
//
//  Created by WenBi on 11-8-5.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//
#ifndef CL_URLENCODING_H
#define CL_URLENCODING_H

#include <CL/SharedPtr>

namespace CL {
	
	class URLEncoding;
	
	typedef SharedPtr<URLEncoding> URLEncodingPtr;
	
	class URLEncoding {
		
	public:
		
		static URLEncodingPtr obtain();
		
		virtual bool encode(const unichar *string, std::string &result);
		virtual bool decode(const char *bytes, std::wstring &result);
	};

}

using CL::URLEncoding;
using CL::URLEncodingPtr;

#endif // CL_URLENCODING_H
