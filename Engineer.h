#pragma once
#ifndef ENGINEER_H
#define ENGINEER_H
#include <iostream>
#include <fstream>
#include "Employee.h";
using namespace std;

class Engineer : public Employee {
	int typeOfDegree;
public:
	// Constructor
	Engineer(char* name, int age, int salary, int degree) : Employee(name, age, salary), typeOfDegree(degree) {}

	virtual void save(ofstream& out) {
		Employee::saveType(out);
		Employee::save(out);
		out.write((char*)&typeOfDegree, sizeof(typeOfDegree));
	}

	virtual void load(ifstream& in) {}
};

#endif // !ENGINEER_H

