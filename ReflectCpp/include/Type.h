#pragma once

#include <string>
#include <vector>
#include <any>
#include "Exporter.h"

#define typeof(_TYPE_) __internal::getType<_TYPE_>()

class Type;
namespace __internal
{
	template <typename T>
	inline Type getType()
	{
		return getType(typeid(T).name());
	}
	RF_API Type getType(const std::string& type);
}

class RF_API Type final
{
	friend Type __internal::getType(const std::string&);
private:
	std::string	_identifier;

	Type(const std::string& identifier);

public:
	Type();
	Type(const Type& other);
	~Type();

	bool operator==(const Type& other);
	bool operator!=(const Type& other);

	std::string getName() { return _identifier; }

	static Type none;

};

Type Type::none = Type();