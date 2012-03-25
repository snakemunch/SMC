/*
 *  LocalizedString.h
 *  ChipLife
 *
 *  Created by WenBi on 11-8-21.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include <CL/NBError>

inline const wchar_t * WBLocalizedErrorMessage(NBErrorCode code) {
	const wchar_t *message = L"未知错误";
	if (code == kErrorOutOfMemory) {
		message = L"内存不足";
	}
	return message;
}
