/*
 *  RefPtr.h
 *  AlipayPortal
 *
 *  Created by WenBi on 11-6-29.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CL_REFPTR_H
#define CL_REFPTR_H

namespace CL {

	template<typename T>
	class RefPtr
	{
	
	public:
		
		RefPtr() : _pointer(0) {
		}
		
		RefPtr(T *ptr) : _pointer(ptr) {
			if (ptr) {
				ptr->retain();
			}
		}
		
		RefPtr(const RefPtr &other) : _pointer(other._pointer) {
			if (_pointer) {
				_pointer->retain();
			}
		}
		
		template <typename U>
		RefPtr(const RefPtr<U> &other) : _pointer(other._pointer) {
			if (T *ptr = _pointer) {
				ptr->retain();
			}
		}
		
		~RefPtr() {
			if (T *ptr = _pointer) {
				ptr->release();
			}
		}
		
		void clear() {
			if (T *ptr = _pointer) {
				ptr->release();
			}
			_pointer = 0;
		}
		
		T & operator*() const {
			return *_pointer;
		}
		
		T * operator->() const {
			return _pointer;
		}
		
		T * get() const {
			return _pointer;
		}
		
		typedef T* RefPtr::*UnspecifiedBoolType;
		operator UnspecifiedBoolType() const { 
			return _pointer ? &RefPtr::_pointer : 0;
		}
		
		RefPtr & operator=(const RefPtr &other) {
			T *ptr = other._pointer;
			if (ptr) {
				ptr->retain();
			}
			ptr = _pointer;
			_pointer = other._pointer;
			if (ptr) {
				ptr->release();
			}
			return *this;
		}
		
		template <typename U>
		RefPtr & operator=(const RefPtr<U> &other) {
			T *ptr = other._pointer;
			if (ptr) {
				ptr->retain();
			}
			ptr = _pointer;
			_pointer = other._pointer;
			if (ptr) {
				ptr->release();
			}
			return *this;
		}
		
		RefPtr & operator=(T *aPtr) {
			if (aPtr) {
				aPtr->retain();
			}
			T *ptr = _pointer;
			_pointer = aPtr;
			if (ptr) {
				ptr->release();
			}
			return *this;
		}
		
	private:
		
		T *_pointer;
		
	};
	
}

template <typename T, typename U>
inline bool operator==(const soko::RefPtr<T> &a, const soko::RefPtr<U> &b) {
	return a.get() == b.get();
}

template <typename T, typename U>
inline bool operator==(const soko::RefPtr<T> &a, U *b) {
	return a.get() == b;
}

template <typename T, typename U>
inline bool operator==(T *a, const soko::RefPtr<U> &b) {
	return a == b.get();
}

template <typename T, typename U>
inline bool operator!=(const soko::RefPtr<T> &a, const soko::RefPtr<U> &b) {
	return a.get() != b.get();
}

template <typename T, typename U>
inline bool operator!=(const soko::RefPtr<T> &a, U *b) {
	return a.get() != b;
}

template <typename T, typename U>
inline bool operator!=(T *a, const soko::RefPtr<U> &b) {
	return a != b.get();
}

using CL::RefPtr;

#endif // CL_REFPTR_H
