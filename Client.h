#pragma once
#include "Address.h"

class Client
{
public:
	Client();
	Client(const char* new_name, const char* new_phone_number, Address new_address);
	Client& operator =(const Client& client);
	~Client();
	void setName(const char* new_name) { name = new_name; }
	void setPhoneNumber(const char* new_phone_number) { phoneNumber = new_phone_number; }
	void setAddress(Address new_address) { homeAddress = new_address; }

private:
	const char*		name;
	const char*		phoneNumber;
	int				credits;
	Address			homeAddress;
};