#include "Member.h"

Member::Member(Type* owner, MemberType memberType, AccessType accessType, const std::string_view& name, bool isStatic, bool isVirtual)
	: _memberType(memberType)
	, _accessType(accessType)
	, _name(name)
	, _owner(owner)
	, _static(isStatic)
	, _virtual(isVirtual){}
Member::~Member() {}

bool Member::operator==(const Member& other)
{
	return (
		_memberType == other._memberType &&
		_accessType == other._accessType &&
		_owner == other._owner &&
		_static == other._static);
}

bool Member::operator!=(const Member& other)
{
	return (
		_memberType != other._memberType ||
		_accessType != other._accessType ||
		_owner != other._owner ||
		_static != other._static);
}