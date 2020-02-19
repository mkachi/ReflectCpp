#include "Test2.h"

RF_METADATA_BEGIN(Sample::Test2)
	RF_FIELD(AccessType::Private, _a)
	RF_FIELD(AccessType::Private, _b)
	RF_METHOD(AccessType::Private, getMultipleB)
	RF_METHOD(AccessType::Public, setA)
	RF_METHOD(AccessType::Public, getA)
RF_METADATA_END