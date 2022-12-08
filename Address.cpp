#include "Address.h"

/*-------------------------------------------------------------------------------*/
// Default constructor
Address::Address()
	:
	street(0)
{
	city = NULL;
}

/*-------------------------------------------------------------------------------*/
// constructor
Address::Address(int new_street, const char* new_city)
	:
	street(new_street)
{
	city = new char[strlen(new_city) + 1];
	if (city == NULL)
	{
		std::cout << "Memory Error! Address not created." << std::endl;
		return;
	}
	//strcpy_s(city, strlen(new_city) + 1, new_city);
	strncpy(city, new_city, strlen(new_city) + 1);
}

/*-------------------------------------------------------------------------------*/
// Assignment operator
Address& Address::operator =(const Address& address) {
	if (this != &address)
	{
		delete[] city;
		street = address.street;
		city = new char[strlen(address.city)+1];
		//strcpy_s(city, strlen(address.city) + 1, address.city);
		strncpy(city, address.city, strlen(address.city) + 1);
	}
	return *this;
}