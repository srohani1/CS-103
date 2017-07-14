#include "network.h"
#include "user.h"
#include <iomanip>
int main(int argc, char *argv[])
{
  Network net;
  int input = 0;
  net.read_friends(argv[1]);
  while(true)
  {	
    cout << "Option 1: Add User" << endl;
    cout << "Option 2: Add friend connection" << endl;
    cout << "Option 3: Remove friend connection" << endl;
    cout << "Option 4: Print users" << endl;
    cout << "Option 5: List friends" << endl;
    cout << "Option 6: Write to file" << endl;
    cout << "Option 7: Shortest path" << endl;
    cout << "Option 8: Disjoint sets" << endl;
    cout << "Option 9: Friend suggestions" << endl;
    cout << "Press any other key to exit" << endl;
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
      else if (input == 7)
      {
        string firstname1;
        string firstname2;
        string lastname1;
        string lastname2;
        string name1;
        string name2;
        int from;
        int to;
        cin >> firstname1 >> lastname1 >> firstname2 >> lastname2;
        name1 = firstname1 + " " + lastname1;
        name2 = firstname2 + " " + lastname2;
        if (!(name1.compare(name2)))
        {
          cout << "Distance: 0" << endl;
          cout << name1 << endl;
        }
        else 
        {
          from = net.get_id(name1);
          to = net.get_id(name2);
          vector <int> tempVector = net.shortest_path(from,to);
          if (tempVector.size() == 0)
          {
            cout << "None" << endl;
          }
          else
          {
            cout << "Distance: " << tempVector.size() << endl;
            for (int i = 0; i < tempVector.size();i++)
            {
              if (i < tempVector.size() -1)
              {
                User* newUser = net.getUser(tempVector[i]);
                cout << newUser->getName() << " -> ";
              }
              else 
              {
                User* newUser = net.getUser(tempVector[i]);
                cout << newUser->getName();
              }
            }
            cout << endl;
          }
        }
      }
      else if (input == 8)
      {
        vector<vector<int> > groups = net.groups();
        for (int i = 0; i < groups.size();i++)
        {
          cout << "Set " << i << " => ";
          for (int j = 0; j < groups[i].size();j++)
          {
            cout << net.getUser(groups[i][j])->getName() << ", ";
          }
          cout << endl;
        }
      }
      else if (input == 9)
      {
        string firstname;
        string lastname;
        string name;
        cin >> firstname >> lastname;
        name = firstname + " " + lastname;
        int who = net.get_id(name);
        int score;
        vector <int> outVector = net.suggest_friends(who,score);
        if (score == -1)
        {
          cout << "None" << endl;
        }
        cout << "The suggested friends is/are: " << endl;
        for (int i = 0; i < outVector.size();i++)
        {
          cout << (net.getUser(outVector[i]))->getName() << '\t' << "Score: "; 
          cout << net.getUser(outVector[i])->score << endl;
        }
      }
      else
      {
        break;
      }
  }
  return 0;
}
