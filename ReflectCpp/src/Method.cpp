#include "Method.h"

Method::Method(Type* owner, AccessType accessType, const std::string_view& name, const std::any& method, bool isStatic, bool isVirtual)
	: Member(owner, MemberType::Method, accessType, name, isStatic, isVirtual)
	, _method(method) {}
Method::~Method() {}