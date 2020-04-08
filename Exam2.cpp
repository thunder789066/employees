// Christina Gerstner
// clgdtf@mail.umkc.edu
// 11/05/2019
// CS201L Lab 12

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "Employee.h"
using namespace std;

int main() {
	string command, first, last, full;
	string* name = nullptr;
	int* employee_id = nullptr, * payrate = nullptr;
	int id, rate;
	vector<Employee> employees;

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	while (fin.good()) {
		fin >> command;

		if (command == "NEW") {		// if new, add employee to vector
			fin >> id >> first >> last;
			full = first + " " + last;	// first & last == full name
			name = &full;
			employee_id = &id;
			Employee Employee(id, *name);
			employees.push_back(Employee);
		}
		else if (command == "RAISE") {	// if raise, give employee a raise
			fin >> id >> rate;
			employee_id = &id;
			payrate = &rate;
			for (int i = 0; i < employees.size(); ++i) {
				if (employees.at(i).getEmployeeID() == *employee_id) {
					employees.at(i).giveRaise(rate);
				}
			}
		}
		else if (command == "PAY") {	// if pay, pay ALL employees in vector
			for (int i = 0; i < employees.size(); ++i) {
				employees.at(i).pay();
			}
		}
		else if (command == "FIRE") {	// if fire, employee is fired
			fin >> id;
			employee_id = &id;
			for (int i = 0; i < employees.size(); ++i) {
				if (employees.at(i).getEmployeeID() == *employee_id) {
					employees.at(i).fire();
				}
			}
		}
	}
	fin.close();

	for (int i = 0; i < employees.size(); ++i) {
		fout << employees.at(i).getEmployeeID() << " " << employees.at(i).getName() << " $" << employees.at(i).getBalance() << employees.at(i).getPayRate() << endl;
	}

	return 0;
}
