#include "Type.h"
#include "Member.h"
#include "Field.h"
#include "Method.h"

Type::Type() 
	: _fullName("none")
	, _name("none")
	, _premitive(false)
	, _class(false)
	, _enum(false) {}
Type::Type(const Type& other)
	: _fullName(other._fullName)
	, _name(other._name)
	, _premitive(other._premitive)
	, _class(other._class)
	, _enum(other._enum)
	, _fields(other._fields)
	, _methods(other._methods) {}
Type::~Type()
{
	for (int i = 0; i < _fields.size(); ++i)
	{
		if (_fields[i] != nullptr)
		{
			delete _fields[i];
			_fields[i] = nullptr;
		}
		_fields.clear();

		if (_methods[i] != nullptr)
		{
			delete _methods[i];
			_methods[i] = nullptr;
		}
		_methods.clear();
	}
}

bool Type::operator==(const Type& other)
{
	return (
		_fullName == other._fullName &&
		_premitive == other._premitive &&
		_class == other._class &&
		_enum == other._enum &&
		_fields.size() == other._fields.size() &&
		_methods.size() == other._methods.size());
}
bool Type::operator!=(const Type& other)
{
	return (
		_fullName != other._fullName ||
		_premitive != other._premitive ||
		_class != other._class ||
		_enum != other._enum ||
		_fields.size() != other._fields.size() ||
		_methods.size() != other._methods.size());
}

std::vector<Member*> Type::getMembers(AccessType access)
{
	std::vector<Member*> result;
	if (access == AccessType::None)
	{
		result.reserve(_fields.size() + _methods.size());
		result.insert(result.end(), _fields.begin(), _fields.end());
		result.insert(result.end(), _methods.begin(), _methods.end());
		return result;
	}

	for (int i = 0; i < _fields.size(); ++i)
	{
		if (_fields[i]->getAccessType() == access)
		{
			result.push_back(_fields[i]);
		}
	}

	for (int i = 0; i < _methods.size(); ++i)
	{
		if (_methods[i]->getAccessType() == access)
		{
			result.push_back(_methods[i]);
		}
	}
	return result;
}
std::vector<Field*> Type::getFields(AccessType access)
{
	if (access == AccessType::None)
	{
		return _fields;
	}

	std::vector<Field*> result;
	for (int i = 0; i < _fields.size(); ++i)
	{
		if (_fields[i]->getAccessType() == access)
		{
			result.push_back(_fields[i]);
		}
	}
	return result;
}
std::vector<Method*> Type::getMethods(AccessType access)
{
	if (access == AccessType::None)
	{
		return _methods;
	}

	std::vector<Method*> result;
	for (int i = 0; i < _methods.size(); ++i)
	{
		if (_methods[i]->getAccessType() == access)
		{
			result.push_back(_methods[i]);
		}
	}
	return result;
}

Member* Type::getMember(const std::string_view& name)
{
	for (int i = 0; i < _methods.size(); ++i)
	{
		if (_methods[i]->getName() == name)
		{
			return _methods[i];
		}
	}

	for (int i = 0; i < _fields.size(); ++i)
	{
		if (_fields[i]->getName() == name)
		{
			return _fields[i];
		}
	}
	return nullptr;
}
Field* Type::getField(const std::string_view& name)
{
	for (int i = 0; i < _fields.size(); ++i)
	{
		if (_fields[i]->getName() == name)
		{
			return _fields[i];
		}
	}
	return nullptr;
}
Method* Type::getMethod(const std::string_view& name)
{
	for (int i = 0; i < _methods.size(); ++i)
	{
		if (_methods[i]->getName() == name)
		{
			return _methods[i];
		}
	}
	return nullptr;
}

const Type Type::none = Type();