#include "gtest/gtest.h"
#include "Example.h"
#include <Method.h>

TEST(Method, invoke) {
	Hello::Base sample;

	Type type = typeof(Hello::Base);
	Method* getA = new Method(type, AccessType::Public, "getA", &Hello::Base::getA, false);
	int result = 0;

	sample.setA(100);
	result = getA->invoke<int>(&sample);
	ASSERT_TRUE(result == 100);

	sample.setA(200);
	result = getA->invoke<int>(&sample);
	ASSERT_TRUE(result == 200);

	sample.setA(300);
	result = getA->invoke<int>(&sample);
	ASSERT_TRUE(result == 300);
}