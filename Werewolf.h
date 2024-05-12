#ifndef WEREWOLF_H
#define WEREWOLF_H
#include <iostream>
#include "Creature.h"
using namespace std;

class Werewolf: public virtual Creature {
	int m_werewolfHours, m_humanHours;
	Werewolf** m_offsprings;
public:
	// Constructors
	Werewolf() : m_werewolfHours(0), m_humanHours(0), m_offsprings(nullptr) {}
	Werewolf(char* name, int age, int numOfOffsprings, int werewolfH, int humanH, Werewolf** offsprings):
		Creature(name, age, numOfOffsprings),
		m_werewolfHours(werewolfH),
		m_humanHours(humanH) {
		if (numOfOffsprings <= 0) { m_offsprings = nullptr; }
		else {
			m_offsprings = new Werewolf * [numOfOffsprings];
			for (int i = 0; i < numOfOffsprings; i++) {
				m_offsprings[i] = offsprings[i];
			}
		}
	}
	
	virtual void printSpecificInfo() override {
		cout << "===Werewolf printInfo===" << endl;
		cout << "Werewolf hours: " << m_werewolfHours << endl;
		cout << "Human hours: " << m_humanHours << endl;
		if (m_offsprings != nullptr) {
			for (int i = 0; i < m_numOfOffsprings; i++) {
				cout << "- Offspring " << i + 1 << ": " << m_offsprings[i]->m_name << endl;
			}
		}
	}
};

#endif // !WEREWOLF_H