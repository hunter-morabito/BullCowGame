#include "main.h"

// entry point
int main() 
{
	PrintIntro();
	PlayGame();
	
	cout << endl;
	return 0;
}

void PrintIntro()
{
	// introduce the game
	constexpr int WORD_LENGTH = 5;

	cout << "Welcome to Bulls and Cows" << endl;
	cout << "Try and guess the " << WORD_LENGTH;
	cout << " letter isogram I'm thinking of." << endl;
}

void PlayGame()
{
	// loop for the number of turns asking for guesses
	constexpr int NUMBER_OF_GUESSES = 5;
	for (int i = 0; i < NUMBER_OF_GUESSES; i++)
	{
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << endl;
	}
}

string GetGuess() 
{
	string Guess;
	cout << "Enter your guess: ";
	// get a guess from the player
	getline(cin, Guess);
	return Guess;
}