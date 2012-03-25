/*
 *  SharedPtrImpl.h
 *  ChipLife
 *
 *  Created by WenBi on 11-7-23.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CL_INTERNAL_SHARED_PTR_IMPL_H
#define CL_INTERNAL_SHARED_PTR_IMPL_H

#include <assert.h>

namespace CL {
	
	template <typename T>
	class SharedPtrImpl {
		
	public:
		
		explicit SharedPtrImpl(T *ptr = 0) : _pn(1), _px(ptr) {
		#ifndef NDEBUG
			_deletionHasBegun = false;
		#endif
		}
		
		SharedPtrImpl * retain() {
			++_pn;
			return this;
		}
		
		void release() {
			assert(!_deletionHasBegun);
			assert(_pn > 0);
			
			if (_pn > 1) {
				--_pn;
			}
			else {
			#ifndef NDEBUG
				_deletionHasBegun = true;
			#endif
				delete _px;
				delete this;
			}
		}
		
		T * get() const {
			return _px;
		}
			
	private:
		int  _pn;
		T   *_px;
	#ifndef NDEBUG
		bool _deletionHasBegun;
	#endif
			
	};
	
}

#endif // CL_INTERNAL_SHARED_PTR_IMPL_H