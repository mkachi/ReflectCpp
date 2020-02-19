#pragma once

#include "Type.h"
#include "TypeRegister.h"
#include "Field.h"
#include "Method.h"

#define typeof(_TYPE_) __internal::__typeof<_TYPE_>()

#define RF_CLASS(_TYPE_) \
public: \
Type getType() { return Type::getType(_typeId); } \
private: \
template <typename T> \
friend inline Type __internal::__typeof(); \
friend static int __##_TYPE_##_createMetadata(); \
static int _typeId

#define RF_METADATA_BEGIN(_TYPE_) \
int _TYPE_::_typeId = __##_TYPE_##_createMetadata(); \
static int __##_TYPE_##_createMetadata() { using T = _TYPE_; return TypeRegister().create(typeid(T).name())

#define RF_METADATA_END .getId(); }

#define RF_FIELD(_ACCESS_, _FIELD_) .field(_ACCESS_, #_FIELD_, &T::##_FIELD_, false)
#define RF_STATIC_FIELD(_ACCESS_, _FIELD_) .field(_ACCESS_, #_FIELD_, &T::##_FIELD_, true)

#define RF_METHOD(_ACCESS_, _METHOD_) .method(_ACCESS_, #_METHOD_, &T::##_METHOD_, false, false)
#define RF_STATIC_METHOD(_ACCESS_, _METHOD_) .method(_ACCESS_, #_METHOD_, &T::##_METHOD_, true, false)
#define RF_VIRTUAL_METHOD(_ACCESS_, _METHOD_) .method(_ACCESS_, #_METHOD_, &T::##_METHOD_, false, true)


namespace __internal
{
	template <typename T>
	inline Type __typeof()
	{
		int typeId = T::_typeId;
		return Type::getType(typeId);
	}
}