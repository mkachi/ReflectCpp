#include "Field.h"

Field::Field(const Type& owner, AccessType accessType, const std::string& name, const std::any& field, bool isStatic)
	: Member(owner, MemberType::Method, accessType, name, isStatic)
	, _field(field) {}
Field::~Field() {}