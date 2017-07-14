# include <iostream>
# include <cmath>
using namespace std;
int main()
{
	double usertheta;
	double lengthsidex;
	cout << "Enter a value for theta between 15 and 75 degrees" << endl;
	cin >> usertheta; 
	usertheta = (usertheta * M_PI)/180;
	for (int i = 1; i <= 31; i++)
	{
		lengthsidex = i * tan(usertheta);
		if (lengthsidex >= 20 && lengthsidex <= 30)
		{
			lengthsidex = 20; 
		}
		for (int j = 1; j <= lengthsidex; j++)
		{
			cout << "*";	
		}
	cout << endl;	
	}
}
