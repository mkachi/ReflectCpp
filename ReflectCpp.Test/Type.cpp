#include "gtest/gtest.h"
#include <Reflection.h>

namespace Test1
{
	class Base
	{
		RF_CLASS;
	private:
		int _a;
		int _b;

		int getB() { return _b; }

	public:
		static int C;
		void setA(int a)
		{
			_a = a;
			_b = a * 2;
		}

		int getA()
		{
			return _a;
		}

	};
}

RF_METADATA_BEGIN(Test1::Base)
	RF_FIELD(AccessType::Private, _a)
	RF_FIELD(AccessType::Private, _b)
	RF_METHOD(AccessType::Private, getB)
	RF_METHOD(AccessType::Public, setA)
	RF_METHOD(AccessType::Public, getA)
RF_METADATA_END

int Test1::Base::_typeId = __internal::Metadata<Test1::Base>::__createMetadata();

TEST(Type, Metadata) 
{
	Test1::Base base;
	Type type = typeof(Test1::Base);
	type.getMethod("setA")->invoke<void>(&base, 10);

	int result;
	result = type.getMethod("getA")->invoke<int>(&base);
	ASSERT_TRUE(result == 10);

	result = type.getField("_a")->getValue<int>(&base);
	ASSERT_TRUE(result == 10);

	result = type.getField("_b")->getValue<int>(&base);
	ASSERT_TRUE(result == (10 * 2));

	type.getField("_b")->setValue(&base, 99);
	result = type.getMethod("getB")->invoke<int>(&base);
	ASSERT_TRUE(result == 99);
}