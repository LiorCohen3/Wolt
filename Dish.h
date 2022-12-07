#pragma once
#include <iostream>
#include <string>

enum DishType
{
	Appetizer = 1,
	MainCourse,
	Dessert
};

class Dish
{
public:
	Dish();
	Dish(const char* new_name, DishType new_type, int new_value);
	Dish& operator =(const Dish& dish);
	~Dish() {}
public:
	int getValue() { return value;}
	void setName(const char* new_name) { name = new_name; }
	DishType getDishType() { return type; }
	void setDishType(DishType new_type) { type = new_type; }
	void setValue(int new_value) { value = new_value; }
	bool getDishStatus(){return dish_status;}
	void setDishStatus(bool val){dish_status = val;}
	void printDish();
	void printDishAdded();

private:
	const char*		name;
	DishType		type;
	bool			dish_status;
	int				value;
};
