#include "network.h"
#include <fstream>
#include <sstream>
#include <iostream>
Network::Network()
{
	numUsersNet = 0;
}
Network::~Network()
{

}
int Network::read_friends(const char *filename)
{
	ifstream myfile;
 	myfile.open(filename);
	if (myfile.fail())
	{
		cout << "File failed to open" << endl;
		return -1;
	}
	int numUsers;
	myfile >> numUsers;
	numUsersNet = numUsers;
	int ID;
	int zipCode;
	int birthDay;
	string firstName;
	string lastName;
	string name;
	string friends;
	int buff;
	vector <string> newFriends;
	string temp;
	getline(myfile,temp);
	for (int i = 0; i < numUsers;i++)
	{
		myfile >> ID;
		getline(myfile, temp);
		getline(myfile,name);
		stringstream ss;
		ss << name;
		ss >> firstName >> lastName;
		myfile >> birthDay;
		getline(myfile,temp);
		myfile >> zipCode;
		getline(myfile,temp);

		getline(myfile,friends);
		stringstream ss1;
		User newUser = User(ID, firstName, lastName, birthDay, zipCode);

		ss1 << friends;
		while (ss1 >> buff)
		{
			newUser.add_friend(buff);
		}
		users.push_back(newUser);
	}
	myfile.close();
	return 0;
}
int Network::write_friends(const char *filename)
{
	ofstream myfile;
 	myfile.open(filename);
	if (myfile.fail())
	{
		cout << "Failed to open file" << endl;
		return -1;
	}
	myfile << users.size() << endl;
	for (int i = 0; i < users.size(); i++)
	{
		myfile << users[i].getID() << endl;
		myfile << '\t' << users[i].getName() << endl;
		myfile << '\t' << users[i].getbirthDay() << endl;
		myfile << '\t' << users[i].getZipCode() << endl;
		string temp;
		vector <int> friends = users[i].getFriends();		
		for (int j = 0; j < friends.size();j++)
		{
			stringstream ss;
			ss << friends[j];
			temp += ss.str();
			temp += " ";
		}	
		myfile << '\t' << temp << endl;
	}
	myfile.close();
	return 0;
}
void Network::add_user(User newUser)
{
	users.push_back(newUser);
	numUsersNet += 1;
}
int Network::add_connection(std::string name1, std::string name2)
{
	int index1 = -1;
	int index2 = -1;
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].getName() == name1)
		{
			index1 = i;
		}
		else if (users[i].getName() == name2)
		{
			index2 = i;
		}
	}
	if (index1 == -1 || index2 == -1)
	{
		cout << "Invalid user" << endl;
			return -1;
	}
	users[index1].add_friend(users[index2].getID());
	users[index2].add_friend(users[index1].getID());
	return 0;
} 
int Network::remove_connection(std::string name1, std::string name2)
{
	int index1 = -1;
	int index2 = -1;
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].getName() == name1)
		{
			index1 = i;
		}
		else if (users[i].getName() == name2)
		{
			index2 = i;
		}
	}
	if (index1 == -1 || index2 == -1)
	{
		cout << "Invalid user" << endl;
			return -1;
	}
	users[index1].delete_friend(users[index2].getID());
	users[index2].delete_friend(users[index1].getID());
	return 0;
}
int Network::get_id(std::string username)
{
 for(int i = 0; i < users.size();i++)
 {
 	
 	
	if (!(username.compare(users[i].getName())))
 	{
 		return users[i].getID();
 	}
 }		
 return -1;
} 	
int Network::get_numUsersNet()
{
	return numUsersNet;
}
vector<User>& Network::getUsers()
{	
	return users;
}
User* Network::getUser(std::string username)
{
	for(int i = 0; i < users.size(); i++)
	{
		if(users[i].getName() == username)
		{
			return &users[i];
		}

	}
	return NULL;
}
User* Network::getUser(int id)
{
	for(int i = 0; i < users.size(); i++)
	{
		if(users[i].getID() == id) 
		{
			return &users[i];
		}

	}
	return NULL;
}