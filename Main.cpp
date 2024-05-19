#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include "employee.h"
using namespace std;



// Employee** loadAllEmployees(ifstream& in) {
// 	char* type[2];
// 	in.read((char*)&type, sizeof(type));
// 	if (type == "")
// }

int main() {
	Employee e((char*)"Spongebob", 26, 1);
	ofstream out;
	out.open("employees.txt", ios::out);
	e.save(out);
	out.close();
	ifstream in;
	return 0;
}