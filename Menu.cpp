#include "Menu.h"

Menu::Menu()
	:
	dishes(NULL),
	size(0) {}

Menu::Menu(Dish* new_dishes, int new_size)
	:
	size(new_size)
{
	dishes = new Dish[new_size];
	if (dishes == NULL)
	{
		std::cout << "Memory error, Menu not created\n";
	}
	for (int i = 0; i < new_size; i++)
	{
		dishes[i] = new_dishes[i];
	}
}


Menu& Menu::operator = (const Menu& menu)
{
	if (this != &menu)
	{
		delete[] dishes;
		size = menu.size;
		dishes = new Dish[size];
		if (dishes == NULL)
		{
			std::cout << "Memory error, Menu not copied\n";
		}
		for (int i = 0; i < menu.size; i++)
		{
			dishes[i] = menu.dishes[i];
		}
	}
	return *this;
}

Menu::~Menu() {
	for (int i = 0; i < size; i++)
	{
		dishes[i].~Dish();
	}
	delete[] dishes;
}