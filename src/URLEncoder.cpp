
#include <CL/URLEncoder>

URLEncoder::URLEncoder() {
}

URLEncoder & URLEncoder::operator>>(const std::string &bytes) {

	const char HEX_CHARS[] = "0123456789ABCDEF";

	for (int i = 0; i < bytes.length(); ++i) {
		char c = bytes[i];
		if ((c >= 'a' && c <= 'z') || 
		    (c >= 'A' && c <= 'Z') || 
		    (c >= '0' && c <= '9')) {
			_buffer.append(1, c);
		}
		else {
			_buffer.append(1, '%');
			_buffer.append(1, HEX_CHARS[c >> 4]);
			_buffer.append(1, HEX_CHARS[c & 0x0F]);
		}
	}

	return *this;
}

