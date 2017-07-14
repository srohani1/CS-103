#include <iostream>
#include <string>

using namespace std;

void license(string plate)
{
	if (plate.size() == 7)
	{
		cout << plate << endl;
	}
	else
	{
		if(plate.size() == 0)
		{
			for (int i = '1'; i <= '9'; i++)
			{
				plate.push_back(i);
				license(plate);
				plate.pop_back();
			}
		}
		else if(plate.size() >=1 && plate.size( <= 3))
		{
			for (char i = 'A'; i <= 'z'; i++)
				{
					plate.push_back(i);
					license(plate);
					plate.pop_back();
					
				}
		}
	}
}
