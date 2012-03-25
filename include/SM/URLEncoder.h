#ifndef CL_URL_ENCODER_H
#define CL_URL_ENCODER_H

#include <string>

namespace CL {

	class URLEncoder {

	public:

		URLEncoder();

		URLEncoder & operator>>(const std::string &bytes);

		URLEncoder & operator>>(const char *bytes) {
			return this->operator>>(std::string(bytes));
		}

		const std::wstring & toString() const {
			return _buffer;
		}

	private:

		std::wstring _buffer;

	};

}

using CL::URLEncoder;

#endif CL_URL_ENCODER_H
