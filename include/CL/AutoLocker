/*
 *  AutoLocker.h
 *  ChipLife
 *
 *  Created by WenBi on 11-7-8.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CL_AUTO_LOCKER_H
#define CL_AUTO_LOCKER_H

#include <CL/Noncopyable>

namespace CL {
	
	template <typename Mutex>
	class AutoLocker : private Noncopyable {
		
	public:
		
		AutoLocker(Mutex &mutex) : _mutex {
			_mutex.lock();
			_locked = true;
		}
		
		~AutoLocker() {
			if (_locked) {
				_mutex.unlock();
			}
		}
		
		bool locked() const {
			return _locked;
		}
		
		void lock() {
			if (!_locked) {
				_mutex.lock();
				_locked = true;
			}
		}
		
		void unlock() {
			if (_locked) {
				_mutex.unlock();
				_locked = false;
			}
		}
		
	private:
		Mutex &_mutex;
		bool   _locked;
		
	};
	
}

using CL::AutoLocker;

#endif // CL_AUTO_LOCKER_H