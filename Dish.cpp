#include "Dish.h"

Dish::Dish()
	:
	value(0)
{
	name = NULL;
}

Dish::Dish(const char* new_name, DishType new_type, int new_value)
	:
	type(new_type),
	value(new_value)
{
	name = new_name;
	//name = new char[strlen(new_name) + 1];
	//if (name == NULL)
	//{
	//	std::cout << "Memory Error! Dish not created." << std::endl;
	//	return;
	//}
	//strcpy_s(name, strlen(new_name) + 1, new_name);
}

Dish& Dish::operator = (const Dish& dish)
{
	if (this != &dish)
	{
		delete[] name;
		type = dish.type;
		value = dish.value;
		name = dish.name;
		//name = new char[strlen(dish.name) + 1];
		//if (name == NULL)
		//{
		//	std::cout << "Memory error, Dish not copied\n";
		//}
		//strcpy_s(name, strlen(dish.name) + 1, dish.name);
	}
	return *this;
}