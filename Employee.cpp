// Christina Gerstner
// clgdtf@mail.umkc.edu
// 11/05/2019
// CS201L Lab 12

#include <string>
#include "Employee.h"
using namespace std;

// Constructor
Employee::Employee(int id, string myName) {
	int employeeID = id;
	string name = myName;
	double balance = 0.0;
	double payRate = 10.0;
	bool employed = true;
}

// Getter to return the employee ID
int Employee::getEmployeeID() {
	return employeeID;
}

// Getter to return the current pay rate
double Employee::getPayRate() {
	return payRate;
}

// Getter to return the current amount of pay earned
double Employee::getBalance() {
	return balance;
}

// Getter to get Employee's name
string Employee::getName() {
	return name;
}

// Function to give the raise. It takes in a percent in whole numbers (ex: 5 for 5%)
void Employee::giveRaise(int rate) {
	double newRate = 0.0;
	if (rate == 5) { newRate = 0.05; }
	payRate = (payRate * newRate) + payRate;
}

// Pays the employee
void Employee::pay() {
	balance += payRate;
}

// Fires the Employee
void Employee::fire() {
	payRate = 0.0;
	employed = false;
}

// Returns if the Employee is currently employed
bool Employee::isEmployed() {
	return employed;
}
