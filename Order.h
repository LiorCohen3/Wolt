#pragma once
#include "Client.h"
#include "Restaurant.h"

class Order
{
public:
	Order();
	Order(Dish* dishes_order, Client client_order, Restaurant restaurant_order, int order_size);
	~Order();

private:
	Dish*		dishes;
	int			totalSum;
	Client		client;
	Restaurant	restaurant;
};