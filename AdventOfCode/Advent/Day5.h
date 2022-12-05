#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <tuple>
#include <vector>

#include "InputDebug.h"


inline void MoveNCratesFromTo(std::vector<std::vector<char>>& crates, const int N, const int from, const int to)
{
	for (int i = 0; i < N; i++)
	{
		auto crateChar = crates.at(from - 1).back();
		crates.at(to - 1).push_back(crateChar);
		crates.at(from - 1).pop_back();
	}
}

inline void MoveNStackFromTo(std::vector<std::vector<char>>& crates, const int N, const int from, const int to)
{
	std::vector<char> temp;
	for (int i = 0; i < N; i++)
	{
		auto crateChar = crates.at(from - 1).back();
		temp.push_back(crateChar);
		crates.at(from - 1).pop_back();
	}

	for (int i = 0; i < N; i++)
	{
		auto crateChar = temp.back();
		crates.at(to - 1).push_back(crateChar);
		temp.pop_back();
	}
}

inline void PerformLineInstruction(std::vector<std::vector<char>>& crates, const std::string instruction, bool part2 = true)
{
	int moveStart = instruction.find(' ', 0) + 1;
	int moveEnd = instruction.find(' ', moveStart);

	std::string moveVal = instruction.substr(moveStart, moveEnd - moveStart);
	int count = stoi(moveVal);

	int fromStart = instruction.find(' ', moveEnd + 4) + 1;
	int fromEnd = instruction.find(' ', fromStart);

	std::string fromVal = instruction.substr(fromStart, fromEnd - fromStart);
	int from = stoi(fromVal);

	int toStart = instruction.find(' ', fromEnd + 2) + 1;
	int toEnd = instruction.find(' ', toStart);

	std::string toVal = instruction.substr(toStart, toEnd - toStart);
	int to = stoi(toVal);

	if (part2)
	{
		MoveNStackFromTo(crates, count, from, to);
	}
	else
	{
		MoveNCratesFromTo(crates, count, from, to);
	}
}

inline std::string StoreDataAsString(int& instructionLineStart)
{
	std::ifstream in;
	std::string raw_data;
	std::string s;
	const std::string path = DayIntoPath(5);

	in.open(path);

	while (!in.eof())
	{
		std::getline(in, s);

		if (s.empty())
		{
			break;
		}

		raw_data += s + "\n";
	}

	in.close();

	return raw_data;
}

inline std::tuple<std::vector<std::string>, std::vector<std::string>> ReadCrateAndInstructionsData()
{
	std::ifstream in;
	std::vector<std::string> crate_data;
	std::vector<std::string> instruction_data;
	bool doneWithCrates = false;
	std::string s;
	const std::string path = DayIntoPath(5);

	in.open(path);

	while (!in.eof()) {
		std::getline(in, s);

		if (s.empty())
		{
			doneWithCrates = true;
			continue;
		}

		if (!doneWithCrates)
		{
			crate_data.push_back(s);
			continue;
		}

		instruction_data.push_back(s);
	}

	in.close();

	return make_tuple(crate_data, instruction_data);
}

inline std::string GetTopmostCrates(std::vector<std::vector<char>>& crates)
{
	std::string result;

	for (int i = 0; i < crates.size(); i++)
	{
		const char topmostCrate = crates.at(i).back();
		result.push_back(topmostCrate);
	}

	return result;
}

inline std::vector<std::vector<char>> PopulateCrates(std::vector<std::string> cratesString)
{
	std::vector<std::vector<char>> result;
	int crates_w = 9;
	int crates_h = 8;

	for (int i = 0; i < crates_w; i++)
	{
		std::vector<char> temp;

		for (int j = 0; j < crates_h; j++)
		{
			const int index = (4 * i) + 1;
			char crateChar = cratesString.at(crates_h - j - 1).at(index);

			if (crateChar == ' ')
			{
				continue;
			}

			temp.push_back(crateChar);
		}

		result.push_back(temp);
	}

	if (false)
	{
		for (auto vector : result)
		{
			for (auto value : vector)
			{
				std::cout << value << ',';
			}
			std::cout << "\n";
		}
	}

	return result;
}


inline void PerformAllInstructions(std::vector<std::vector<char>>& crates, const std::vector<std::string> instructions)
{
	for (int i = 0; i < instructions.size(); i++)
	{
		std::string currInstruction = instructions[i];
		PerformLineInstruction(crates, currInstruction);
	}
}

inline void RunDay5()
{
	bool debug = false;

	std::tuple<std::vector<std::string>, std::vector<std::string>> result = ReadCrateAndInstructionsData();

	std::vector<std::string> crateData = std::get<0>(result);
	std::vector<std::string> instructionData = std::get<1>(result);


	if (false)
	{
		for (std::string line : crateData)
		{
			std::cout << line << std::endl;
		}

		std::cout << '\n';

		for (std::string line : instructionData)
		{
			std::cout << line << std::endl;
		}
	}

	std::vector<std::vector<char>> crates = PopulateCrates(crateData);

	PerformAllInstructions(crates, instructionData);

	for (auto vector : crates)
	{
		for (auto value : vector)
		{
			std::cout << value << ',';
		}
		std::cout << "\n";
	}

	std::cout << GetTopmostCrates(crates);
}