#include "TypeRegister.h"
#include "Field.h"
#include "Method.h"

TypeRegister::TypeRegister()
	: _type(nullptr) {}
TypeRegister::~TypeRegister() {}

TypeRegister TypeRegister::create(const char* typeName)
{
	std::string type = typeName;
	constexpr const char* CLASS_TOKEN = "class ";

	if (type.find(CLASS_TOKEN) != std::string::npos)
	{
		_type = new Type();
		_type->_fullName = type.substr(type.find(CLASS_TOKEN) + strlen(CLASS_TOKEN));

		size_t index = type.find_last_of("::");
		if (index != std::string::npos)
		{
			_type->_name = type.substr(type.find_last_of("::") + 1);
		}
		else
		{
			_type->_name = _type->_fullName;
		}
		_type->_class = true;
	}
	return *this;
}

TypeRegister TypeRegister::field(AccessType accessType, const std::string_view& name, const std::any& field, bool isStatic)
{
	if (_type != nullptr)
	{
		_type->_fields.push_back(new Field(_type, accessType, name, field, isStatic));
	}
	return *this;
}

TypeRegister TypeRegister::method(AccessType accessType, const std::string_view& name, const std::any& method, bool isStatic, bool isVirtual)
{
	if (_type != nullptr)
	{
		_type->_methods.push_back(new Method(_type, accessType, name, method, isStatic, isVirtual));
	}
	return *this;
}

int TypeRegister::getId()
{
	if (_type != nullptr)
	{
		return Type::registerType(_type);
	}
	return -1;
}
