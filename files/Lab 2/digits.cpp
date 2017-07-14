#include <iostream>
using namespace std;
int main()
{
int input;
int onesdigit;
int tensdigit;
int hundredsdigit;
cout << "Enter an integer between 0 and 999: ";
cin >> input;
onesdigit = input % 10;
input = input/10;
tensdigit = input % 10;
input = input/10;
hundredsdigit = input % 10; 
cout << onesdigit << endl;
cout << tensdigit << endl;
cout << hundredsdigit << endl;
}

