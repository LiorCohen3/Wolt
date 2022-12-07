#pragma once
#include "Client.h"
#include "Restaurant.h"

class Order
{
public:
	Order();
	Order(Dish* dishes_order, Client client_order, Restaurant restaurant_order, int order_size);
	~Order();
public:
	void PrintOrder();
	bool CallgetDishStatus(int index){dishes[index].getDishStatus();}
	void CallSetDishStatus(int index, bool val) {dishes[index].setDishStatus(val);}

private:
	Dish*		dishes;
	int			dishes_size;
	int			totalSum;
	Client		client;
	Restaurant	restaurant;
};