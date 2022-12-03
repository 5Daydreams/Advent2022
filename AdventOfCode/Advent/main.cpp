#include "InputDebug.h"
#include "Day2.h"

int main(void)
{
	std::cout << "Hello day 3" << std::endl;

	std::vector<std::string> allData = StoreDataAsStringVector();

	std::cout << CalcNewRoundsResult(allData);

	return 0;
}

// 9377 too high
