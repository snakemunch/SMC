/*
 *  StringUtil.h
 *  ChipLife
 *
 *  Created by WenBi on 11-8-5.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CL_STRING_UTIL_H
#define CL_STRING_UTIL_H

#include <CL/Config>
#include <string>

namespace CL {

	class StringUtil {
		
	public:
		
		template <class T>
		static void toLowerCase(std::basic_string<T> &string) {
			for (size_t i = 0; i < string.length(); ++i) {
				int ch = string[i];
				if (ch >= 'A' && ch <= 'Z') {
					string[i] = ch + 32;
				}
			}
		}
		
		static void UTF8Encode(std::string &result, const std::wstring &string, int offset, int length);
		static void UTF8Decode(std::wstring &result, const std::string &bytes, int offset, int length);
		
	};
	
}

using CL::StringUtil;

#endif // CL_STRING_UTIL_H
