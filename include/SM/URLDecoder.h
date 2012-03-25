
#ifndef CL_URL_DECODER_H
#define CL_URL_DECODER_H

#include <string>

namespace CL {


	class URLDecoder {

		friend struct URLDecoderRep;
		
	public:

		URLDecoder();

		URLDecoder & operator>>(const std::wstring & string);

		const std::string & toBytes() const {
			return _bytes;
		}

	private:

		std::string _bytes;
		char        _hex2IndexMap[256];

	};


}

using CL::URLDecoder;

#endif //CL_URL_DECODER_H
