#include "../AI/Evaluation.h"

#include <iostream>

int main()
{
    Position position;

    int score =
        Evaluation::evaluate(position);

    std::cout
        << "Initial evaluation: "
        << score
        << "\n";

    return 0;
}