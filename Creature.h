#ifndef CREATURE_H
#define CREATURE_H
#include <iostream>
using namespace std;

class Creature {
protected:
	char* m_name;
	int m_age;
	int m_numOfOffsprings;
public:
	// Constructors
	Creature(): m_name(nullptr), m_age(0), m_numOfOffsprings(0) {}
	Creature(const char* name, int age, int numOfOffsprings):
		m_age(age),
		m_numOfOffsprings(numOfOffsprings) {
		m_name = new char[strlen(name) + 1];
		strcpy_s(m_name, strlen(name) + 1, name);
	}

	char* getName() { return m_name; }
	int getAge() { return m_age; }
	int getNumOfOffsprings() { return m_numOfOffsprings; }

	void printCommonInfo() {
		cout << "===Creature printInfo===" << endl;
		cout << "Name: " << m_name << endl;
		cout << "Age: " << m_age << endl;
		cout << "Number of offsprings: " << m_numOfOffsprings << endl;
	}

	virtual void printSpecificInfo() = 0;

	void printInfo() {
		printCommonInfo();
		printSpecificInfo();
		cout << endl;
	}
};

#endif // !CREATURE_H