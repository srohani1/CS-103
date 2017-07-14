# include <iostream>
using namespace std;
int main()
{
	int userint;
	int twoscount = 0;
	int threescount = 0;
	cout << "Enter a positive integer: "<< endl;
	cin >> userint;
	while (userint % 2 == 0 || userint % 3 == 0)
	{
			if (userint % 2 == 0)
		{
			twoscount = twoscount + 1;
			userint = userint/2;
		}
		if (userint % 3 == 0)
		{	
			threescount = threescount + 1;
			userint = userint/3;
		}
	}
	if (userint > 1)
		{
		cout << "No" << endl;
		}
	else 
		{
			cout << "Yes" << endl;
			cout << "Twos=" << twoscount << "  Threes=" << threescount << endl;
		}
}
