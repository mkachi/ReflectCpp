#pragma once

#include "Exporter.h"
#include <vector>
#include <string>

enum class AccessType
{
	None,
	Public,
	Protected,
	Private
};

class Member;
class Field;
class Method;
class RF_API Type final
{
	template <typename T>
	using vector = std::vector<T>;
	friend class TypeRegister;
private:
	std::string		_fullName;
	std::string		_name;
	bool			_premitive;
	bool			_class;
	bool			_enum;
	vector<Field*>	_fields;
	vector<Method*> _methods;

	static int registerType(Type* type);

public:
	Type();
	Type(const Type& other);
	~Type();

	bool operator==(const Type& other);
	bool operator!=(const Type& other);

	std::string getFullName() { return _fullName; }
	std::string getName() { return _name; }

	bool isPremitive() { return _premitive; }
	bool isClass() { return _class; }
	bool isEnum() { return _enum; }

	std::vector<Member*> getMembers(AccessType access = AccessType::None);
	std::vector<Field*>	 getFields(AccessType access = AccessType::None);
	std::vector<Method*> getMethods(AccessType access = AccessType::None);

	Member* getMember(const std::string_view& name);
	Field*	getField(const std::string_view& name);
	Method* getMethod(const std::string_view& name);

	static Type getType(int typeId);
	static const Type none;

};