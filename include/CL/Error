#ifndef CL_ERROR_H
#define CL_ERROR_H

#include <CL/Localization>
#include <string>
	
namespace CL {

	enum ErrorCode {
		kErrorFail = 0x80000000,
		kErrorInvalidParameters,
		kErrorOutOfMemory,
		kErrorNotFound,
	};
	
	class Error {

	public:

		Error();
		
		void init(int code, const char *message) {
			if (this != NULL) {
				_errorCode = code;
				_errorMessage = message;
			}
		}
		
		void init(int code, const std::string &message) {
			if (this != NULL) {
				_errorCode = code;
				_errorMessage = message;
			}
		}
		
		void init(int code) {
			if (this != NULL) {
				_errorCode = code;
				_errorMessage = CLLocalizedString(code);
			}
		}
		
		int errorCode() const {
			return _errorCode;
		}
		
		const std::string& errorMessage() const {
			return _errorMessage;
		}
		
	private:
		int _errorCode;
		std::string _errorMessage;
	};

}

using CL::Error;

#endif // CL_ERROR_H