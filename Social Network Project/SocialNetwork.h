#pragma once
#include "ProfileList.h"

class SocialNetwork
{
public:
	void init(std::string networkName, int minAge);
	void clear();
	std::string getNetworkName() const;
	int getMinAge() const;
	bool addProfile(Profile profile_to_add);
	std::string getWindowsDevices() const;
private:
	//fields
	std::string _networkName;
	int _minAge;
	ProfileList* _profilesList;
};
