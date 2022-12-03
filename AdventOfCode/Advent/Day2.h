#pragma once
#include <fstream>
#include <string>
#include <vector>

#include "InputDebug.h"

inline int CalculateRoundVictory(const char opponentChoice, const char playerChoice)
{
	if (opponentChoice == playerChoice)
	{
		return 3;
	}

	if (opponentChoice == 'A')
	{
		if (playerChoice == 'Y')
		{
			return 6;
		}

		if (playerChoice == 'Z')
		{
			return 0;
		}
	}

	if (opponentChoice == 'B')
	{
		if (playerChoice == 'Z')
		{
			return 6;
		}

		if (playerChoice == 'X')
		{
			return 0;
		}
	}

	if (opponentChoice == 'C')
	{
		if (playerChoice == 'X')
		{
			return 6;
		}

		if (playerChoice == 'Y')
		{
			return 0;
		}
	}

	return 3;
}

inline int RoundScore(const std::string roundData, const bool debug = false)
{
	const char playerChoice = roundData.back();
	const int playerScore = playerChoice - 'W';

	const char opponentChoice = roundData.front();

	int result = CalculateRoundVictory(opponentChoice, playerChoice) + playerScore;

	if (debug)
	{
		std::cout << "For the round: " << roundData << std::endl;
		std::cout << "The result is " << result << std::endl;
	}
	return result;

	/*
	 The score for a single round is the score for the shape you selected (1 for Rock, 2 for Paper, and 3 for Scissors)
	 plus the score for the outcome of the round (0 if you lost, 3 if the round was a draw, and 6 if you won).
	 */
}

inline int DecidePlayerScore(const char opponentChoice, const char desiredRoundResult)
{
	switch (opponentChoice)
	{
	case 'A': // enemy == rock
		switch (desiredRoundResult)
		{
		case 'X':
			return 3;
			break;
		case 'Y':
			return 1;
			break;
		case 'Z':
			return 2;
			break;
		}
		break;
	case 'B': // enemy == paper
		switch (desiredRoundResult)
		{
		case 'X':
			return 1;
			break;
		case 'Y':
			return 2;
			break;
		case 'Z':
			return 3;
			break;
		}
		break;
	case 'C': // enemy == scissors
		switch (desiredRoundResult)
		{
		case 'X':
			return 2;
			break;
		case 'Y':
			return 3;
			break;
		case 'Z':
			return 1;
			break;
		}
		break;
	}
}

inline int NewRoundScore(const std::string roundData, const bool debug = false)
{
	const char desiredResult = roundData.back();
	const int roundResult = (desiredResult - 'X') * 3;

	const char opponentChoice = roundData.front();

	int playerScore = DecidePlayerScore(opponentChoice, desiredResult);

	int result = playerScore + roundResult;

	if (debug)
	{
		std::cout << "For the round: " << roundData << std::endl;
		std::cout << "The result is " << result << std::endl;
	}

	return result;
}

inline int CalcAllRounds(std::vector<std::string> allRoundData)
{
	int roundTotals = 0;

	for (int i = 0; i < allRoundData.size(); i++)
	{
		std::string currLine = allRoundData[i];

		roundTotals += RoundScore(currLine);
	}

	return roundTotals;
}

inline int CalcNewRoundsResult(std::vector<std::string> allRoundData)
{
	int roundTotals = 0;

	for (int i = 0; i < allRoundData.size(); i++)
	{
		std::string currLine = allRoundData[i];

		roundTotals += NewRoundScore(currLine);
	}

	return roundTotals;
}

