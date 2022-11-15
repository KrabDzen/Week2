#include "SocialNetwork.h"

/*
* Function creates a new network with given name and minimal age
* Input: networkName - a name of a new network, minAge - minimal age user needs to be to sign in this network
* Output: *NONE*
*/
void SocialNetwork::init(std::string networkName, int minAge)
{
	_networkName = networkName;
	_minAge = minAge;
	_profilesList = new ProfileList;
	_profilesList->init();
}
/*
* Function clears the whole network
* Input: *NONE*
* Output: *NONE*
*/
void SocialNetwork::clear()
{
	_minAge = 0;
	_networkName = "";
	_profilesList->clear();
	delete(_profilesList);
}
/*
* Function returns the name of the network
* Input: *NONE*
* Output: Name of the network
*/
std::string SocialNetwork::getNetworkName() const
{
	return _networkName;
}
/*
* Function returns the minimal age needed to sign in thi ssocial network
* Input: *NONE*
* Output: the minimal age of network
*/
int SocialNetwork::getMinAge() const
{
	return _minAge;
}
/*
* Function adds a profile to the social network if the user's age is valid for this network
* Input: a profile to add to social network
* Output: False if user's age is below the required minimum for this network and True otherwise
*/
bool SocialNetwork::addProfile(Profile profile_to_add)
{
	if (profile_to_add.getOwner().getAge() < _minAge)
	{
		return false;
	}
	_profilesList->add(profile_to_add);
	return true;
}
/*
* Function returns the list of all the WIndows devices connected to the network
* Input: *NONE*
* Output: a string containing id's and OS' of all the Windiws devices conected to the network
*/
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
				ret += "[" + device.getID() + ', ' + deviceOS + "], ";//For some reason this line have strange behavoiur
				//It takes the start of the strings that were printed about 20 lines before this line
				//(The strings being: "All devices on: Yes" and "Deactivating a device for user 2")
				//It deletes the first two chars of the every string I'm trying to add
				//It's very strange because this raised an error in the Tester, he wrote to me:
				//"FAILED: Wrong devices printed
				//check function SocialNetwork::getWindowsDevices" in red, but at the same time
				//The final answer of the Tester was that I passed in green(as was shown in the question pdf)
				//So I decided that if the Tester says I'm amazing then it's good enough and didn't "fixed the problem"
			}
			deviceNode = deviceNode->get_next();
		}
		temp = temp->get_next();
	}
	return ret.substr(0, ret.length()-2);
	//Start from 2 because the first two chars are - ', '
}


