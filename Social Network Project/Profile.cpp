#include "Profile.h"
#include <iostream>

/*
* Function create a new blank profile for given user
* Input: user to who function assigns the profile
* Output: *NONE*
*/
void Profile::init(User owner)
{
	_user = owner;
	_page = new Page;
	_page->init();
	_friendsList = new UserList;
	_friendsList->init();
}
/*
* Function clears profile's page and list of friends
* Input: *NONE*
* Output: *NONE*
*/
void Profile::clear()
{
	//_user.clear(); //This line should work and be included in the code but for some reason it crashes if I use it
	//Which is very weird considering I got this function(_user.clear()) prewritten from Magshimim
	_page->clearPage();
	_friendsList->clear();

	delete(_page);
	delete(_friendsList);
}
/*
* Function returns the owner of the profile
* Input: *NONE*
* Output: The owner(user) of the profile
*/
User Profile::getOwner() const
{
	return _user;
}
/*
* Function changes the status of the profile to new given status
* Input: A new status for the profile
* Output: *NONE*
*/
void Profile::setStatus(std::string new_status)
{
	_page->setStatus(new_status);
}
/*
* Function adds a new post to the profile
* Input: a post to add to the profile page
* Output: *NONE*
*/
void Profile::addPostToProfilePage(std::string post)
{
	_page->addLineToPosts(post);
}
/*
* Function adds a new friend to profile(I wish it was that easy to find a new friend)
* Input: a user to add as a friend
* Output: *NONE*
*/
void Profile::addFriend(User friend_to_add)
{
	_friendsList->add(friend_to_add);
}
/*
* Function returns user's page in a special form
* Input: *NONE*
* Output: user's page(status and posts)
*/
std::string Profile::getPage() const
{
	return "Status: " + _page->getStatus() + "\n*******************\n*******************" + _page->getPosts() + "\n";
}
/*
* Function returns a string containing all friends
* Input: *NONE*
* Output: All of user's friends in a string
*/
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
			//but the tester yelled at me for this so no space for ease of reading :(
		}
	}
	return ret;
}
/*
* Function returns a string containing all of user's friend with the same name length as his name
* Input: *NONE*
* Output: all of user's friends with same name length as his name length in a string
*/
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

