#include "network.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <queue>
#include <deque>
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
void Network::bfs(int from)
{
	for (int i = 0; i < users.size();i++)
	{
		users[i].depth = -1;
		users[i].predecessor = -1;
	}
	User* user1 = getUser(from);
	queue<User*> to_visit;
	to_visit.push(user1);
	user1->depth = 0;
	while (!to_visit.empty())
	{
		//get front
		user1 = to_visit.front();
		vector <int> friends = (*user1).getFriends();
    	for (int i = 0; i < friends.size(); i++)
    	{
    		if(getUser(friends[i])->depth == -1)
    		{
    			(getUser(friends[i]))->depth = (*user1).depth + 1;
    			(getUser(friends[i]))->predecessor = user1->getID();
    			to_visit.push(getUser(friends[i]));
    		}
    	}
    	to_visit.pop();
	}
}			
vector<int> Network::shortest_path(int from, int to)
{
	bfs(from);
	User* user2 = getUser(to);
	deque<int> predecessorReturn; 
	vector<int> tempVector;
	if (from == to)
	{
		tempVector.push_back(from);
		return tempVector;
	}
	if (user2->predecessor != -1)
	{
		predecessorReturn.push_front(user2->getID());
		while (user2->predecessor != -1)
		{
			User* uPredecessor = getUser(user2->predecessor);
			predecessorReturn.push_front(uPredecessor->getID());
			user2 = uPredecessor;
		}
		for (int i = 0; i < predecessorReturn.size();i++)
		{
			tempVector.push_back(predecessorReturn[i]);
		}
	}	
	for (int i = 0; i < users.size();i++)
	{
		users[i].depth = -1;
		users[i].predecessor = -1;
	}	
	return tempVector;
}
vector<vector<int> > Network::groups()
{
	vector<vector<int> > groups;
	vector<bool> visited;
	for(int i=0;i<users.size() ;i++) 
	{
		visited.push_back(false);
	}
	for(int i = 0; i  < users.size();i++) 
	{ 
		vector<int> group;
		if( !visited[i] && users[i].depth == -1) 
		{
			bfs(users[i].getID());
			visited[i] = true;
			for (int j = 0; j < users.size();j++)
			{
				if(users[j].depth != -1) {
				  group.push_back(users[j].getID());
				  visited[j] = true;
			    }
			}
			groups.push_back(group);
		}
	}
	for (int i = 0; i < users.size();i++)
	{
		users[i].depth = -1;
		users[i].predecessor = -1;
	}
	return groups;	
}
vector<int> Network::suggest_friends(int who, int& score)
{
	int max = -1;
	// set score to 0 by default
	for (int i = 0; i < users.size();i++)
	{
		users[i].score = 0;
	}
	vector <int> friendsSuggestions;
	User* newUser = getUser(who);
	// find friends depth 2 away and save them in a vector
	bfs(who);
	for (int i = 0; i < users.size();i++)
	{
		if( users[i].depth == 2)
		{
			friendsSuggestions.push_back(users[i].getID());

		}
	}
	// caluclate scores
	vector <int> whoFriends;
	whoFriends = newUser->getFriends();
	for (int i = 0; i < friendsSuggestions.size();i++)
	{
		vector <int> friends = getUser(friendsSuggestions[i])->getFriends();

		for (int j = 0; j < friends.size();j++)
		{
			for(int k = 0; k < whoFriends.size();k++)
			{
				if (friends[j] == whoFriends[k])
				{
					getUser(friendsSuggestions[i])->score += 1;
				}
			}
		}
		if (getUser(friendsSuggestions[i])->score > max)
		{ 
			max = getUser(friendsSuggestions[i])->score;
		}	
	}
	score = max;
	vector <int> friendsSuggestions2;
	// save suggested friends with highest score in a vector
	for (int i = 0; i < friendsSuggestions.size();i++)
	{
		if (getUser(friendsSuggestions[i])->score == max)
		{
			friendsSuggestions2.push_back(friendsSuggestions[i]);
		}
	}
	for (int i = 0; i < users.size();i++)
	{
		users[i].depth = -1;
		users[i].predecessor = -1;
	}
	return friendsSuggestions2;
}
