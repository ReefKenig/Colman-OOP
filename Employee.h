#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <fstream>
using namespace std;

class Employee {
	char* name;
	int age;
	int salary;
public:
	// Constructor
	Employee(char* name, int age, int salary) : name(name), age(age), salary(salary) {}

	// Save employee to file
	virtual void save(ofstream& out) {
		// Save the name field length
		int n = strlen(name);
		out.write((char*)&n, sizeof(n));
		// Name field data
		out.write(name, n);
		// Rest of data
		out.write((char*)&age, sizeof(age));
		out.write((char*)&salary, sizeof(salary));
	}

	// Load employee from file
	virtual void load(ifstream& in) {
		// Read the length of the name field and then the name
		int n;
		in.read((char*)&n, sizeof(n));
		name = new char[n + 1];
		in.read(name, n);
		name[n] = '\0';
		// Read age and salary
		in.read((char*)&age, sizeof(age));
		in.read((char*)&salary, sizeof(salary));
	}

	// Save employee subclass
	void saveType(ofstream& out) const {
		// Create type code (2 characters)
		char type[2];
		strncpy(type, typeid(*this).name() + 6, 2);
		out.write((char*)type, 2);
	}
};

#endif // !EMPLOYEE_H