#include "Dish.h"
#include <iomanip>

/*-------------------------------------------------------------------------------*/
// Default constructor
Dish::Dish()
	:
	value(0),
	dish_status(false)
{
	name = NULL;
}

/*-------------------------------------------------------------------------------*/
// Constructor
Dish::Dish(const char* new_name, DishType new_type, int new_value)
	:
	type(new_type),
	value(new_value),
	dish_status(true)
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

/*-------------------------------------------------------------------------------*/
// Assignment operator
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

/*-------------------------------------------------------------------------------*/
// Print the Dish
void Dish::printDish()
{
	std::cout << std::setw(20) << std::left << name << std::setw(5) << value << "NIS\n";
}

/*-------------------------------------------------------------------------------*/
// Print the dish that have been hadded by the client to the order (call from Menu - returnDishByChoose())
void Dish::printDishAdded()
{
	std::cout << name << " has been added!\n";
}