#include "Method.h"

Method::Method(const Type& owner, AccessType accessType, const std::string& name, const std::any& method, bool isStatic)
	: Member(owner, MemberType::Method, accessType, name, isStatic)
	, _method(method) {}
Method::~Method() {}