// scramble.cpp
// Word Scramble guessing game
// Illustrates string library functions, character arrays,
// arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
using namespace std;
// Scramble the letters of this string randomly
void permute(char items[], int len);
int main(int argc, char*argv[]) {
  if (argc < 2){
  	cout << "You did not enter enough command line arguments" << endl;
  }
  ifstream myfile;
  myfile.open(argv[1]);
  int numWords;
  if (myfile.fail()){
  	cout << "Can not open the file" << endl;
  	return 1;
	}
	myfile >> numWords;
  if (myfile.fail()){
  	myfile.close();
  	cout << "Can not read integer from file" << endl;
  	return 1;
  }
  char** WordBank = new char*[numWords];
  char buffer[41];
  for (int i = 0; i <= numWords; i++){
  	myfile >> buffer;
  	WordBank[i] = new char[strlen(buffer)];
  	strcpy(WordBank[i],buffer);
  }
  myfile.close();
  srand(time(0));
  char guess[80];
  bool wordGuessed = false;
  int numTurns = 10;
  // Pick a random word from the WordBank
  int target = rand() % numWords;
  int targetLen = strlen(WordBank[target]);
  // Make a dynamically-allocated copy of the word and scramble it
  char* word = new char[targetLen+1];
  strcpy(word, WordBank[target]);
  permute(word, targetLen);
  // An individual game continues until a word
  // is guessed correctly or 10 turns have elapsed
  while (!wordGuessed && numTurns > 0) {
    cout << "Scrambled word: " << word << endl;
    cout << "What do you guess the original word is? ";
    cin >> guess;
    wordGuessed = (strcmp(guess, WordBank[target]) == 0);
    numTurns--;
  }
  if (wordGuessed) {
    cout << "You win!" << endl;
  }
  else {
    cout << "Too many turns...You lose!" << endl;
  }

  delete [] word;
  for(int i = 0; i < numWords; i++){
  	delete [] WordBank[i]; 
  }
  delete [] WordBank;
  return 0;
}
// Scramble the letters. See "Knuth shuffle" on Wikipedia.
void permute(char items[], int len) {
  for (int i = len-1; i > 0; --i) {
    int r = rand() % i;
    char temp = items[i];
    items[i] = items[r];
    items[r] = temp;
  }
}
