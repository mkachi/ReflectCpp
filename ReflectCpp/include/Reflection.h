#pragma once
#pragma warning(disable: 4251)

#include "Type.h"
#include "TypeRegister.h"
#include "Field.h"
#include "Method.h"
#include <type_traits>

#define typeof(_TYPE_) __internal::__typeof<_TYPE_>::getType()

#define RF_CLASS \
public: \
	Type getType() { return Type::getType(_typeId); } \
private: \
template <typename T, typename IF> \
friend struct __internal::__typeof; \
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
		static int __createMetadata(); \
	}; \
} \
int _TYPE_::_typeId = __internal::Metadata<_TYPE_>::__createMetadata(); \
int __internal::Metadata<_TYPE_>::__createMetadata() { \
			return TypeRegister().create(typeid(_TYPE_).name())

#define RF_METADATA_END .getId(); }

#define RF_FIELD(_ACCESS_, _FIELD_) .field(_ACCESS_, #_FIELD_, &T::##_FIELD_, false)
#define RF_STATIC_FIELD(_ACCESS_, _FIELD_) .field(_ACCESS_, #_FIELD_, &T::##_FIELD_, true)
#define RF_METHOD(_ACCESS_, _METHOD_) .method(_ACCESS_, #_METHOD_, &T::##_METHOD_, false, false)
#define RF_STATIC_METHOD(_ACCESS_, _METHOD_) .method(_ACCESS_, #_METHOD_, &T::##_METHOD_, true, false)
#define RF_VIRTUAL_METHOD(_ACCESS_, _METHOD_) .method(_ACCESS_, #_METHOD_, &T::##_METHOD_, false, true)

namespace __internal
{
	template <typename T>
	using IsPremitive = std::enable_if_t<std::is_fundamental_v<T>>;
	template <typename T>
	using IsEnum = std::enable_if_t<std::is_enum_v<T>>;
	template <typename T>
	using IsClass = std::enable_if_t<std::is_class_v<T>>;

	template <typename T>
	struct Metadata;

	// Error Type
	template <typename T, typename IF = void>
	struct __typeof
	{
		static Type getType()
		{
			return Type::none;
		}
	};

	template <typename T>
	struct __typeof <T, IsPremitive<T>>
	{
		static Type getType()
		{
			return Type(typeid(T).name(), true, false);
		}
	};

	template <typename T>
	struct __typeof<T, IsEnum<T>>
	{
		static Type getType()
		{
			return Type(typeid(T).name(), false, true);
		}
	};

	template <typename T>
	struct __typeof<T, IsClass<T>>
	{
		static Type getType()
		{
			int typeId = T::_typeId;
			return Type::getType(typeId);
		}
	};
}