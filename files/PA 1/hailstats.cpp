// Alec Lord
// alord@usc.edu
// This is hailstats. It runs hailstone on a range of numbers.
# include <iostream>
# include <cmath>
# include <limits.h>
using namespace std;
int main()
{
	// smaller of the two input numbers
	int usernummin;
	// larger of the two input numbers
	int usernummax;
	// keeps track of the length of the minimum number
	int minlengthcount = INT_MAX;
	// keeps track of the smallest number in the user range
	int minnum = 0;
	// keeps track of the length of the maximum number
	int maxlengthcount = 0;
	// keeps track of the biggest number in the user range
	int maxnum = 0;
	cout << "Enter the range you want to search: " << endl;
	cin >> usernummin >> usernummax;
	if (usernummin <= usernummax)
	{	
		for (int i = usernummin; i <= usernummax; i++)
		{	
			int currentnum = i;
			int lengthcount = 0;
			// once we get to 1 the hailstone conjecture is complete
			while (currentnum != 1)
			{
				// even
				if (currentnum % 2 == 0)
				{
					currentnum = currentnum/2;
					lengthcount = lengthcount + 1;
				}
				//odd
				else 
				{
					currentnum = currentnum * 3 + 1;
					lengthcount = lengthcount + 1;
				}
			}
			if (lengthcount < minlengthcount)
			{
				minnum = i;
				minlengthcount = lengthcount;
			}
			if (lengthcount > maxlengthcount)
			{
				maxnum = i;
				maxlengthcount = lengthcount;
			}
		}	
			cout << endl;
			cout << "Minimum Length: " << minlengthcount << endl;
			cout << "Achieved by: " << minnum << endl;
			cout << "Maximum Length: " << maxlengthcount << endl;
			cout << "Achieved by: " << maxnum << endl;		
	}
	else 
	{
	cout << "Invalid range" << endl;
	}
}
