#pragma once
#include <iostream>
#include <string>

class Address
{
public:
	Address();
	Address(int new_street, const char* new_city);
	Address& operator =(const Address address);
	~Address() { delete[] city; }

private:
	int		street;
	char*	city;
};
