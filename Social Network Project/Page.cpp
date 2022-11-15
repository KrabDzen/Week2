#include "Page.h"

/*
* Creates a new page with blank status and profile
* Input: *NONE*
* Output: *NONE*
*/
void Page::init()
{
	_status = "";
	_posts = "";
}
/*
* Function returns the posts of the page
* Input: *NONE*
* Output: Page's posts
*/
std::string Page::getPosts() const
{
	return _posts;
}
/*
* Function returns the status of the page
* Input: *NONE*
* Output: Status posted on the page
*/
std::string Page::getStatus() const
{
	return _status;
}
/*
* Function clears the posts of the page
* Input: *NONE*
* Output: *NONE*
*/
void Page::clearPage()
{
	_posts = "";
}
/*
* Function changes the current status to given status
* Input: new status to post
* Output: *NONE*
*/
void Page::setStatus(std::string status)
{
	_status = status;
}
/*
* Function adds a new line to the posts
* Input: a line to post
* Output: *NONE*
*/
void Page::addLineToPosts(std::string new_line)
{
	_posts += "\n" + new_line;
}
