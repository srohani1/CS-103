#include "network.h"
#include "user.h"
#include <iomanip>
int main(int argc, char *argv[])
{
	Network net;
	int input = 0;
	net.read_friends(argv[1]);
	while(input != 7)
	{	
		cout << "Option 1: Add User" << endl;
  		cout << "Option 2: Add friend connection" << endl;
  		cout << "Option 3: Remove friend connection" << endl;
  		cout << "Option 4: Print users" << endl;
  		cout << "Option 5: List friends" << endl;
  		cout << "Option 6: Write to file" << endl;
 		cout << "Option 7: Exit the program" << endl;
  		cin >> input;
  		if (input == 1)
  		{
  			string firstName;
  			string lastName;
  			int birthDay;
  			int zipCode;
  			int ID = net.get_numUsersNet();
  			cin >> firstName >> lastName >> birthDay >> zipCode;
  			User newUser = User(ID, firstName, lastName, birthDay, zipCode);
  			net.add_user(newUser);
  		}
  		else if (input == 2)
  		{
  			string firstName1;
  			string lastName1;
  			string firstName2;
  			string lastName2;
  			string name1;
  			string name2;
  			cin >> firstName1 >> lastName1 >> firstName2 >> lastName2;
  			name1 = firstName1 + " "  + lastName1;
  			name2 = firstName2 + " " + lastName2;
  			net.add_connection(name1, name2);
  		}
  		else if (input == 3)
  		{
  			string firstName1;
  			string lastName1;
  			string firstName2;
  			string lastName2;
  			string name1;
  			string name2;
  			cin >> firstName1 >> lastName1 >> firstName2 >> lastName2;
  			name1 = firstName1 + " "  + lastName1;
  			name2 = firstName2 + " " + lastName2;
  			net.remove_connection(name1, name2);
  		}
  		else if (input == 4)
  		{
  			cout << setw(5) << left;
  			cout << "ID";
  			cout << setw(20) << left;
  			cout << "Name";
  			cout << setw(10) << left;
  			cout << "Year";
  			cout << setw(10) << left;
  			cout << "Zip" << endl;
  			vector<User> users = net.getUsers();
  			for (int i = 0; i < users.size(); i++)
  			{
  				cout << setw(5) << left << users[i].getID() << setw(20) << left; 
  				cout << users[i].getName(); 
  				cout << setw(10) << left << users[i].getbirthDay(); 
  				cout << setw(10) << left << users[i].getZipCode() << endl;
  			}
  		}
  		else if (input == 5)
  		{
			string username1;
			string username2;
			string username;
			cin >> username1;
			cin >> username2;
			username = username1 + " " + username2;
 			cout << setw(5) << left;
  			cout << "ID";
  			cout << setw(20) << left;
  			cout << "Name";
  			cout << setw(10) << left;
  			cout << "Year";
  			cout << setw(10) << left;
  			cout << "Zip" << endl;
  			User* newUser = net.getUser(username);
  			if (newUser == NULL)
  			{
  				cout << "Error user does not exist";
  			}
  			else
  			{
  				vector<int> friends = newUser->getFriends();	
  				for (int i = 0; i < friends.size(); i++)
  				{
  					User* f = net.getUser(friends[i]);
  					cout << setw(5) << left << f->getID() << setw(20); 
  					cout << left << f->getName(); 
  					cout << setw(10) << left << f->getbirthDay(); 
  					cout << setw(10) << left << f->getZipCode() << endl;	
  				}
  			}
  		}
  		else if (input == 6)
  		{
  			char filename[500];
  			cin >> filename;
  			net.write_friends(filename);
  		}
  		else
  		{
  			break;
  		}
  	}
  return 0;
}
