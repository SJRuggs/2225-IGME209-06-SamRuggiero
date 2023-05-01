#include <iostream>
#include <thread>
#include <vector>
#include "NumberPrinter.h"
#include "Gameplay.h"

using namespace std;

int main()
{
    // part 1
    vector<thread*> threadsP1;
    for (int i = 0; i < 50; i++)
    {
        // numP.Print();
        threadsP1.push_back(new thread(&NumberPrinter::Print, NumberPrinter(i)));
    }
    for (int i = 0; i < threadsP1.size(); i++)
    {
        threadsP1[i]->join();
        delete threadsP1[i];
    }

    // part 2
    vector<Gameplay> gameplays;
    gameplays.push_back(Gameplay("Physics"));
    gameplays.push_back(Gameplay("Spawning"));
    gameplays.push_back(Gameplay("Healthbar"));
    gameplays.push_back(Gameplay("Texturing"));
    gameplays.push_back(Gameplay("Pathfinding"));
    vector<thread*> threadsP2;
    for (int i = 0; i < gameplays.size(); i++)
    {
        threadsP2.push_back(new thread(&Gameplay::Update, gameplays[i]));
    }
    for (int i = 0; i < threadsP2.size(); i++)
    {
        threadsP2[i]->join();
        delete threadsP2[i];
    }
    cout << "Update Complete! Time to Draw";
}
