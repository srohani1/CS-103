 1: #include <iostream>
 2: #include <cstring>
 3:
 4: using namespace std;
 5:
 6: int main()
 7: {
 8:    char mystring[80] = "ComputerScience";
 9:    char yourstring[80];
10:    char* astring;
11:
12:    yourstring = mystring;
13:    strncpy(astring, mystring, 80);
14:
15:    astring = mystring;
16:    strncpy(yourstring, mystring, 80);  // make a copy?
17:    cout << astring << endl;
18:    cout << yourstring << endl;
19:
20:    mystring[0] = '*'; // which one actually made a copy?
21:    cout << astring << endl;
22:    cout << yourstring << endl;
23:
24:    return 0;
25: }