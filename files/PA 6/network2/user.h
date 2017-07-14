#ifndef USER_H
#define USER_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class User 
{
 public:
 	User(int ID, string firstName, string lastName,int birthDay,int zipCode);
 	~User();
 	void add_friend(int ID);
 	void delete_friend(int ID);
 	int getID();
 	int getbirthDay();
 	int getZipCode();
 	string getName();
 	vector<int>& getFriends();
 	int depth;
 	int predecessor;
 	int score;
 private:
 	int ID;
 	string firstName;
 	string lastName;
 	int birthDay;
 	int zipCode;
 	vector<int> friends;
};
#endif
