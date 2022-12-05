#include "Restaurant.h"

Restaurant::Restaurant()
	:
	name(NULL) {}

Restaurant::Restaurant(const char* new_name, Address new_address, Menu new_menu)
	:
	street(new_address),
	menu(new_menu)
{
	name = new_name;
	/*name = new char[strlen(new_name) + 1];
	if (name == NULL)
	{
		std::cout << "Memory Error! Client not created." << std::endl;
		return;
	}
	strcpy_s(name, strlen(new_name) + 1, new_name);*/
}


Restaurant& Restaurant::operator = (const Restaurant& restaurant)
{
	if (this != &restaurant)
	{
		/*delete[] name;*/
		street = restaurant.street;
		menu = restaurant.menu;
		name = restaurant.name;
		/*name = new char[strlen(restaurant.name) + 1];
		if (name == NULL)
		{
			std::cout << "Memory error, Restaurant not copied\n";
		}
		strcpy_s(name, strlen(restaurant.name) + 1, restaurant.name);*/
	}
	return *this;
}

Restaurant::~Restaurant() {
	//delete[] name;
	street.~Address();
	menu.~Menu();
}