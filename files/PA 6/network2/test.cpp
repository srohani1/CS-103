# include <iostream>
# include <string>
# include <sstream>
# include <fstream>
# include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	ifstream.input(argv[1]);
	if(input.fail())
	{
		cout << "Unable to open input file..." << endl;
		return -1;
	}
	string t;
	getline(input t);
	stringstream st(t);
	int num_users;
	st >> num_users;
	cout << "This data file shoul have " << num_users << " records." << endl;
	for(int i = 0; i < num_users; i++)
	{
		int id, year, zip;
		string first, last;
		vector<int> v;
		for (int k = 0; k < 5; k++)
		{
			string line;
			getline(input,line);
			stringstream ss(line);
			cout << ss.str() << endl;
			if (k==0)
			{
				ss >> id;
			}
			if (k==1)
			{
				ss >> first,last;
			}
			if (k==2)
			{
				ss >> year;
			}
			if (k==3)
			{
				ss >> zip;
			}
			if (k==4)
			{
				int t;
				while(ss >> t)
				{
					v.push_back(t);
				}
			}
		}
		cout << "The user with id: " << id;
		cout << " is named " << first << " " << last;
		cout << ", was born in " << year;
		cout << " and lives in " << zip;
		cout << " with " << v.size() << " friends." << endl;
	}
	return 0;
}
