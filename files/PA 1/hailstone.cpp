//Alec Lord
//alord@usc.edu
//This is hailstone. It runs the hailstone procedure on a number
# include <iostream>
# include <cmath>
using namespace std;
int main()
{
	int usernum;
	int lengthcount = 0;
	cout << "Enter a number: " << endl;
	cin >> usernum;
	// hailstone conjecture is complete once we hit 1
	while (usernum != 1)
	{
		// even
		if (usernum % 2 == 0)
		{
			usernum = usernum/2;
			lengthcount = lengthcount + 1;
			cout << usernum << " ";
		}
		// odd
		else 
		{
			usernum = usernum * 3 + 1;
			lengthcount = lengthcount + 1;
			cout << usernum << " ";
		}
	}
	cout << endl;
	cout << "Length: " << lengthcount << endl;
}
