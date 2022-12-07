#pragma once
#include <string>
#include <vector>

#include "../InputDebug.h"

struct Range
{
public:
	int minimum;
	int maximum;

	bool Contains(const int value) const
	{
		return (minimum <= value && value <= maximum);
	}
};

struct RangePair
{
	Range firstRange;
	Range secondRange;

	bool IsSelfContained()
	{
		bool secondWithinFirst = firstRange.minimum <= secondRange.minimum && secondRange.maximum <= firstRange.maximum;
		bool firstWithinSecond = secondRange.minimum <= firstRange.minimum && firstRange.maximum <= secondRange.maximum;
		return secondWithinFirst || firstWithinSecond;
	}

	bool ContainsOverlap()
	{
		bool a = firstRange.minimum <= secondRange.minimum && secondRange.minimum <= firstRange.maximum;
		bool b = firstRange.minimum <= secondRange.maximum && secondRange.maximum <= firstRange.maximum;
		bool c = secondRange.minimum <= firstRange.minimum && firstRange.minimum <= secondRange.maximum;
		bool d = secondRange.minimum <= firstRange.maximum && firstRange.maximum <= secondRange.maximum;

		return a || b || c || d;
	}
};

inline Range ParseIntoRange(std::string rangeString)
{
	size_t pos = rangeString.find("-");

	const int rangeMin = std::stoi(rangeString.substr(0, pos));
	const int rangeMax = std::stoi(rangeString.substr(pos + 1));

	Range result = Range{ rangeMin,rangeMax };

	return result;
}

inline int CountSelfContainedPairs(std::vector<std::string> data, const bool isPartTwo = true)
{
	int selfContainedCount = 0;

	for (std::string line : data)
	{
		size_t pos = line.find(",");

		std::string first = line.substr(0, pos);
		std::string second = line.substr(pos + 1);

		RangePair pair = RangePair{ ParseIntoRange(first), ParseIntoRange(second) };


		if (isPartTwo)
		{
			if (pair.ContainsOverlap())
			{
				selfContainedCount++;
			}
		}
		else
		{

			if (pair.IsSelfContained())
			{
				selfContainedCount++;
			}
		}
	}

	return selfContainedCount;
}