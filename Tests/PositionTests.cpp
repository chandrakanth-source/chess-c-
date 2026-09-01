#include "../Engine/Position.h"
#include <iostream>

int main()
{

    Position position;

    std::cout << "Initial Chess Position:\n";

    position.display();

    std::cout << "\nTesting move e2 -> e4\n";

    bool result =
        position.movePiece("e2", "e4");

    if (result)
    {
        std::cout << "Move successful!\n";
    }
    else
    {
        std::cout << "Move failed!\n";
    }

    position.display();

    return 0;
}