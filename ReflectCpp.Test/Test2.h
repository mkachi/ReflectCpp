#pragma once

#include <Reflection.h>

namespace Sample
{
	class Test2
	{
		RF_CLASS;
	private:
		int _a;
		int _b;

		int getMultipleB(int value) { return _b * value; }

	public:
		Test2();
		~Test2();

		void setA(int a);
		int getA() { return _a; }

	};
}