#pragma once
#include <string>

///////////////////////////////////////////////////////////
/*														 //
	Those definitions are used for tests,                //
	you can add your own, but please do not delete any.  //
*/														 //
enum DeviceType {PHONE, PC, LAPTOP, TABLET};		     //
													     //
#define UbuntuOS "UbuntuLinux"                           //						
#define RedHatOS "RedHatLinux"							 //
#define MacOS "MacOS"									 //
#define IOS "IOS"										 //
#define WINDOWS7 "Windows7"                              //
#define WINDOWS10 "Windows10"                            //
#define WINDOWS11 "Windows11"                            //
#define ANDROID "Android"                                //
													     //
/// ///////////////////////////////////////////////////////


class Device
{
public:
	//methods
	
	//Create a new Device with given variables
	void init(unsigned int id, DeviceType type, const std::string& os);

	//getters
	unsigned int getID() const;
	DeviceType getType() const;
	std::string getOS() const;
	bool isActive() const;

	//changes the state of _active 
	void activate();
	void deactivate();
private:
	//fields
	unsigned int _id;
	DeviceType _type;
	std::string _os;
	bool _active;
};

