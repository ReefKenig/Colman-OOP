#include <iostream>
#include <array>
#include "Creature.h"
using namespace std;

class Vampire : public virtual Creature {
	int m_lightSensitivity;
	Vampire** m_offsprings;
public:
	Vampire(): m_lightSensitivity(0), m_offsprings(nullptr) {}
	Vampire(char* name, int age, int numOfOffsprings, Vampire** offsprings, int lightSensitivity):
		Creature(name, age, numOfOffsprings), m_lightSensitivity(lightSensitivity), m_offsprings(offsprings) {}
	Vampire(Vampire& v) {
		delete[] m_offsprings;

		m_lightSensitivity = v.m_lightSensitivity;
		m_offsprings = new Vampire* [v.getNumOfOffsprings()];
	}
	~Vampire() {
		for (int i = 0; i < m_numOfOffsprings; i++) {
			delete(m_offsprings[i]);
		}
		delete[] m_offsprings;
	}
};