#pragma once
#include <fstream>
#include <string>
#include <vector>

#include "InputDebug.h"

inline std::vector<std::vector<int>> StoreDataAsNestedVector()
{
	std::ifstream in;
	std::string s;
	const std::string path = DayIntoPath("1");

	in.open(path);

	std::vector<std::vector<int>> output;
	std::vector<int> temp;

	while (!in.eof())
	{
		std::getline(in, s);

		if (s.empty())
		{
			output.push_back(temp);
			temp.clear();
			continue;
		}

		int lineValue = IntFromString(s);

		temp.push_back(lineValue);
	}

	in.close();

	return output;
}
