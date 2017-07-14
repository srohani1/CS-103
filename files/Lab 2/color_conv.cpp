#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
   // Enter your code here
   int red, green, blue;
   double cyan, magenta, yellow, black;
   cout << "Enter your values for red, green, and blue" <<  endl;
   cin >> red;
   cin >> green;
   cin >> blue;
   double white = max(max((double)red/255, (double)green/255), (double)blue/255);
   cyan = (white - (double)red/255)/white;
   magenta = (white - (double)green/255)/white;
   yellow = (white-(double)blue/255)/white;
   black = 1 - white;
   cout << cyan << endl;
   cout << magenta << endl;
   cout << yellow << endl;
   cout << black << endl;
   return 0;
}
