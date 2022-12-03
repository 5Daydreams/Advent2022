#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include <vector>

inline std::string DayIntoPath(const std::string& id)
{
	const std::string start = "Puzzle_Input/Day";
	const std::string end = ".txt";

	return start + id + end;
}

inline std::string PrintFullFile(const std::string id)
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

	std::cout << raw_data;

	in.close();

	return raw_data;
}

inline std::string PrintFullFile(const int id)
{
	std::string idString = std::to_string(id);
	return PrintFullFile(idString);
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

inline std::vector<std::string> StoreDataAsStringVector(std::string dayNumber)
{
	std::ifstream in;
	std::string temp;
	const std::string path = DayIntoPath(dayNumber);

	in.open(path);

	std::vector<std::string> output;

	while (!in.eof())
	{
		std::getline(in, temp);
		output.push_back(temp);
	}

	in.close();

	return output;
}

inline std::vector<std::string> StoreDataAsStringVector(int dayNumber)
{
	std::string dayString = std::to_string(dayNumber);
	return StoreDataAsStringVector(dayString);
}