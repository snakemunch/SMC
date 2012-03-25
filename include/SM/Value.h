/*
 *  Value
 *  ChipLife
 *
 *  Created by WenBi on 11-8-20.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CL_VALUE_H
#define CL_VALUE_H

#include <CL/Config>

namespace CL {

	class Value {
	
		union ValueHolder {
			int i;
			unsigned int ui;
			int64_t l;
			uint64_t ul;
			double real;
			bool b;
			char *psz;
			wchar_t *pwsz;
		};
		
	public:
	
		enum ValueType {
			kNullValue,
			kIntegerValue,
			kUnsignedIntegerValue,
			kLongValue,
			kUnsignedLongValue,
			kRealValue,
			kAnsiStringValue,
			kUnicodeStringValue,
			kBooleanValue,
			kArrayValue,
			kObjectValue,
		};
		
		Value(ValueType type = kNullValue);
		Value(int i);
		Value(unsigned int ui);
		Value(int64_t l);
		Value(uint64_t ul);
		Value(const char *ansiString);
		Value(const std::string &ansiString);
		Value(const wchar_t *unicodeString);
		Value(const std::wstring &unicodeString);
		
		ValueType type() const {
			return _type;
		}
		
		
		
	private:
		
		ValueType _type;
		ValueHolder _holder;
		
	};
	
}

using CL::Value;

#endif // CL_VALUE_H