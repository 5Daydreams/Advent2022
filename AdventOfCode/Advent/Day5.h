#pragma once
#include <string>
#include <vector>

#include "InputDebug.h"


inline void MoveNCratesFromTo(std::vector<std::vector<char>>& crates, const int N, const int from, const int to)
{
    for (int i = 0; i < N; i++)
    {
        auto crateChar = crates.at(from).back();
        crates.at(to).push_back(crateChar);
        crates.at(from).pop_back();
    }
}

inline void ReadLineInstruction(std::vector<std::vector<char>>& crates, const std::string instruction)
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

    MoveNCratesFromTo(crates, count, from, to);

    //std::cout << count << '.' << fromIndex << '.' << toIndex << std::endl;
}

inline std::string PerformInstructions(std::vector<std::vector<char>>& crates, const std::vector<std::string> instructions)
{

}