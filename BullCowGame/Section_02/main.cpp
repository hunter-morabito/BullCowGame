/* This is the console executable, that makes use of  the BullCow class
This acts as the view in a MVS pattern, and is responsible for all 
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include "FBullCowGame.h"

using FText = std::string;

FBullCowGame BCGame; // instantiate a new game

// entry point
int main() 
{
	PrintIntro();
	
	// play the game at least once
	do {
		PlayGame();
	}while(AskToPlayAgain());
	
	std::cout << std::endl;
	return 0;
}

void PrintIntro()
{
	// introduce the game
	constexpr int WORD_LENGTH = 5;

	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Try and guess the " << WORD_LENGTH;
	std::cout << " letter isogram I'm thinking of." << std::endl;
}

void PlayGame()
{
	int MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	constexpr int MaxTries = 5;
	for (int i = 0; i < MaxTries; i++)
	{
		FText Guess = GetGuess(); // TODO make loop checking valid
		std::cout << "Your guess was: " << Guess << std::endl;
	}
}

FText GetGuess() 
{
	int CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	// get a guess from the player
	FText Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again?";
	FText Response = "";
	std::getline(std::cin, Response);
	return ((Response[0] | ' ') == 'y');
}