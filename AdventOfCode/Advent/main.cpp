#include "InputDebug.h"
#include "Day4.h"

using namespace std;

int main(void)
{
	std::cout << "Hello day 4" << std::endl;

	std::vector<std::string> data = StoreDataAsStringVector(4);

	int thing = CountSelfContainedPairs(data);

	std::cout << thing << '\n';

	return 0;
}
