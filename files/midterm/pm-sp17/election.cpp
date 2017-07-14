#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
// You may add #includes in this program

using namespace std;

// Stores a state's name and how many
// electoral votes that state has
struct StateElectoralInfo{
  string state;
  int elecVotes;
};

// Complete the following function
//
// This function should search/find the target stateName
//  in an array of StateElectoralInfo structs
//  and return that state's electoral vote number
//
//  state_info  input array of filled in StateElectoralInfo structs
//  len         is the length/size of the state_info array
//  stateName   is the state name you need to find
//
// Return the electoral votes the target state has
// Return -1 if the stateName does not appear in the array

int getStateElecVotes(StateElectoralInfo state_info[], int len, string stateName)
{
  // Add your code here
//for (int i=0; i ;i++)
 // if (stateName ++ 



}


//**************************************
// Do not change these 2 lines and don't
// add any lines between them and main()
//**************************************
#ifndef AUTO_TEST
#define AUTO_TEST
int main(int argc, char* argv[])
{
  //*********************************************************
  // Use these declarations to store the appropriate answers.
  // Our 'couts' at the bottom expect these variables to 
  //  be set correctly by the end of your program.
  //*********************************************************
  string candidate1; // Store candidate 1 last name here
  string candidate2; // Store candidate 2 last name here

  int c1_electoral_votes=0; // Total (all states) candidate 1 electoral  votes
  int c2_electoral_votes=0; // Total (all states) candidate 1 electoral  votes

  int c1_total_votes=0; // Total candidate 1 popular votes from all states
  int c2_total_votes=0; // Total candidate 2 popular votes from all states
  
  string best_c1_state; // State with highest percentage win for candidate1
  string best_c2_state; // State with highest percentage win for candidate2

  double best_c1_percent = 0.0; // Store highest percentage of vote candidate1 
                                //  got in a state
  double best_c2_percent = 0.0; // Store highest percentage of vote candidate2 
                                //  got in a state
  int totalStates;
  ifstream myfile;
  myfile.open(argv[1]);
  myfile >> totalStates;
  
  int N = atoi(argv[1]);
  StateElectoralInfo[i].state = new char[N];
  strcpy(StateElectoralInfo[i].state, myArray);

  for (int i = 0; i < N; i++){
    myfile >> myArray;

  }
  cout << myArray << endl;
  myfile.close();
  ifstream myfile2;
  myfile2.open(argv[1]);
  myfile >> candidate1;
  myfile.open(argv[2]);
  myfile >> candidate2;
  for (int i = 0; i ; i++)
    StateElectoralInfo.elecVotes()
    getStateElecVotes();
    c1_total_votes += c1_total_votes + votes;
    c2_total_votes += c2_total_votes + votes;
    if (i > best_c1_percent){
      c1_total_votes = i
    }
    else if (i > best_c2_percent){
      best_c2_percent = i
    }

    else if (i > best_c1_state){
      best_c1_state = i
    }
    
    else if (i > best_c2_state){
      best_c2_state = i
    }

  if(argc < 3){
    cout << "Not enough command line arguments." << endl;
    cout << "Usage: ./election <electoral college data file> <voting data file>"
	 << endl;
    return -1;
  }

  // cout this message if the program fails to open the electoral file
  const string elecFileErrorMsg = "Electoral college file not found.";
  // cout this message if the program fails to open the voter file
  const string voterFileErrorMsg = "Voter totals file not found.";

  //*********************************************************
  // Write your code below to perform the overall task.
  // Be sure to follow requirements.  Make sure your code
  // produces the appropriate values of the variables we
  // declared above so that the code at the bottom will print
  // out the answers in the correct format.
  //*********************************************************













  
  //**************************************
  // You are DONE!  The code below this point
  //  will use the values in the variables
  //  declared at the top of main to output
  //  the desired statistics to the screen.
  //**************************************
  string winner;
  string loser;
  int w_electoral;
  int l_electoral;
  int w_total;
  int l_total;
  if(c1_electoral_votes > c2_electoral_votes)
    {
      winner = candidate1;
      loser = candidate2;
      w_electoral = c1_electoral_votes;
      l_electoral = c2_electoral_votes;
      w_total = c1_total_votes;
      l_total = c2_total_votes;
    }
  else
    {
      winner = candidate2;
      loser = candidate1;
      l_electoral = c1_electoral_votes;
      w_electoral = c2_electoral_votes;
      l_total = c1_total_votes;
      w_total = c2_total_votes;
    }
  
  cout << winner << " defeated " << loser 
       << " in the electoral college." << endl; 

  cout << "The electoral vote count was " << w_electoral
       << " votes to " << l_electoral << " votes." << endl;
  
  cout << "The popular vote total was " << w_total << " to " << l_total << endl;
  
  cout << winner << "'s best state was " << best_c1_state << " where they won ";
  cout  << 100*best_c1_percent << " percent of the votes" << endl;
  
  cout << loser << "'s best state was " << best_c2_state << " where they won "; 
  cout << 100*best_c2_percent << " percent of the votes" << endl;
  
  return 0;  
}
//****************************************
// Do not change the following line
//****************************************
#endif

//****************************************
// You may add code after this if you like
//****************************************
myfile.close();