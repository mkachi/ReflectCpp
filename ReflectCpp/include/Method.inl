#pragma once

#include "Method.h"

template<typename Result, typename Instance, typename ...Args>
inline Result Method::invoke(const Instance& instance, Args ...args)
{
	typedef Result(Instance::* MethodType)(Args...);
	MethodType method = std::any_cast<MethodType>(_method);
	std::function<Result(Args...)> result = std::bind(method, instance, args...);
	return result(args...);
}