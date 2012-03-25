/*
 *  Value.cpp
 *  ChipLife
 *
 *  Created by WenBi on 11-8-20.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <CL/Value>

Value::Value(ValueType type) : _type(type) {
	switch (type) {
		case kNullValue:
			break;
		case kIntegerValue:
		case kUnsignedIntegerValue:
		case kLongValue:
		case kUnsignedLongValue:
			_holder.i = 0;
			break;
		case kRealValue:
			_holder.real = 0.0;
			break;
		case kAnsiStringValue:
		case kUnicodeStringValue:
			_holder.psz = 0;
			break;
		case kBooleanValue:
			_holder.b = false;
			break;
		default:
			break;
	}
}

Value::Value(int i) : _type(kIntegerValue) {
	_holder.i = i;
}

Value::Value(unsigned int ui) : _type(kUnsignedIntegerValue) {
	_holder.ui = ui;
}

Value::Value(int64_t l) : _type(kLongValue) {
	_holder.l = l;
}

Value::Value(uint64_t ul) : _type(kUnsignedLongValue) {
	_holder.ul = ul;
}

Value::Value(const char *ansiString) : _type(kAnsiStringValue) {
}
