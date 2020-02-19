#pragma once

#include <Reflection.h>

class Test1
{
	RF_CLASS;
private:
	int _a;
	int _b;

	int getMultipleB(int value) { return _b * value; }

public:
	Test1();
	~Test1();

	static int c;

	void setA(int a);
	int getA() { return _a; }

	static int add(int value1, int value2);

};