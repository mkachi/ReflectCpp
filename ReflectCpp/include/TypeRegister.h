#pragma once

#include "Exporter.h"
#include "Type.h"
#include <any>

class RF_API TypeRegister final
{
private:
	Type* _type;

public:
	TypeRegister();
	~TypeRegister();

	TypeRegister create(const char* typeName);
	TypeRegister field(AccessType accessType, const std::string_view& name, const std::any& field, bool isStatic);
	TypeRegister method(AccessType accessType, const std::string_view& name, const std::any& method, bool isStatic, bool isVirtual);
	int getId();

};