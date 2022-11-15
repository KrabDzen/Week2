#include "Device.h"

/*
* Function creates a new Device with given variables
* Input: id - used as a new Device's id, type - used as a new Device's DeviceType, os - used as a new Device's os
* Output: *NONE*
*/
void Device::init(unsigned int id, DeviceType type, const std::string& os)
{
	this->_id = id;
	this->_type = type;
	this->_os = os;
	this->_active = true;
}
/*
* Function returns the id of the device
* Input: *NONE*
* Output: The id of the device
*/
unsigned int Device::getID() const
{
	return this->_id;
}
/*
* Function returns the type of the device
* Input: *NONE*
* Output: The type of the device
*/
DeviceType Device::getType() const
{
	return this->_type;
}
/*
* Function returns the os of the device
* Input: *NONE*
* Output: The os of the device
*/
std::string Device::getOS() const
{
	return this->_os;
}
/*
* Function returns whther the device is active or not
* Input: *NONE*
* Output: True if device is active, False otherwise
*/
bool Device::isActive() const
{
	return this->_active;
}
/*
* Function activates the device
* Input: *NONE*
* Output: *NONE*
*/
void Device::activate()
{
	this->_active = true;
}
/*
* Function deactivates the device
* Input: *NONE*
* Output: *NONE*
*/
void Device::deactivate()
{
	this->_active = false;
}