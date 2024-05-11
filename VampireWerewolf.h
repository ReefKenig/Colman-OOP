#include <iostream>
#include "Vampire.h"
#include "Werewolf.h"
using namespace std;

class VampireWerewolf : public Vampire, public Werewolf {
	Creature** offsprings;
};