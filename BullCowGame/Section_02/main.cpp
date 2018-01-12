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
	do 
	{
		PlayGame();
	}while(AskToPlayAgain());
	
	std::cout << std::endl;
	return 0;
}

void PrintIntro()
{
	// introduce the game
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Try and guess the " << BCGame.GetHiddenWordLength();;
	std::cout << " letter isogram I'm thinking of." << std::endl;
}

void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	for (int32 i = 0; i < MaxTries; i++)
	{
		FText Guess = GetGuess(); // TODO make loop checking valid

		// submit valid guess to game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
		std::cout << "Cows = " << BullCowCount.Bulls << std::endl;
		std::cout << "Your guess was: " << Guess << std::endl;
	}
}

FText GetGuess() 
{
	int32 CurrentTry = BCGame.GetCurrentTry();

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