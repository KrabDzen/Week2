#pragma once
#include "ProfileList.h"

class SocialNetwork
{
public:
	//methods

	//Creates a new Network with given name and minimum age
	void init(std::string networkName, int minAge);

	//Clears the entire network
	void clear();

	//getters
	std::string getNetworkName() const;
	int getMinAge() const;
	std::string getWindowsDevices() const;

	//Add a new profile to the network
	bool addProfile(Profile profile_to_add);
private:
	//fields
	std::string _networkName;
	int _minAge;
	ProfileList* _profilesList;
};
