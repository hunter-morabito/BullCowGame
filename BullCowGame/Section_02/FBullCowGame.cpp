#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRY = 8;
	MyMaxTries = MAX_TRY;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	
	return;
}

int32 FBullCowGame::GetMaxTries() const{ return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon()
{
	return 0;
}

EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
	return EWordStatus::OK;
}

// receives a VALID guess, incriments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();
	// loop throuhg all letters in the guess
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		// compare letter against the hidden word
		for (int32 j = 0; j < HiddenWordLength; j++) 
		{
			if ((MyHiddenWord[i] | ' ') == (Guess[j] | ' ')) 
			{
				if (i == j)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
		// incriment bulls if they're in the same place
		// increment cows if not
	}
	return BullCowCount;
}
