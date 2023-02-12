#include <iostream>
using namespace std;

class MovableObject
{
public:
	int xPos;
	int yPos;
	void PrintPos()
	{
		cout << "X:" << xPos << " Y:" << yPos << endl;
	}
};

class Player : public MovableObject
{
public:
	char* name;
	Player()
	{
		cout << "player ctor" << endl << endl;
		name = new char[15];
	}

	~Player()
	{
		cout << "player dtor" << endl << endl;
		delete[] name;
	}
};

class Monster : public MovableObject
{
public:
	int damage;
};

int main()
{
	Monster* boss = new Monster();
	Player* pOne = new Player();
	// MovableObject *boss = new Monster();
	// MovableObject *pOne = new Player();
	Monster* fakeMonster = (Monster*)pOne;

	// add code here
	cout << "- VARIABLE ADDRESSES -" << endl;
	cout << "Boss:         " << &boss << endl;
	cout << "Player:       " << &pOne << endl;
	cout << "Fake Monster: " << &fakeMonster << endl << endl;

	cout << "- REFERENCE ADDRESSES -" << endl;
	cout << "Boss:         " << &*boss << endl;
	cout << "Player:       " << &*pOne << endl;
	cout << "Fake Monster: " << &*fakeMonster << endl << endl;

	//boss->xPos = 1;
	//boss->yPos = 2;
	boss->damage = 3;

	//pOne->xPos = 4;
	//pOne->yPos = 5;

	fakeMonster->xPos = 7;
	fakeMonster->yPos = 8;
	fakeMonster->damage = 9;

	cout << "- VALUES -" << endl;
	cout << "Boss Damage:         " << boss->damage << endl;
	cout << "Fake Monster Damage: " << fakeMonster->damage << endl << endl;

	cout << "Boss Position:         ";
	boss->PrintPos();
	cout << "Player Position:       ";
	pOne->PrintPos();
	cout << "Fake Monster Position: ";
	fakeMonster->PrintPos();
	
	delete boss;
	// delete pOne;
	// the above line is unnecessary and doesn't allow fakeMonster's damage to change
	delete fakeMonster;

	return 0;
}

// question (6):
// the player object position is overridden when the fake monster position changes