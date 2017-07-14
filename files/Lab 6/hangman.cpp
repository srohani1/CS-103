// hangman.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
// Prototype. Defined later
int processGuess(char* word, const char* targetWord, char guess);
// Define an array of strings (since a string is just a char array)
// and since string are just char *'s, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};
const int numWords = 10;
int main()
{
  srand(time(0));
  //char guess;
  //bool wordGuessed = false;
  //int numTurns = 10;
  // Picks a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];
  // a blank array 
  // initialized with *'s and then changed them to the actual letters when the 
  // user guesses the letter
  char word[80];  
  for (int i = 0; i < strlen(targetWord);i++)
  {
  	word[i] = '*';
  }
	word[strlen(targetWord)] = '\0';
	int numcount = 10;
	int guesscount = 0;
	while (numcount > 0)
	{
		char userinput;
		cout << "Current word: " << word << endl;
		cout << numcount << " remain..." << " Enter a letter to guess: " << endl;
		cin >> userinput;
		int ret = processGuess(word, targetWord, userinput);
		guesscount = guesscount + ret;
		if (ret == 0)
		{
			numcount = numcount - 1;
		} 
		if (guesscount == strlen(targetWord))
		{
			break;
		}
	}
	 if (strcmp(targetWord,word) == 0)
	 {
 	  	cout << "The word was: " << targetWord << ". You won!" << endl;
	 }
	 else 
	 {
	 	cout << "Too many turns... You Loose!" << endl;
	 }
  // An individual game continues until a word
  // is guessed correctly or 10 turns have elapsed
  // Print out end of game status
	return 0;
}
// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
	int wordcounter = 0;
	for (int i = 0; i < strlen(targetWord);i++)
	{
		if (guess == targetWord[i])
		{
			word[i] = guess;
			wordcounter = wordcounter + 1;
		}
	}
	return wordcounter;
}
