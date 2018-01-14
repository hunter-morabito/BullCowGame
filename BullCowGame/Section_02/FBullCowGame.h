#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount 
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame 
{
// methods are public
public:
	FBullCowGame(); // constructor
	void Reset();	// TODO make a more rich return value

	// 'TODO' is the accpted format for C++/VS
	// const prevents this method from changing any of the variables in this class!
	int32 GetMaxTries() const; 
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon()const;
	EGuessStatus CheckGuessValidity(FString) const;


	// counts bulls and cows, and increases the try #, assuming valid guess
	FBullCowCount SubmitValidGuess(FString);


private:
	// variables are private
	// these are created at compile time
	int32 MyCurrentTry;
	int32 MyMaxTries;
	FString MyHiddenWord;
	bool bGameWon;
};