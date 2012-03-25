/*
 *  Charset.h
 *  ChipLife
 *
 *  Created by WenBi on 11-7-9.
 *  Copyright 2011 ChipLife. All rights reserved.
 *
 */

#ifndef CL_CHARSET_H
#define CL_CHARSET_H

#include <string>
#include <CL/Config>
#include <CL/Noncopyable>

namespace CL {

	class Charset;
	typedef SharedPtr<Charset> CharsetPtr;

	class Charset : private Noncopyable {
		
	public:
		
		static CharsetPtr forName(const char *charsetName);
		
		virtual bool decode(std::wstring &result, const std::string &bytes, int offset, int length) = 0;
		virtual bool encode(std::string &result, const std::wstring &string, int offset, int length) = 0;
		
	};
		
}

using CL::Charset;
using CL::CharsetPtr;

#endif // CL_CHARSET_H