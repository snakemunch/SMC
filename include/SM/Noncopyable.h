/*
 *  Noncopyable.h
 *  ChipLife
 *
 *  Created by WenBi on 11-7-8.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CL_NONCOPYABLE_H
#define CL_NONCOPYABLE_H

namespace CL {
	
	class Noncopyable {
		
	protected:
		
		Noncopyable() {}
		~Noncopyable() {}
		
	private:
		
		Noncopyable(const Noncopyable &) {}
		const Noncopyable & operator=(const Noncopyable &) { return *this; }
		
	};
	
}

using CL::Noncopyable;

#endif // CL_NONCOPYABLE_H