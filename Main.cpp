#include <iostream>
#include <fstream>
using namespace std;

class Employee {
	char* name;
	int age;
	int salary;
public:
	Employee(char* name, int age, int salary) : name(name), age(age), salary(salary) {}

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

	void saveTypes(ofstream& out) const {
		// Create type code (2 characters)
		char type[2];
		strncpy(type, typeid(*this).name() + 6, 2);
		out.write((char*)type, 2);
	}
};

int main() {
	Employee e((char*)"Spongebob", 26, 1);
	ofstream out;
	out.open("emp.txt", ios::out);
	e.save(out);
	out.close();
	return 0;
}