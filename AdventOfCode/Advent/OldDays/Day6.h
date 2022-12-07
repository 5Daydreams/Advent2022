#pragma once

#include <string>
#include <vector>

#include "../InputDebug.h"


inline bool TestForDifferentChars(std::string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = i + 1; j < str.length(); j++)
		{
			if (str[i] == str[j])
			{
				return false;
			}
		}
	}

	return true;
}

inline void RunDay6()
{
	std::string receivedCode = StoreDataAsString(6);

	int sizeOfMarker = 14;

	int targetIndex = -1;

	for (int i = sizeOfMarker; receivedCode[i] != NULL; i++)
	{
		std::string test = receivedCode.substr(i - sizeOfMarker, sizeOfMarker);

		if (TestForDifferentChars(test))
		{
			targetIndex = i;
			break;
		}
	}

	std::cout << "Found 4 different chars right before index number: " << targetIndex << std::endl;
}