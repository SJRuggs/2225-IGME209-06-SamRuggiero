#include <iostream>
#include <memory>
#include "GameLevel.h";

void MyFunctionA()
{
    std::unique_ptr<GameLevel> smartPtr(new GameLevel());
}

void MyFunctionB()
{
    GameLevel* ptr = new GameLevel();
}

void PrintLeaks()
{
    if (_CrtDumpMemoryLeaks())
    {
        std::cout << "Memory leaks found!" << std::endl;
    }
    else
    {
        std::cout << "No memory leaks" << std::endl;
    }
}

int main()
{
    MyFunctionA();
    PrintLeaks();
    std::cout << std::endl;
    MyFunctionB();
    PrintLeaks();
}