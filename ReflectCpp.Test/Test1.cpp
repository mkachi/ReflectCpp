#include "Test1.h"

Test1::Test1()
	: _a(0)
	, _b(0) {}
Test1::~Test1() {}

void Test1::setA(int a)
{
	_a = a;
}

int Test1::add(int value1, int value2)
{
	return value1 + value2;
}