#include "Test1.h"

RF_METADATA_BEGIN(Test1)
	RF_FIELD(AccessType::Private, _a)
	RF_FIELD(AccessType::Private, _b)
	RF_METHOD(AccessType::Private, getMultipleB)
	RF_METHOD(AccessType::Public, setA)
	RF_METHOD(AccessType::Public, getA)
RF_METADATA_END