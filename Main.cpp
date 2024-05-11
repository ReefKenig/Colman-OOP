#include <iostream>
#include "Creature.h"
#include "Vampire.h"
#include "Werewolf.h"
#include "VampireWerewolf.h"
using namespace std;

int main() {
	// Creature c((char*)"Meliodas", 2000, 1);
	// c.printInfo();
	// Vampire alucard((char*)"Alucard", 55, 0, 4, nullptr);
	// Vampire* offsprings[] = { &alucard };
	// Vampire dracula((char*)"Dracula", 200, 1, 10, offsprings);
	// dracula.printInfo();
	// Werewolf bobby((char*)"Bobby", 34, 0, 6, 18, nullptr);
	// bobby.printInfo();
	// Creature* offsprings[] = { &alucard, &bobby };
	VampireWerewolf ackbar((char*)"Ackbar", 100, 0, 50, 24, 0, nullptr);
	ackbar.printInfo();
	return 1;
}