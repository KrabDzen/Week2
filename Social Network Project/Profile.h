#pragma once
#include "Page.h"
#include "UserList.h"

class Profile
{
public:
	//methods

	//Creates a new profile with owner already set
	void init(User owner);

	//Clears(resets) the page and friends list
	void clear();

	//getters
	User getOwner() const;
	std::string getPage() const;
	std::string getFriends() const;
	std::string getFriendsWithSameNameLength() const;

	//Changes the status
	void setStatus(std::string new_status);

	//Adds post to page
	void addPostToProfilePage(std::string post);

	//Adds a new friend
	void addFriend(User friend_to_add);



private:
	//fields
	User _user;
	Page* _page;
	UserList* _friendsList;
};
