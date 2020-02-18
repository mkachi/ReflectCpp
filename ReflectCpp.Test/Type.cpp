#include "gtest/gtest.h"
#include "Example.h"
#include <Type.h>

TEST(Type, getName) {
	Type type = typeof(Hello::Base);
	ASSERT_TRUE(type.getName() == "Hello::Base");
}

TEST(Type, operator) {
	Type type = typeof(Hello::Base);
	Type type2 = typeof(Hello2::Base);
	ASSERT_FALSE(type == type2);
}