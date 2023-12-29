#include <iostream>
#include "banking.h"

using namespace std;

int main() {
    // Constructor
    Account myAccount("12345");
    
    // getNumber
    cout << "Account Number: " << myAccount.getNumber() << endl;
    
    // setNumber
    myAccount.setNumber("98765");
    
    // getNumber
    cout << "New Account Number: " << myAccount.getNumber() << endl;
    
    // getBalance
    cout << "Account Balance: " << myAccount.getBalance() << endl;
    
    // addOperation
    myAccount.addOperation(10.0);
    myAccount.addOperation(-5.0);
    myAccount.addOperation(-150.50);
    myAccount.addOperation(628.25);
    
    // getIncomes
    cout << "Account Incomes: " << myAccount.getIncomes() << endl;
    
    // getOutcomes
    cout << "Account Outcomes: " << myAccount.getOutcomes() << endl;

    // Print account details
    cout << myAccount;
    
    // Copy-constructor
    cout << "Testing the Copy Constructor";
    Account c(myAccount);
    cout << c << endl;

    // Close Account
    return 0;
}
