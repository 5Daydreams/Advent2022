#include "InputDebug.h"
#include "Day5.h"

int main(void)
{
    std::cout << "Hello day 5" << std::endl;

    std::vector<std::vector<char>> crates = { std::vector<char>{} };

    ReadLineInstruction(crates, "move 100 from 17 to 55");

    return 0;
}