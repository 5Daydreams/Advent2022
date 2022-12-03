#include "InputDebug.h"
#include "Day2.h"
#include "Day3.h"

int main(void)
{
	std::cout << "Hello day 3" << std::endl;

	std::vector<std::string> data = StoreDataAsStringVector(3);

	int value = FindBadgeSumOfPriorities(data);

	std::cout << "Found the sum as: " << value << "\n";

	return 0;
}
