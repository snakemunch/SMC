
#ifndef CL_SHARED_PTR_H
#define CL_SHARED_PTR_H

#include <CL/Config>
#include <CL/Internal/SharedPtrImpl>

namespace CL {

	template <typename T, typename TRep = SharedPtrImpl<T> >
	class SharedPtr {
		
	public:

		SharedPtr() : _rep(new TRep()) {
		}

		SharedPtr(T *ptr) : _rep(new TRep(ptr)) {
		}

		SharedPtr(const SharedPtr &other) : _rep(other._rep->retain()) {
		};
		
		~SharedPtr() {
			_rep->release();
		}

		T * get() const {
			return _rep->get();
		}
		
		T * operator->() const {
			return _rep->get();
		}
		
		T & operator*() const {
			return *_rep->get();
		}
		
		operator bool() const {
			return _rep->get() != 0;
		}
		
		bool operator!() const {
			return _rep->get() == 0;
		}

	private:
		TRep *_rep;
	};

}

using CL::SharedPtr;

#endif // CL_SHARED_PTR_H
