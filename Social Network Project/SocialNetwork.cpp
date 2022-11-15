#include "SocialNetwork.h"

void SocialNetwork::init(std::string networkName, int minAge)
{
	_networkName = networkName;
	_minAge = minAge;
	_profilesList = new ProfileList;
	_profilesList->init();
}

void SocialNetwork::clear()
{
	_minAge = 0;
	_networkName = "";
	_profilesList->clear();
	delete(_profilesList);
}

std::string SocialNetwork::getNetworkName() const
{
	return _networkName;
}

int SocialNetwork::getMinAge() const
{
	return _minAge;
}

bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < _minAge)
	{
		return false;
	}
	_profilesList->add(profile_to_add);
	return true;
}

std::string SocialNetwork::getWindowsDevices() const
{
	ProfileNode* temp = _profilesList->get_first();
	std::string ret = "";
	User user;
	DeviceNode* deviceNode;
	Device device;
	std::string deviceOS;
	while (temp)
	{
		user = temp->get_data().getOwner();
		deviceNode = user.getDevices().get_first();
		while (deviceNode)
		{
			device = deviceNode->get_data();
			deviceOS = device.getOS();
			if (deviceOS == WINDOWS10 || deviceOS == WINDOWS11 || deviceOS == WINDOWS7)
			{
				ret += "[" + device.getID() + ', ' + deviceOS + "], ";
			}
			deviceNode = deviceNode->get_next();
		}
		temp = temp->get_next();
	}
	return ret.substr(0, ret.length()-2);
	//Start from 2 because the first two chars are - ', '
}


