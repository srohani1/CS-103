#ifndef NETWORK_H
#define NETWORK_H
#include <string>
#include <vector>
#include "user.h"
using namespace std;
class Network 
{
 public:
  Network();
  ~Network();
  int read_friends(const char *filename);
  int write_friends(const char *filename);
  void add_user(User newUser);
  int add_connection(std::string name1, std::string name2);
  int remove_connection(std::string name1, std::string name2);
  int get_id(std::string username);
  int get_numUsersNet();
  vector<User>& getUsers(); 
  User* getUser(std::string username);
  User* getUser(int id);
  vector<int> shortest_path(int from, int to);
  vector<vector<int> > groups();
  vector<int> suggest_friends(int who, int& score);
  void bfs(int from);
 private:
  vector<User> users;
  int numUsersNet;
 };
#endif
