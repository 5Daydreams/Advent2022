#pragma once

#include <iostream>
#include <string>
#include <fstream>

inline std::string DayIntoPath(const std::string& id)
{
	const std::string start = "Puzzle_Input/Day";
	const std::string end = ".txt";

	return start + id + end;
}

inline std::string PrintFullFile(const std::string id, const bool printOutput = false)
{
	std::ifstream in;
	std::string raw_data;
	std::string s;
	const std::string path = DayIntoPath(id);

	in.open(path);

	while (!in.eof()) {
		std::getline(in, s);
		raw_data += s + "\n";
	}

	if (printOutput)
	{
		std::cout << raw_data;
	}

	in.close();

	return raw_data;
}

inline int IntFromString(const std::string& s)
{
	int output = 0;

	for (unsigned long long i = 0; i < s.length(); i++)
	{
		output *= 10;
		output += static_cast<int>(s[i] - '0');
	}

	return output;
}