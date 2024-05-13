#ifndef VAMPIRE_H
#define	VAMPIRE_H
#include <iostream>
#include <array>
#include "Creature.h"
using namespace std;

class Vampire : public virtual Creature {
	int m_lightSensitivity;
	Vampire** m_offsprings;
public:
	// Constructors
	Vampire(): m_lightSensitivity(0), m_offsprings(nullptr) {}
	Vampire(char* name, int age, int numOfOffsprings, int lightSensitivity, Vampire** offsprings):
		Creature(name, age, numOfOffsprings), m_lightSensitivity(lightSensitivity) {
		if (numOfOffsprings <= 0) { m_offsprings = nullptr; }
		else {
			m_offsprings = new Vampire * [numOfOffsprings];
			for (int i = 0; i < numOfOffsprings; i++) {
				m_offsprings[i] = offsprings[i];
			}
		}
		
	}
	// Vampire(Vampire& v) {
	// 	delete[] m_offsprings;
	// 
	// 	m_lightSensitivity = v.m_lightSensitivity;
	// 	m_offsprings = new Vampire* [v.getNumOfOffsprings()];
	// }
	// ~Vampire() {
	// 	for (int i = 0; i < m_numOfOffsprings; i++) {
	// 		delete(m_offsprings[i]);
	// 	}
	// 	delete[] m_offsprings;
	// }

	int getLightSensitivity() { return m_lightSensitivity; }

	virtual void printSpecificInfo() override {
		cout << "===Vampire printInfo===" << endl;
		cout << "Light sensitivity: " << m_lightSensitivity << endl;
		if (m_offsprings != nullptr) {
			for (int i = 0; i < m_numOfOffsprings; i++) {
				cout << "- Offspring " << i + 1 << ": " << m_offsprings[i]->m_name << endl;
			}
		}
	}
};

#endif // !VAMPIRE_H