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

int FindMaximumSum(std::vector<std::vector<int>> nestedVec)
{
	int highestSumFound = -1;

	for (int i = 0; i < nestedVec.size(); i++)
	{
		int currentSum = 0;
		std::vector<int> currVec = nestedVec[i];

		for (int k = 0; k < currVec.size(); k++)
		{
			currentSum += currVec[k];
		}

		if (currentSum > highestSumFound)
		{
			highestSumFound = currentSum;
		}
	}

	return highestSumFound;
}

std::vector<int> SortVec(std::vector<int> vec)
{
	std::vector<int> sorted;

	sorted.push_back(vec.back());
	vec.pop_back();

	if (vec.back() < sorted.front())
	{
		sorted.insert(sorted.begin(), vec.back());
	}
	else if (vec.back() > sorted.back())
	{
		sorted.push_back(vec.back());
	}

	vec.pop_back();

	for (int i = 0; i < vec.size() - 1; i++)
	{
		int elementOld = vec[i];
		bool placementFound = false;

		if (elementOld < sorted[0])
		{
			sorted.insert(sorted.begin(), elementOld);
			continue;
		}

		if (elementOld > sorted.back())
		{
			sorted.push_back(elementOld);
			continue;
		}

		for (int k = 1; k < sorted.size(); k++)
		{
			if (sorted[k - 1] < elementOld && elementOld <= sorted[k])
			{
				placementFound = true;
				sorted.insert(sorted.begin() + k, elementOld);
				break;
			}
		}

		if (!placementFound)
		{
			std::cout << "Something is dumb." << std::endl;

			return { 0 };
		}
	}

	for (int value : sorted)
	{
		std::cout << value << std::endl;
	}

	return sorted;

}

int SumOfTopN(std::vector<std::vector<int>> nestedVec, int N)
{
	std::vector<int> sums;

	for (int i = 0; i < nestedVec.size(); i++)
	{
		int currentSum = 0;
		std::vector<int> currVec = nestedVec[i];

		for (int k = 0; k < currVec.size(); k++)
		{
			currentSum += currVec[k];
		}

		sums.push_back(currentSum);
	}

	// Sort the elements of "sums" instead of creating a new vector

	std::vector<int> sortedVec = SortVec(sums);

	std::cout << "\nFinal sum is... " << std::endl;
	int finalSum = 0;

	for (int i = sortedVec.size() - 1; i >= sortedVec.size() - N; --i)
	{
		int element = sortedVec[i];
		finalSum += element;
		std::cout << element << std::endl;
	}

	std::cout << "-->" << finalSum << std::endl;

	return finalSum;

	// 203194 is wrong
}

int SumOfTopNBullshit(std::vector<std::vector<int>> nestedVec, int N)
{
	std::vector<int> SumOfHighest;

	for (int k = 0; k < N; k++)
	{
		int indexOfHighest = -1;
		int highestSumFound = -1;

		for (int i = 0; i < nestedVec.size(); i++)
		{
			int currentSum = 0;
			std::vector<int> currVec = nestedVec[i];

			for (int k = 0; k < currVec.size(); k++)
			{
				currentSum += currVec[k];
			}

			if (currentSum > highestSumFound)
			{
				highestSumFound = currentSum;
				indexOfHighest = i;
			}
		}

		SumOfHighest.push_back(highestSumFound);
		nestedVec.erase(nestedVec.begin() + indexOfHighest);
	}

	std::cout << "\n Final sum is..." << std::endl;

	int finalSum = 0;

	for (int sum_of_highest : SumOfHighest)
	{
		std::cout << sum_of_highest << ", ";
		finalSum += sum_of_highest;
	}

	std::cout << "-->" << finalSum << std::endl;

	return finalSum;
}
