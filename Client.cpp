#include "Client.h"

/*-------------------------------------------------------------------------------*/
// Default constructor
Client::Client()
	:
	credits(100),
	name(NULL),
	phoneNumber(NULL) {}

/*-------------------------------------------------------------------------------*/
// Constructor
Client::Client(const char* new_name, const char* new_phone_number, Address new_address)
	:
	credits(100)
{
	name = new_name;
	phoneNumber = new_phone_number;
	//name = new char[strlen(new_name) + 1];
	//if (name == NULL)
	//{
	//	std::cout << "Memory Error! Client not created." << std::endl;
	//	return;
	//}
	//phoneNumber = new char[strlen(new_phone_number) + 1];
	//if (phoneNumber == NULL)
	//{
	//	std::cout << "Memory Error! Client not created." << std::endl;
	//	delete[] name;
	//	return;
	//}
	//strcpy_s(name, strlen(new_name) + 1, new_name);
	//strcpy_s(phoneNumber, strlen(new_phone_number) + 1, new_phone_number);
	homeAddress = new_address;
}

/*-------------------------------------------------------------------------------*/
// Assignment operator
Client& Client::operator = (const Client& client)
{
	if (this != &client)
	{
		//delete[] name;
		//delete[] phoneNumber;
		name = client.name;
		phoneNumber = client.phoneNumber;
		credits = client.credits;
		homeAddress = client.homeAddress;
		//name = new char[strlen(client.name) + 1];
		//if (name == NULL)
		//{
		//	std::cout << "Memory error, Client not copied\n";
		//}
		//strcpy_s(name, strlen(client.name) + 1, client.name);

		//phoneNumber = new char[strlen(client.phoneNumber) + 1];
		//if (phoneNumber == NULL)
		//{
		//	delete[] name;
		//	std::cout << "Memory error, Client not copied\n";
		//}
		//strcpy_s(phoneNumber, strlen(client.phoneNumber) + 1, client.phoneNumber);
	}
	return *this;
}

/*-------------------------------------------------------------------------------*/
// Destructor
Client::~Client() 
{
	//delete[] name;
	//delete[] phoneNumber;
	homeAddress.~Address();
}