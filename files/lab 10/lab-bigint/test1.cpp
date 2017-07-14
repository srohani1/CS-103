#include "bigint.h"
#include <iostream>
using namespace std;

int main() {
   /*
	BigInt a("A54");
   BigInt b("");
   b.add(a);    // increase b by a
   cout << b.to_string() << endl; // prints 55
   b.add(a);    // increase b by a
   cout << b.to_string() << endl; // prints 68
	*/
  BigInt first("DADCAFE", 16); // hexadecimal
  BigInt second("AAABEEF", 16);
  first.add(second);
  cout << first.to_string() << endl; // prints 185889ED

}
