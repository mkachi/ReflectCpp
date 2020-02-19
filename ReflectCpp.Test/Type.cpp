#include "gtest/gtest.h"
#include "Test1.h"
#include "Test2.h"

#include "Enum1.h"
#include "Enum2.h"
#include "Enum3.h"

TEST(Type, getType)
{
	Test1 test;
	Type type1 = typeof(Test1);
	Type type2 = test.getType();
	ASSERT_TRUE(type1 == type2);
}

TEST(Type, name)
{
	Sample::Test2 test;
	Type type = test.getType();
	ASSERT_TRUE(type.getName() == "Test2");
	ASSERT_TRUE(type.getFullName() == "Sample::Test2");
}

TEST(Type, isPremitive)
{
	Type type1 = typeof(int);
	ASSERT_TRUE(type1.isPremitive());

	Type type2 = typeof(double);
	ASSERT_TRUE(type2.isPremitive());

	Type type3 = typeof(char);
	ASSERT_TRUE(type3.isPremitive());
}

TEST(Type, isClass)
{
	Type type = typeof(Sample::Test2);
	ASSERT_TRUE(type.isClass());
}

TEST(Type, isEnum)
{
	Type type1 = typeof(Enum1);
	ASSERT_TRUE(type1.isEnum());

	Type type2 = typeof(Enum2);
	ASSERT_TRUE(type2.isEnum());

	Type type3 = typeof(Sample::Enum3);
	ASSERT_TRUE(type3.isEnum());
}