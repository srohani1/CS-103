#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
  int x, y;
  ifstream ifile("num2.txt");
  ifile >> x >> y;
  if(ifile.fail())
  {
  	cout << "Error in input file." << endl;
  	return 1;
  }
cout << "X=" << x << " and Y=" << y << endl;
return 0;
}
