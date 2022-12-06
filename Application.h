#pragma once
#include "Client.h"
#include "Restaurant.h"
#include "Order.h"

class Application
{
public:
	Application();
	Application(Client* new_clients, int num_of_clients, Restaurant* new_restaurants, int num_of_restaurants);
	~Application();
public:
	void order();

private:
	Client*		clients;
	int			num_of_clients;
	Restaurant* restaurants;
	int			num_of_restaurants;
	Order*		orders;
	int			curr_orders_num;
	int			max_orders_num;
};