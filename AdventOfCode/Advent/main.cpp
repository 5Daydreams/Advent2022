#include "InputDebug.h"
#include "Day1_1.h"

int main(void)
{
	std::vector<std::vector<int>> data = StoreDataAsNestedVector();

	SumOfTopNBullshit(data, 3);

	return 0;
}
