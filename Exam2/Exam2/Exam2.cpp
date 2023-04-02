// Sam Ruggiero - Exam 2

#include "MovableObject.h";
#include "Player.h";
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // 1 ----------------------------------------
    vector<MovableObject*> objects;
    objects.push_back(new MovableObject(rand() % 201 - 100, rand() % 201 - 100));
    objects.push_back(new MovableObject(rand() % 201 - 100, rand() % 201 - 100));
    objects.push_back(new MovableObject(rand() % 201 - 100, rand() % 201 - 100));
    objects.push_back(new Player(rand() % 201 - 100, rand() % 201 - 100));
    objects.push_back(new Player(rand() % 201 - 100, rand() % 201 - 100));



    // 2 ----------------------------------------
    for (int i = 0; i < objects.size(); i++)
    {
        objects[i]->Display();
    }



    // 3 ----------------------------------------
    for (int i = 0; i < objects.size(); i++)
    {
        delete objects[i];
    }
    cout << "No Memory Leaks";
}
