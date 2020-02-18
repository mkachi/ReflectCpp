#include "Type.h"
#include <unordered_map>

static std::unordered_map<std::string, Type> _typeInfos;

Type::Type()
	: _identifier("none") { }

Type::Type(const std::string& identifier)
	: _identifier(identifier.substr(6)) { }

Type::Type(const Type& other)
	: _identifier(other._identifier) { }

Type::~Type() { }

bool Type::operator==(const Type& other)
{
	return _identifier == other._identifier;
}

bool Type::operator!=(const Type& other)
{
	return _identifier != other._identifier;
}

RF_API Type __internal::getType(const std::string& type)
{
	if (_typeInfos.find(type) == _typeInfos.end())
	{
		_typeInfos.emplace(std::make_pair(type, Type(type)));
	}
	return _typeInfos[type];
}

const Type Type::none = Type();