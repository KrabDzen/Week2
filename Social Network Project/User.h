#pragma once
#include "DeviceList.h"

class User
{
public:
	//methods
	
	//Creates a new User with given parameters
	void init(unsigned int id, std::string username, unsigned int age);
	
	//Clears the User
	void clear();

	//getters
	unsigned int getID() const;
	std::string getUserName() const;
	unsigned int getAge() const;
	DevicesList& getDevices() const;

	//Adds a device to the user
	void addDevice(Device newDevice);

	//Checks whether all of user's devices are on
	bool checkIfDevicesAreOn() const;

private:
	//fields
	unsigned int _id;
	std::string _name;
	unsigned int _age;
	DevicesList* _devicesList;
};


