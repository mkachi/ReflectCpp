#pragma once

#include <string>
#include <vector>
#include <any>
#include "Exporter.h"

typedef wchar_t				wchar;
typedef unsigned char		byte;
typedef signed char			sbyte;
typedef unsigned short		ushort;
typedef unsigned int		uint;
typedef unsigned long		ulong;
typedef long long			int64;
typedef unsigned long long	uint64;
typedef std::string			string;
typedef std::wstring		wstring;
typedef std::any			any;

#define typeof(_TYPE_) __internal::getType<_TYPE_>()

class RF_API Type final
{
	template <typename T>
	friend Type __internal::getType<T>();
private:
	string	_identifier;

	Type(const string& identifier);

public:
	Type() = delete;
	Type(const Type& other);
	~Type();

	bool operator==(const Type& other);
	bool operator!=(const Type& other);

	string getName() { return _identifier; }

};

namespace __internal
{
	template <typename T>
	inline Type getType()
	{
		return getType(typeid(T).name())
	}
	Type getType(const string& type);
}