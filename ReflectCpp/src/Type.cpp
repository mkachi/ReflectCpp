#include "Type.h"
#include <unordered_map>

static std::unordered_map<string, Type> _typeInfos;

Type::Type()
	: _identifier("") { }

Type::Type(const string& identifier)
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

RF_API Type __internal::getType(const string& type)
{
	if (_typeInfos.find(type) == _typeInfos.end())
	{
		_typeInfos.emplace(std::make_pair(type, Type(type)));
	}
	return _typeInfos[type];
}