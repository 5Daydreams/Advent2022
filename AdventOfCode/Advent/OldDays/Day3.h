#pragma once
#include <string>
#include <vector>

#include "../InputDebug.h"

inline int ConvertIntoPriority(const char itemChar)
{
	if ('a' <= itemChar && itemChar <= 'z')
	{
		return (itemChar - 'a') + 1;
	}

	if ('A' <= itemChar && itemChar <= 'Z')
	{
		return (itemChar - 'A') + 27;
	}

	std::cout << "Error, character not alphabetic, terminating program." << std::endl;

	return -1;
}

inline char FindMistakenChar(std::string compartment1, std::string compartment2)
{
	for (char item1 : compartment1)
	{
		for (char item2 : compartment2)
		{
			if (item1 == item2)
			{
				return item1;
			}
		}
	}

	std::cout << "Error, could not find matching character\n";

	return -1;
}

inline int RucksackPriorityMistake(std::string rucksack)
{
	std::string compartment1 = rucksack.substr(0, rucksack.size() / 2);
	std::string compartment2 = rucksack.substr(rucksack.size() / 2);

	const char mistakenItem = FindMistakenChar(compartment1, compartment2);

	return ConvertIntoPriority(mistakenItem);
}

inline int FindSumOfPriorities(std::vector<std::string> data)
{
	int sumOfPriorities = 0;

	for (std::string element : data)
	{
		int priorityValue = RucksackPriorityMistake(element);
		sumOfPriorities += priorityValue;
	}

	return sumOfPriorities;
}


inline char FindBadgeChar(std::string sack1, std::string sack2, std::string sack3)
{
	for (char item1 : sack1)
	{
		for (char item2 : sack2)
		{
			for (char item3 : sack3)
			{
				if (item1 == item2 && item2 == item3)
				{
					return item1;
				}
			}
		}
	}

	std::cout << "Error, could not find matching character\n";

	return -1;
}

inline int FindBadgeSumOfPriorities(std::vector<std::string> data)
{
	int sumOfPriorities = 0;


	for (int i = 0; i < data.size(); i += 3)
	{
		char badgeChar = FindBadgeChar(data[i], data[i + 1], data[i + 2]);

		int priorityValue = ConvertIntoPriority(badgeChar);
		sumOfPriorities += priorityValue;
	}

	return sumOfPriorities;
}