#include "user.h"
User::User(int _ID, string _firstName, string _lastName,int _birthDay,int _zipCode)
{
	this->ID = _ID;
	this->firstName = _firstName;
	this->lastName = _lastName;
	this->birthDay = _birthDay;
	this->zipCode  = _zipCode;
	depth = -1;
	predecessor = -1;

}
User::~User()
{
	
}
void User::add_friend(int _ID)
{
	friends.push_back(_ID);
}
void User::delete_friend(int _ID)
{
	for (int i = 0; i < friends.size(); i++)
	{
		if (friends[i] == _ID)
		{
			friends.erase(i + friends.begin());
			break;
		}
	}
}
int User::getID()
{
	return ID;
}
int User::getbirthDay()
{
	return birthDay;
}
int User::getZipCode()
{
	return zipCode;
}
string User::getName()
{
	return firstName + " " + lastName;
}
vector<int>& User::getFriends()
{
	return friends;
}
