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
	Creature(char* name, int age, int numOfOffsprings):
		m_name(strcpy(name, m_name)),
		m_age(age),
		m_numOfOffsprings(numOfOffsprings) {}
	Creature(Creature& c) {
		strcpy(m_name, c.getName());
		m_age = c.getAge();
		m_numOfOffsprings = c.getNumOfOffsprings();
	}

	// Set methods
	void setName(char* name) { strcpy(m_name, name); }
	void setAge(int age) { m_age = age; }
	void setNumOfOffsprings(int offsprings) { m_numOfOffsprings = offsprings; }

	// Get methods
	char* getName() { return m_name; }
	int getAge() { return m_age; }
	int getNumOfOffsprings() { return m_numOfOffsprings; }
};