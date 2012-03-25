/*
 *  Localization
 *  ChipLife
 *
 *  Created by WenBi on 11-8-22.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CL_LOCALIZATION_H
#define CL_LOCALIZATION_H

#include <string>

namespace CL {
	
	class Localization {
		
		static Localization& instance() {
			static Localization loc;
			return loc;
		}
				
	};
		
}

using CL::Localization;

extern std::string CLLocalizedString(int code);

#endif // CL_LOCALIZATION_H