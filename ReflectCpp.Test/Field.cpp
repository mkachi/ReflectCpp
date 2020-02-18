#include "gtest/gtest.h"
#include <Field.h>

class Base
{
private:
	int _a;

public:
	void setA(int value) { _a = value; }
	int getA() { return _a; }

	static Field* getFieldInfo()
	{
		Type type = typeof(Base);
		Field* result = new Field(type, AccessType::Private, "_a", &Base::_a, false);
		return result;
	}

};

TEST(Field, getValue) 
{
	Base test;
	Field* field = Base::getFieldInfo();
	
	test.setA(100);
	ASSERT_TRUE(test.getA() == field->getValue<int>(&test));

	test.setA(200);
	ASSERT_TRUE(test.getA() == field->getValue<int>(&test));
}