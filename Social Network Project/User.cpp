#include "User.h"

/*
* Function creates a new user with given parameters
* Input: id - used a new user's id, username - used as a new user's name, age - used as a new user's age
*/
void User::init(unsigned int id, std::string username, unsigned int age)
{
	this->_id = id;
	this->_name = username;
	this->_age = age;
	this->_devicesList = new DevicesList;
	this->_devicesList->init();

}
/*
* FUnction clears(deletes/resets) the current user
* Input: *NONE*
* Output: *NONE*
*/
void User::clear()
{
	_devicesList->clear();
	delete(_devicesList);
	_age = 0;
	_id = 0;
	_name = "";
}
/*
* Function returns user's id
* Input: *NONE*
* Output: user's id
*/
unsigned int User::getID() const
{
	return _id;
}
/*
* Function returns user's name
* Input: *NONE*
* Output: user's name
*/
std::string User::getUserName() const
{
	return _name;
}
/*
* Function returns user's age
* Input: *NONE*
* Output: user's age
*/
unsigned int User::getAge() const
{
	return _age;
}
/*
* Function returns list of all user's devices
* Input: *NONE*
* Output: all of user's devices
*/
DevicesList& User::getDevices() const
{
	return* _devicesList;
}
/*
* Function add a new device to user's list of devices
* Input: a new device to add to the list
* Output: *NONE* 
*/
void User::addDevice(Device newDevice)
{
	_devicesList->add(newDevice);
}
/*
* Function checks if all of user's devices are on
* Input: *NONE*
* Output: True if all of user's devices are currently acrive(on), false if at least on of them is inactive(off)
*/
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
