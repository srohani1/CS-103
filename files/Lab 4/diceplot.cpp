// Alec Lord
// alord@usc.edu
#include <iostream>
#include <cstdlib>
using namespace std;

int roll()
{
	return rand() % 6 + 1; 
}

void printHistogram(int counts[]) 
{
	for (int i = 4; i <= 24; i++)
		{
			cout << i << ":";
			
			for (int j = 1; j <= counts[i] ; j++)
			{
				cout << "X";
			}
			cout << endl;	
		}
}
int main()
{
srand(time(NULL));
int n;
cout << "Enter the number of times you want to roll" << endl;
cin >> n;
int numarray[25] = {0};
for (int i=0; i<n; i++)
{
	int rollsum = roll() + roll() + roll() + roll();
	numarray[rollsum] += 1;
}
printHistogram(numarray);
}
