#include "Application.h"

Application::Application()
	:
	clients(NULL),
	restaurants(NULL),
	orders(NULL) {}

Application::Application(Client* new_clients, int new_num_of_clients, Restaurant* new_restaurants, int new_num_of_restaurants)
	:
	curr_orders_num(0),
	max_orders_num(1),
	num_of_clients(new_num_of_clients),
	num_of_restaurants(new_num_of_restaurants)
{
	orders = new Order[max_orders_num];
	if (orders == NULL)
	{
		std::cout << "Memory error! Application not created\n";
	}

	clients = new Client[new_num_of_clients];
	if (clients == NULL)
	{
		std::cout << "Memory error, Application not created\n";
	}
	for (int i = 0; i < new_num_of_clients; i++)
	{
		clients[i] = new_clients[i];
	}
	
	restaurants = new Restaurant[new_num_of_restaurants];
	if (restaurants == NULL)
	{
		std::cout << "Memory error, Application not created\n";
	}
	for (int i = 0; i < new_num_of_restaurants; i++)
	{
		restaurants[i] = new_restaurants[i];
	}
}

Application::~Application()
{
	for (int i = 0; i < curr_orders_num; i++)
	{
		orders[i].~Order();
	}
	delete[] orders;

	for (int i = 0; i < num_of_clients; i++)
	{
		clients[i].~Client();
	}
	delete[] clients;

	for (int i = 0; i < num_of_restaurants; i++)
	{
		restaurants[i].~Restaurant();
	}
	delete[] restaurants;
}