#include <iostream>
#include "banking.h"

Operation::Operation(double val) : value(val) {}

// Constructor
Account::Account(string AN) : acc_no(AN), balance(0.0) {}

// Copy-constructor
Account::Account(const Account &other) : acc_no(other.acc_no), balance(other.balance), operations(other.operations) {}

// Assignment operator
Account &Account::operator=(const Account &other) {
    if (this == &other) {
        return *this;
    }
    acc_no = other.acc_no;
    balance = other.balance;
    operations = other.operations;
    return *this;
}

// Destructor
Account::~Account() {
    cout << "Account " << acc_no << " closed!" << endl;
}

// getNumber
string Account::getNumber() const {
    return acc_no;
}

// setNumber
void Account::setNumber(string newNumber) {
    acc_no = newNumber;
}

// getBalance
double Account::getBalance() const {
    return balance;
}

// addOperation
void Account::addOperation(double value) {
    operations.push_back(Operation(value));
    balance += value;
}

// getIncomes
double Account::getIncomes() const {
    double sum = 0.0;
    for (const Operation &op : operations) {
        if (op.value > 0) {
            sum += op.value;
        }
    }
    return sum;
}

// getOutcomes
double Account::getOutcomes() const {
    double sum = 0.0;
    for (const Operation &op : operations) {
        if (op.value < 0) {
            sum += op.value;
        }
    }
    return sum;
}

// Indexing operator
double Account::operator[](int index) const {
    if (index >= 0 && index < operations.size()) {
        return operations[index].value;
    } else {
        return 101;
    }
}

// Shift operator
ostream &operator<<(ostream &out, const Account &acc) {
    out << endl << endl;
    out << "!!! ACCOUNT DETAILS !!!" << endl;
    out << "Account Number: " << acc.acc_no << endl;
    out << "Account Balance: " << acc.balance << endl;
    out << "Account Incomes: " << acc.getIncomes() << endl;
    out << "Account Outcomes: " << acc.getOutcomes() << endl << endl;
    out << "Account Operations:" << endl;
    for (int i = 0; i < acc.operations.size(); ++i) {
        out << "Operation " << i + 1 << ": " << acc.operations[i].value << endl;
    }
    out << endl;
    return out;
}