#include "Test2.h"

namespace Sample
{
	Test2::Test2()
		: _a(0)
		, _b(0) {}
	Test2::~Test2() {}

	void Test2::setA(int a)
	{
		_a = a;
	}
}