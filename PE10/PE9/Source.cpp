#include <iostream>
#include "Player.h"
#include "Fighter.h"
using namespace std;

int main() 
{
	Player p1 = Player();
	Player p2 = Player("Sam", 10, 14, 11);
	Player* p3 = new Player();
	Player* p4 = new Player("Justin", 12, 12, 10);

	cout << "- PRINTING P1 -" << endl;
	p1.printPlayer();
	cout << endl << "- PRINTING P2 -" << endl;
	p2.printPlayer();
	cout << endl << "- PRINTING P3 -" << endl;
	p3->printPlayer();
	cout << endl << "- PRINTING P4 -" << endl;
	p4->printPlayer();

	delete p3;
	delete p4;

	cout << endl << "== PE10: OOP ==" << endl;
	Fighter f1 = Fighter();
	Fighter f2 = Fighter("Zach", "Swords", 14, 8, 10);

	cout << endl << "- PRINTING F1 -" << endl;
	f1.printFighter();
	cout << endl << "- PRINTING F2 -" << endl;
	f2.printFighter();
}