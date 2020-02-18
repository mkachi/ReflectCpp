template<typename T, typename Instance>
inline void Field::setValue(Instance* instance, const T& value)
{
	typedef T Instance::* __FieldType;
	__FieldType field = std::any_cast<__FieldType>(_field);
	instance->*field = value;
}

template<typename T, typename Instance>
inline T Field::getValue(Instance* instance)
{
	typedef T Instance::* __FieldType;
	__FieldType field = std::any_cast<__FieldType>(_field);
	return instance->*field;
}