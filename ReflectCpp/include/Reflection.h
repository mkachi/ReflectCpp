#pragma once

#include "Type.h"
#include "TypeRegister.h"
#include "Field.h"
#include "Method.h"

#define typeof(_TYPE_) __internal::__typeof<_TYPE_>()

#define RF_CLASS \
public: \
	Type getType() { return Type::getType(_typeId); } \
private: \
template <typename T> \
friend inline Type __internal::__typeof(); \
template <typename T> \
friend struct __internal::Metadata; \
	static int _typeId

#define RF_METADATA_BEGIN(_TYPE_) \
namespace __internal \
{ \
	template <> \
	struct Metadata<_TYPE_> \
	{ \
		using T = _TYPE_; \
		static int __createMetadata() \
		{ \
			return TypeRegister().create(typeid(_TYPE_).name())

#define RF_METADATA_END .getId(); } }; }

#define RF_FIELD(_ACCESS_, _FIELD_) .field(_ACCESS_, #_FIELD_, &T::##_FIELD_, false)
#define RF_STATIC_FIELD(_ACCESS_, _FIELD_) .field(_ACCESS_, #_FIELD_, &T::##_FIELD_, true)
#define RF_METHOD(_ACCESS_, _METHOD_) .method(_ACCESS_, #_METHOD_, &T::##_METHOD_, false, false)
#define RF_STATIC_METHOD(_ACCESS_, _METHOD_) .method(_ACCESS_, #_METHOD_, &T::##_METHOD_, true, false)
#define RF_VIRTUAL_METHOD(_ACCESS_, _METHOD_) .method(_ACCESS_, #_METHOD_, &T::##_METHOD_, false, true)

namespace __internal
{
	template <typename T>
	struct Metadata;

	template <typename T>
	inline Type __typeof()
	{
		int typeId = T::_typeId;
		return Type::getType(typeId);
	}
}