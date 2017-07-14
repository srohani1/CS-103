#ifndef USER_H
#define USER_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class User 
{
 public:
 	User(int , string , string , int , int );
 	~User();
 	void add_friend(int ID);
 	void delete_friend(int ID);
 	int getID();
 	int getbirthDay();
 	int getZipCode();
 	string getName();
 	vector<int>& getFriends();
 private:
 	int ID;
 	string firstName;
 	string lastName;
 	int birthDay;
 	int zipCode;
 	vector<int> friends;
};
#endif
