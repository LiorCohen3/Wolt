#include "Order.h"

/*-------------------------------------------------------------------------------*/
// Default constructor
Order::Order()
	:
	dishes(NULL),
	totalSum(0) {}

/*-------------------------------------------------------------------------------*/
//Constructor
Order::Order(Dish* dishes_order, Client client_order, Restaurant restaurant_order, int order_size)
	:
	client(client_order),
	restaurant(restaurant_order)
{
	int sum = 0;
	dishes = new Dish[order_size];
	if (dishes == NULL)
	{
		std::cout << "Memory error, Order not created\n";
	}
	for (int i = 0; i < order_size; i++)
	{
		sum += dishes_order[i].getValue();
		dishes[i] = dishes_order[i];
	}
	totalSum = sum;
}

/*-------------------------------------------------------------------------------*/
// Destructor
Order::~Order()
{
	delete[] dishes;
	restaurant.~Restaurant();
	client.~Client();
}

/*-------------------------------------------------------------------------------*/
// Order Print
void Order::PrintOrder()
{
	std::cout << "your order:" << std::endl;
	for (int i = 0; i < dishes_size; i++)
	{
		if (dishes[i].getDishStatus())
		{
			std::cout << i+1 << " ";
			dishes[i].printDish();
			std::cout << std::endl;
		}
	}
}