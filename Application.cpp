#include "Application.h"
#define MAX_ORDER_SIZE 20

/*-------------------------------------------------------------------------------*/
// Default constructor
Application::Application()
	:
	clients(NULL),
	restaurants(NULL),
	orders(NULL) {}

/*-------------------------------------------------------------------------------*/
//Constructor
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

/*-------------------------------------------------------------------------------*/
// Destructor
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

/*-------------------------------------------------------------------------------*/
// Order func (call from main)
void Application::order()
{
	int choose = 0;
	do
	{
		std::cout << "\n1) Back <--\n";
		for (int i = 0; i < num_of_restaurants; i++)
		{
			std::cout << i + 2 << ") ";
			restaurants[i].printRestaurant();
		}
		std::cout << "\n>";
		std::cin >> choose;

	} while (choose < 1 || choose > num_of_restaurants + 1);
	if (choose == 1) return;
	int restaurantIndex = choose - 2;
	if (strcmp(restaurants[restaurantIndex].callGetCity(),clients[0].callGetCity()) == 0)
	{
		Dish chosen_dishes[MAX_ORDER_SIZE];
		int order_size = restaurants[restaurantIndex].makeOrder(chosen_dishes);
		Order new_order(chosen_dishes, clients[0], restaurants[restaurantIndex], order_size);
		orders[curr_orders_num] = new_order;
		std::cout << "\nPlease confirm the details of the order:\n\n";
		std::cout << "Client's details: ";
		clients[0].printClient();
		std::cout << "Restaurant: ";
		restaurants[restaurantIndex].printRestaurant();
		int client_credit = clients[0].getCredits();
		int order_sum = orders[curr_orders_num].getTotalSum();
		if (client_credit < order_sum)
		{
			std::cout << "\nError! not enough credits. Please remove items\n"
				<< "Order total:" << order_sum << " NIS " << "\nAvailable balance:"
				<< client_credit << " NIS\n\n";
			CheckOrder();
		}
	}
	else std::cout << "This restaurant does not deliver to you!\n";
	return;
}

/*-------------------------------------------------------------------------------*/
// Check Order func (call from main)
void Application::CheckOrder()
{
	// print the order first
	orders[curr_orders_num].PrintOrder();
	std::cout << "\nWould you like to delete a dish?" << std::endl << "1 - yes" 
		<< std::endl << "0 - No, leave the order" << std::endl << std::endl;
	int sel;
	do
	{
		std::cout << ">";
		std::cin >> sel;
	} while (sel != 0 && sel != 1);

	if (sel == 0)
		return;		// no changes
	
	// Changes
	std::cout << "\nWhich dish would you like to delete?" << std::endl
				<< "Select a dish by number\nEnter 0 to finish" << std::endl;;
	do
	{
		do
		{
			std::cout << ">";
			std::cin >> sel;
		} while (sel < 0 || sel > orders[curr_orders_num].getSize());
		if (sel != 0)
		{
			orders[curr_orders_num].deleteDishByIndex(sel - 1);
		}
	} while (sel != 0);
	
	


}