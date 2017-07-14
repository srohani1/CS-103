#include <string>
#include <vector>

// importing a whole namespace in a header is frowned upon
// this will at least let us write 'string'/'vector' below
using std::string;
using std::vector;

class BigInt {
   public:
      BigInt(string s);   // convert string to BigInt
      BigInt(string s, int base1);
      string to_string(); // get string representation
      void add(BigInt b); // add another BigInt to this one
      int size();
      int get(int i);
      string message;
   private:
      vector <int> myVector; 
      string myString;
      //string message;
      int base;
};
