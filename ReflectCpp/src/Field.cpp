#include "Field.h"

Field::Field(Type* owner, AccessType accessType, const std::string_view& name, const std::any& field, bool isStatic)
	: Member(owner, MemberType::Method, accessType, name, isStatic, false)
	, _field(field) {}
Field::~Field() {}