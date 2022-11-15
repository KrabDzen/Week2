#pragma once
#include <string>

class Page
{
public:
	//methods

	//Creates a new clear page
	void init();

	//getters
	std::string getPosts() const;
	std::string getStatus() const;

	//Clears(resets) the entire page
	void clearPage();
	
	//Changes the status
	void setStatus(std::string status);

	//Adds new line(s) to the posts
	void addLineToPosts(std::string new_line);
private:
	//fields
	std::string _status;
	std::string _posts;
};
