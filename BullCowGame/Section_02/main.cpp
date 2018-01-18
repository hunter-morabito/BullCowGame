/* This is the console executable, that makes use of  the BullCow class
This acts as the view in a MVS pattern, and is responsible for all
user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include "FBullCowGame.h"

// TODO polish

// function prototypes as outside a class
void PrintIntro();
void PlayGame();
FString GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

using FText = std::string;

FBullCowGame BCGame; // instantiate a new game

// entry point
int main()
{
	PrintIntro();

	// play the game at least once
	do
	{
		BCGame.Reset();
		PlayGame();
	} while (AskToPlayAgain());

	std::cout << std::endl;
	return 0;
}

void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "Try and guess the " << BCGame.GetHiddenWordLength();;
	std::cout << " letter isogram I'm thinking of." << std::endl;
}

// plays a single game to completion
void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();

	// loop while game is NOT won and does not exceed max amount of tries
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		// submit valid guess to game
		FText Guess = GetValidGuess();

		// print
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		if (!BCGame.IsGameWon())
		{
			std::cout << "Bulls = " << BullCowCount.Bulls;
			std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		}
	}
	PrintGameSummary();
	return;
}

// loop until user makes valid guess
FText GetValidGuess()
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";
	
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << " of " << BCGame.GetMaxTries();
		std::cout << ". Enter your guess: ";
		// get a guess from the player
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Not_Lowercase:
			std::cout << "Not Lowercase"<<std::endl;
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Not and Isogram"<<std::endl;
			break;
		case EGuessStatus::Wrong_Length:
			std::cout << "Wrong Word Length"<<std::endl;
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK);// keep looping until we get no errors
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again?";
	FText Response = "";
	std::getline(std::cin, Response);
	return ((Response[0] | ' ') == 'y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "YOU WIN!"<<std::endl;
	}
	else 
	{
		std::cout << "Better luck next time"<<std::endl;
	}
}
