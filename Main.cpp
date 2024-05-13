#include <iostream>
#include "Creature.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "VampireWerewolf.h"
using namespace std;

int main() {
	Vampire alucard((char*)"Alucard", 55, 0, 4, nullptr);
	Vampire vlada((char*)"Vlada", 26, 0, 14, nullptr);
	Vampire* v_offsprings[] = { &alucard };
	Vampire dracula((char*)"Dracula", 200, 1, 10, v_offsprings);
	Werewolf bobby((char*)"Bobby", 34, 0, 6, 18, nullptr);
	VampireWerewolf scooby((char*)"ScoobyDoo", 888, 0, 5, 6, 10, nullptr);
	Creature* c_offsprings[] = { &alucard, &bobby, &vlada, &scooby };
	VampireWerewolf ackbar((char*)"Ackbar", 100, 4, 50, 24, 0, c_offsprings);

	// alucard.printInfo();
	// dracula.printInfo();
	// bobby.printInfo();
	// ackbar.printInfo();

	cout << ackbar.pureVampireOffsprings() << endl;
	cout << ackbar.vampireLikeOffsprings() << endl;
	cout << ackbar.averageLightSensitivity() << endl;

	return 1;
}