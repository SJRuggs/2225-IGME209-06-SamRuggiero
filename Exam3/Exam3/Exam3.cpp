// Sam Ruggiero
// Section 6
// Exam #3

#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>
#include <iostream>
#include <thread>
#include "Player.h";
using namespace std;

int main()
{
	// 1. Create a player called p1 on the stack and give it a meaninful name.
	Player p1 = Player("Player 1");

	// 2. Create a player called p2 on the stack by passing p1 into the player copy constructor. 
	//    Assign p2 a different meaningful name.
	std::cout << "Creating p2 from p1 and setting its name to Player 2" << std::endl;
	Player p2 = *p1.Copy();
	p2.ChangeName("Player 2");
	p2.PrintInventory();
	std::cout << std::endl;

	// 3. Attempt a good (in range) and bad (out of range) item swap on p1. 
	//    Print both p1 and p2's inventories out after the swaps.
	std::cout << "Putting 200 int p1's inventory slot 1" << std::endl;
	p1.SwapItem(200, 1);
	std::cout << "Putting 200 int p1's inventory slot 20" << std::endl;
	p1.SwapItem(200, 20);
	p1.PrintInventory();
	p2.PrintInventory();

	// 4. Use the copy assignment operator to set p1 = p2.
	//    Print both inventories out afterwards.
	p2.PrintInventory();
	std::cout << "Setting p1 = p2, then printing p1 inventory and p2 inventory" << std::endl;
	p1.CopyAssignmentOp(p2);
	p1.PrintInventory();
	p2.PrintInventory();

	// 5. Using a loop, create 10 threads that cacll the PrintInentory() method on the p2 object.
	//    Note that mangled text output it expected from this step.
	thread* threads = new thread[10];
	for (int i = 0; i < 10; i++)
	{
		threads[i] = thread(&Player::PrintInventory, p2);
	}
	for (int i = 0; i < 10; i++)
	{
		threads[i].join();
	}

	// check for memory leaks
	if (_CrtDumpMemoryLeaks()) {
		std::cout << std::endl;
	}
}