#pragma once

#include "Member.h"
#include <any>

class RF_API Field final
	: public Member
{
private:
	std::any _field;

public:
	Field() = delete;
	Field(const Type& owner, AccessType accessType, const std::string& name, const std::any& field, bool isStatic);
	virtual ~Field();

	template <typename T, typename Instance>
	void setValue(Instance* instance, const T& value);
	template <typename T, typename Instance>
	T getValue(Instance* instance);

};
#include "Field.inl"