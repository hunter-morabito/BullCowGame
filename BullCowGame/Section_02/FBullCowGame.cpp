#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset()
{
	constexpr int MAX_TRY = 8;
	MyMaxTries = MAX_TRY;

	MyCurrentTry = 1;
	
	return;
}

int FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return 0;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return 0;
}
