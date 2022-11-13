#pragma once
#include "DeviceList.h"

class User
{
public:
	//methods
	void init(unsigned int id, std::string username, unsigned int age);
	void clear();
	unsigned int getID() const;
	std::string getUserName() const;
	unsigned int getAge() const;
	DevicesList& getDevices() const;
	void addDevice(Device newDevice);
	bool checkIfDevicesAreOn() const;

private:
	//variables
	unsigned int _id;
	std::string _name;
	unsigned int _age;
	DevicesList* _devicesList;
};


