/*
 *  UTF8Charset.cpp
 *  ChipLife
 *
 *  Created by WenBi on 11-7-9.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#include "UTF8Charset.h"

static unsigned char UTF8_BYTES[] = { 
	1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
	1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
	2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3,
	3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4,
	4, 0, 0, 0, 0, 0, 0, 0, 0, 
};

bool UTF8Charset::decode(std::wstring &result, const std::string &bytes, int offset, int length) {
	
	result.clear();
	
	unsigned char b1, b2, b3, b4;
	
	for (int i = 0; i < length; ) {

		b1 = bytes[i++] & 0xFF;
		switch (UTF8_BYTES[b1]) {
			case 1:
				result.append(1, b1);
				break;
			case 2:
				b2 = bytes[i++];
				result.append(1, ((b1 & 0x1f) << 6) | (b2 & 0x3f));
				break;
			case 3:
				b2 = bytes[i++];
				b3 = bytes[i++];
				result.append(1, ((b1 & 0x1f) << 12) | ((b2 & 0x3f) << 6) | (b3 & 0x3f));
				break;
			case 4:
				b2 = bytes[i++];
				b3 = bytes[i++];
				b4 = bytes[i++];
				result.append(1, (((b1 & 0x1f) << 18) | ((b2 & 0x3f) << 12) | ((b3 & 0x1f) << 6) | (b4 & 0x1f) - 0x10000) / 0x400 + 0xd800);
				break;
		}

	}
	return true;
}

bool UTF8Charset::encode(std::string &result, const std::wstring &string, int offset, int length) {

	result.clear();

	for (int i = 0; i < length; ++i) {

		int c = string[offset + i];
		if (c < 0x80) {
			result.append(1, c);
		}
		else if (c < 0x800) {
			result.append(1, 0xC0 | c >> 6);
			result.append(1, 0x80 | c & 0x3F);
		}
		else if (c < 0x10000) {
			result.append(1, 0xE0 | c >> 12);
			result.append(1, 0x80 | ((c >> 6) & 0x3F));
			result.append(1, 0x80 | (c & 0x3F));
		}
		else if (c < 0x200000) {
			result.append(1, 0xF0 | c >> 18);
			result.append(1, 0x80 | c >> 12 & 0x3F);
			result.append(1, 0x80 | c >> 6 & 0x3F);
			result.append(1, 0x80 | c & 0x3F);
		}

	}

	return true;
}

static int numberFromHexChar(char ch) {
	int number = 0;
	switch (ch)
	{
	case '0': number = 0x00; break;
	case '1': number = 0x01; break;
	case '2': number = 0x02; break;
	case '3': number = 0x03; break;
	case '4': number = 0x04; break;
	case '5': number = 0x05; break;
	case '6': number = 0x06; break;
	case '7': number = 0x07; break;
	case '8': number = 0x08; break;
	case '9': number = 0x09; break;
	case 'A': number = 0x0A; break;
	case 'B': number = 0x0B; break;
	case 'C': number = 0x0C; break;
	case 'D': number = 0x0D; break;
	case 'E': number = 0x0E; break;
	case 'F': number = 0x0F; break;
	}
	return number;
}

unsigned char makeByte(char ch1, char ch2) {
	return (unsigned char)(numberFromHexChar(ch2) | numberFromHexChar(ch1));
}
