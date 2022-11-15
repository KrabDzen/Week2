#include "Profile.h"
#include <iostream>


void Profile::init(User owner)
{
	_user = owner;
	_page = new Page;
	_page->init();
	_friendsList = new UserList;
	_friendsList->init();
}

void Profile::clear()
{
	//_user.clear(); //This line should work and be included in the code nut for some reason it crashes if I use it
	//Which is very weird considering I got this function(_user.clear()) prewritten from Magshimim
	_page->clearPage();
	_friendsList->clear();

	delete(_page);
	delete(_friendsList);
}

User Profile::getOwner() const
{
	return _user;
}

void Profile::setStatus(std::string new_status)
{
	_page->setStatus(new_status);
}

void Profile::addPostToProfilePage(std::string post)
{
	_page->addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add)
{
	_friendsList->add(friend_to_add);
}

std::string Profile::getPage() const
{
	return "Status: " + _page->getStatus() + "\n*******************\n*******************" + _page->getPosts() + "\n";
}

std::string Profile::getFriends() const
{
	UserNode* temp = _friendsList->get_first();
	std::string ret = "";
	while (temp)
	{
		ret += temp->get_data().getUserName();
		temp = temp->get_next();
		if (temp)//If the temp we entered with have another person after
		{
			ret += ",";//Wanted to add space after the ',',
			//but the tester yelled at me for this so no space for your ease of reading :(
		}
	}
	return ret;
}

std::string Profile::getFriendsWithSameNameLength() const
{
	int userNameLength = _user.getUserName().length(), currentFrienNameLength = 0;;
	UserNode* temp = _friendsList->get_first();
	std::string ret = "";
	while (temp)
	{
		currentFrienNameLength = temp->get_data().getUserName().length();
		if (currentFrienNameLength == userNameLength)
		{
			ret += "," + temp->get_data().getUserName();
			//There will be "," before every name without need for me to make sure there is more names with same length later
		}
		temp = temp->get_next();
	}
	if (ret.length() > 1)
	{
		return ret.substr(1, ret.length());//start from 1 because the first index is ','
	}
	return "";
}

