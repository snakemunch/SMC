
#include <CL/URLDecoder>

namespace soko {
	
	struct URLDecoderRep {
		
		static int indexOfHexChar(URLDecoder *decoder, char ch) {
			switch (ch) {
				case '0': return 0;
				case '1': return 1;
				case '2': return 2;
				case '3': return 3;
				case '4': return 4;
				case '5': return 5;
				case '6': return 6;
				case '7': return 7;
				case '8': return 8;
				case '9': return 9;
				case 'A': return 10;
				case 'B': return 11;
				case 'C': return 12;
				case 'D': return 13;
				case 'E': return 14;
				case 'F': return 15;
			}
			return 0;
		}
		
	};
}

using namespace soko;

URLDecoder::URLDecoder() {
}

URLDecoder & URLDecoder::operator>>(const std::wstring &string) {

	for (int i = 0; i < string.length(); ++i) {
		std::wstring::value_type c = string[i];
		if (c != '%') {
			_bytes.append(1, c);
		}
		else {
			//char b = (_hex2IndexMap[string[++i]] << 4);
			//b |= _hex2IndexMap[string[++i]];
			char b = URLDecoderRep::indexOfHexChar(this, string[++i]) << 4;
			c |= URLDecoderRep::indexOfHexChar(this, string[++i]);
			_bytes.append(1, b);
		}
	}
	
	return *this;
}

