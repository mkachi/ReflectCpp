#pragma once

#include "Exporter.h"
#include "Type.h"
#include <string>
#include <string_view>

enum class MemberType
{
	None,
	Constructor,
	Destructor,
	Method,
	Field,
};

class Type;
class RF_API Member
{
protected:
	MemberType	_memberType;
	AccessType	_accessType;
	Type*		_owner;
	std::string	_name;
	bool		_static;
	bool		_virtual;

public:
	Member() = delete;
	Member(Type* owner, MemberType memberType, AccessType accessType, const std::string_view& name, bool isStatic, bool isVirtual);
	virtual ~Member();

	bool operator==(const Member& other);
	bool operator!=(const Member& other);

	MemberType getMemberType() { return _memberType; }
	AccessType getAccessType() { return _accessType; }

	std::string getName() { return _name; }
	bool isStatic() { return _static; }
	bool isVirtual() { return _virtual; }

};