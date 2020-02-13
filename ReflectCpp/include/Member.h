#pragma once

#include <any>
#include <string>

#include "Exporter.h"

enum class MemberType
{
	Constructor,
	Destructor,
	Method,
	Field,
};

enum class AccessType
{
	Public,
	Protected,
	Private
};

class RF_API Member
{
protected:
	MemberType	_memberType;
	AccessType	_accessType;
	std::string _identifier;
	std::string	_name;
	bool		_static;

public:
	Member() = delete;
	Member(MemberType memberType, AccessType accessType, const std::string& name, bool isStatic);
	virtual ~Member();

	bool operator==(const Member& other);
	bool operator!=(const Member& other);

	MemberType getMemberType() { return _memberType; }
	AccessType getAccessType() { return _accessType; }

	std::string getName() { return _name; }
	bool isStatic() { return _static; }
	
};