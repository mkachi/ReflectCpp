#include "gtest/gtest.h"
#include <Type.h>

namespace Hello
{
	class Base
	{
	private:
		int _a;

	public:
		void setA(int value) { _a = value; }
		int getA() { return _a; }

	};

	class Base2
	{
	private:
		int _a;

	public:
		void setA(int value) { _a = value; }
		int getA() { return _a; }

	};
}

namespace Hello2
{
	class Base
	{
	private:
		int _a;

	public:
		void setA(int value) { _a = value; }
		int getA() { return _a; }

	};
}

TEST(Type, getName) {
	Type type = typeof(Hello::Base);
	ASSERT_TRUE(type.getName() == "Hello::Base");
}

TEST(Type, operator) {
	Type type = typeof(Hello::Base);
	Type type2 = typeof(Hello2::Base);
	ASSERT_FALSE(type == type2);
}