#pragma once

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
	Result invoke(const Instance& instance, Args... args);

};