#pragma once
#include <string>

class Player
{
private:
	int* inventory;
	int invSize;
	std::string name;
public:
	Player(std::string name);
	void SwapItem(int _itemId, int _slot);
	void PrintInventory();
	void ChangeName(std::string _newName);
	Player* Copy();
	void CopyAssignmentOp(Player other);
};

