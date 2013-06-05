/**
 *
 * @file Pointer.h
 * @author Moritz Wagner
 * @date Mar 4, 2013
 *
 */

#pragma once

namespace tools {

/**
 * @brief template class for generic pointers including null pointers
 * @see please consider using tools::AutoPointer as references.
 *      when using untyped memory please also consider using MemoryContainer
 */
template <class T>
class Pointer {
public:
	/**
	 * constructs a typed null pointer
	 */
	Pointer<T>()
	: ptr(0)
	, autoDelete(true)
	{ }

	/**
	 * constructs a typed object by copying copyObj
	 * @param copyObj object to be copied
	 */
	Pointer<T>(const T& copyObj)
	: ptr(new T(copyObj))
	, autoDelete(true)
	{ }

	/**
	 * constructs a typed object from a already allocated pointer
	 * @param ptr pointer to be managed by this class
	 */
	Pointer<T>(T* ptr)
	: ptr(ptr)
	, autoDelete(true)
	{ }

public:
	virtual ~Pointer() {
		Destruct();
	}

	/**
	 * cast this instance to a constant typed pointer
	 */
	virtual operator const T*() const {
        return ptr;
    }

	/**
	 * cast this instance to a non constant pointer
	 */
	virtual operator T*() {
        return ptr;
    }

	/**
	 * set this pointer to a new value, deleting all already contained
	 * instances
	 * @param ptr new instance
	 * @param autoDelete true if the instance is bound to this instance
	 */
	void Set(T* ptr, bool autoDelete) {
		Destruct();

		this->ptr = ptr;
		this->autoDelete = autoDelete;
	}

	/**
	 * gets content of this pointer, consider using
	 * cast operators for performance reasons
	 * @return this instances pointer
	 */
	T* Get() {
		return ptr;
	}

	/**
	 * takes over ownership of a pointer from another instance
	 * @param swap instance to be owned
	 */
	void Swap(T* swap) {
		swap->autoDelete = false;
		Set(swap,true);
	}

	/**
	 * checks if pointer is null
	 * @return true if pointer is null
	 */
	bool IsNull() const {
		return ptr == 0;
	}

	/**
	 * releases all allocated instances of this pointer
	 */
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

/**
 * @brief wrapper class for pointer that cannot be null
 * @see please see tools:Pointer for more reference
 */
template <class T>
class AutoPointer : public Pointer<T> {

public:
	/**
	 * constructs an empty AutoPointer
	 */
	AutoPointer<T>()
	: Pointer<T>(0)
	{ }

	/**
	 * construct an instance copying another object
	 * @param copyObj object to be copyied
	 */
	AutoPointer<T>(const T& copyObj)
	: Pointer<T>(copyObj)
	{ }

	/**
	 * constructs a typed object from a already allocated pointer
	 * @param ptr pointer to be managed by this class
	 */
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
