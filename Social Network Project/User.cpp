#include "User.h"

void User::init(unsigned int id, std::string username, unsigned int age)
{
	this->_id = id;
	this->_name = username;
	this->_age = age;
	this->_devicesList = new DevicesList;
	this->_devicesList->init();

}

void User::clear()
{
	_devicesList->clear();
	delete(_devicesList);
	_age = 0;
	_id = 0;
	_name = "";
}

unsigned int User::getID() const
{
	return _id;
}

std::string User::getUserName() const
{
	return _name;
}

unsigned int User::getAge() const
{
	return _age;
}

DevicesList& User::getDevices() const
{
	return* _devicesList;
}

void User::addDevice(Device newDevice)
{
	_devicesList->add(newDevice);
}

bool User::checkIfDevicesAreOn() const
{
	DeviceNode* temp = _devicesList->get_first();
	while (temp)
	{
		if (!temp->get_data().isActive())//temp->get-data gives the device of the current node
		{								 //and isActive returns true if the device is active
			return false;
		}
		temp = temp->get_next();
	}
	return true;//If none of the devices triggered the if then it means all of the devices are on
}
