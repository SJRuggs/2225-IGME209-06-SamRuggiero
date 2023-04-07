#include <iostream>
#include "methods.h";

int main()
{
    wrapper();

    if (_CrtDumpMemoryLeaks())
    {
        std::cout << "WARNING // memory Leaks found // WARNING\n";
    }
}
