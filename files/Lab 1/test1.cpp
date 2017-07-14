#include <iostream>
using namespace std;

int main() {
   int x, y, z;
   cin >> x >> y >> z;

   bool isDecreasing = (x > y) &&    (y > z) ;
   bool isIncreasing =  (x < y) && (y < z) ;

   bool isOrdered = isIncreasing    or  isDecreasing;

   // print out result, true or false   
   cout << boolalpha << isOrdered;
   return 0;
}
