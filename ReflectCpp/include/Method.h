#pragma once

#define _METHOD_H_
#include "Member.h"
#include <functional>
#include <any>

class RF_API Method final
	: public Member
{
private:
	std::any _method;

public:
	Method() = delete;
	Method(const Type& owner, AccessType accessType, const std::string& name, const std::any& method, bool isStatic);
	virtual ~Method();

	template <typename Result, typename Instance, typename ...Args>
	Result invoke(Instance* instance, Args... args);

};
#include "Method.inl"