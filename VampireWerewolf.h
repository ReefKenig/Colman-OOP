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
		Creature(name, age, numOfOffsprings),
		Vampire(name, age, 0, lightSensitivity, nullptr),
		Werewolf(name, age, 0, werewolfHours, humanHours, nullptr) {
		if (numOfOffsprings <= 0) { m_offsprings = nullptr; }
		else {
			m_offsprings = new Creature * [numOfOffsprings];
			for (int i = 0; i < numOfOffsprings; i++) {
				m_offsprings[i] = offsprings[i];
			}
		}
	}

	virtual void printSpecificInfo() override {
		Vampire::printSpecificInfo();
		Werewolf::printSpecificInfo();
		cout << "===VampireWerewolf printInfo===" << endl;
		for (int i = 0; i < m_numOfOffsprings; i++) {
			cout << "- Offspring " << i + 1 << endl;
			cout << "Name: " << m_offsprings[i]->getName() << endl;
			cout << "Species: ";
			if (auto* VOffspring = dynamic_cast<Vampire*>(m_offsprings[i])) {
				cout << "Vampire" << endl;
			}
			else if (auto* WOffspring = dynamic_cast<Werewolf*>(m_offsprings[i])) {
				cout << "Werewolf" << endl;
			}
			else if (auto* VWOffspring = dynamic_cast<VampireWerewolf*>(m_offsprings[i])) {
				cout << "Vampire Werewolf" << endl;
			}
		}
	}

	bool isPureVampire(Creature* offspring) {
		if (typeid(*offspring) == typeid(Vampire)) { return true; }
		return false;
	}

	bool isVampireLike(Creature* offspring) {
		if (dynamic_cast<Vampire*>(offspring)) { return true; }
		return false;
	}

	int pureVampireOffsprings() {
		int count = 0;
		if (m_offsprings) {
			for (int i = 0; i < m_numOfOffsprings; i++) {
				if (isPureVampire(m_offsprings[i])) {
					count++;
				}
			}
		}
		return count;
	}

	int vampireLikeOffsprings() {
		int count = 0;
		if (m_offsprings) {
			for (int i = 0; i < m_numOfOffsprings; i++) {
				if (isVampireLike(m_offsprings[i])) {
					count++;
				}
			}
		}
		return count;
	}

	int averageLightSensitivity() {
		double sum = 0;
		int vampireLikes = 0;
		if (m_offsprings) {
			for (int i = 0; i < m_numOfOffsprings; i++) {
				if (isVampireLike(m_offsprings[i])) {
					vampireLikes++;
					sum += dynamic_cast<Vampire*>(m_offsprings[i])->getLightSensitivity();
				}
			}
		}
		return (int)(sum / vampireLikes);
	}
};

#endif // !VAMPIRE_WEREWOLF_H