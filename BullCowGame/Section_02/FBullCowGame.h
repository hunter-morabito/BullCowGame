#pragma once
#include <string>

class FBullCowGame {
// methods are public
public:
	FBullCowGame(); // constructor

					// 'TODO' is the accpted format for C++/VS
	void Reset();	// TODO make a more rich return value
	// const prevents this method from changing any of the variables in this class!
	int GetMaxTries() const; 
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string);

private:
	// variables are private
	// these are created at compile time
	int MyCurrentTry;
	int MyMaxTries;
};

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();