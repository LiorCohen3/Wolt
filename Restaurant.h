#pragma once
#include "Menu.h"
#include "Address.h"

class Restaurant
{
public:
	Restaurant();
	Restaurant(const char* new_name, Address new_address, Menu new_menu);
	Restaurant& operator = (const Restaurant& restaurant);
	~Restaurant();
	void setName(const char* new_name) { name = new_name; }
	void setAddress(Address new_address) { street = new_address; }
	void setMenu(Menu new_menu) { menu = new_menu; }

private:
	const char*		name;
	Address			street;
	Menu			menu;
};