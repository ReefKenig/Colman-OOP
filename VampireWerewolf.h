#ifndef VAMPIRE_WEREWOLF_H
#define VAMPIRE_WEREWOLF_H
#include <iostream>
#include "Vampire.h"
#include "Werewolf.h"
using namespace std;

class VampireWerewolf : public Vampire, public Werewolf {
	Creature** m_offsprings;
public:
	VampireWerewolf(
		char* name,
		int age,
		int numOfOffsprings,
		int lightSensitivity,
		int werewolfHours,
		int humanHours,
		Creature** offsprings):
		Vampire(name, age, numOfOffsprings, lightSensitivity, nullptr),
		Werewolf(name, age, numOfOffsprings, werewolfHours, humanHours, nullptr) {
		if (numOfOffsprings <= 0) { m_offsprings = nullptr; }
		else {
			m_offsprings = new Creature * [numOfOffsprings];
			for (int i = 0; i < numOfOffsprings; i++) {
				m_offsprings[i] = offsprings[i];
			}
		}
	}
	
	virtual void printInfo() {
		Creature::printInfo();
		// Vampire::printInfo();
		// Werewolf::printInfo();
		cout << "===VampireWerewolf printInfo===" << endl;
		// for (int i = 0; i < m_numOfOffsprings; i++) {
		// 	cout << "- Offspring " << i + 1 << endl;
		// 	cout << "Name: " << m_offsprings[i] << endl;
		// 	cout << "Species: ";
		// 	if (auto* VOffspring = dynamic_cast<Vampire*>(m_offsprings[i])) {
		// 		cout << "Vampire" << endl;
		// 	}
		// 	else if (auto* WOffspring = dynamic_cast<Werewolf*>(m_offsprings[i])) {
		// 		cout << "Werewolf" << endl;
		// 	}
		// 	else if (auto* VWOffspring = dynamic_cast<VampireWerewolf*>(m_offsprings[i])) {
		// 		cout << "Vampire Werewolf" << endl;
		// 	}
		// }
	}
};

#endif // !VAMPIRE_WEREWOLF_H