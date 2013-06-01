/**
 *
 * @file Pointer.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 */

#pragma once

namespace tools {

template <class T>
class Pointer {
public:
	Pointer<T>()
	: ptr(0)
	, autoDelete(true)
	{ }

	Pointer<T>(const T& copyObj)
	: ptr(new T(copyObj))
	, autoDelete(true)
	{ }

	Pointer<T>(T* ptr)
	: ptr(ptr)
	, autoDelete(true)
	{ }

public:
	virtual ~Pointer() {
		Destruct();
	}

	virtual operator const T*() const {
        return ptr;
    }

	virtual operator T*() {
        return ptr;
    }

	void Set(T* ptr, bool autoDelete) {
		Destruct();

		this->ptr = ptr;
		this->autoDelete = autoDelete;
	}

	T* Get() {
		return ptr;
	}

	void Swap(T* swap) {
		swap->autoDelete = false;
		Set(swap,true);
	}

	bool IsNull() const {
		return ptr == 0;
	}

	void Release() {
		if(ptr)
			delete ptr;
		autoDelete = true;
		ptr = 0;
	}

private:
	void Destruct() {
		if(autoDelete)
			Release();
	}

protected:
	T* ptr;
	bool autoDelete;
};

template <class T>
class AutoPointer : public Pointer<T> {

public:
	AutoPointer<T>()
	: Pointer<T>()
	{ }

	AutoPointer<T>(const T& copyObj)
	: Pointer<T>(new T(copyObj))
	{ }

	AutoPointer<T>(T* ptr)
	: Pointer<T>(ptr)
	{ }

	virtual ~AutoPointer()
	{}

	virtual operator T&() {
    	if(!Pointer<T>::ptr)
    		Set(new T(), true);
        return *(Pointer<T>::ptr);
    }
};

}
