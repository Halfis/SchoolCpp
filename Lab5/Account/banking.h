#ifndef BANKING_KNOWN
#define BANKING_KNOWN

#include <string>
#include <vector>

using namespace std;

class Operation {
    public:
        double value;
        Operation(double val);
};

class Account {
    private:
        string acc_no;
        double balance;
        vector<Operation> operations;
    
    public:
        // Constructor
        Account(string AN);
    
        // Copy-constructor
        Account(const Account &other);
    
        // Assignment operator
        Account &operator=(const Account &other);
    
        // Destructor
        ~Account();
    
        // getNumber
        string getNumber() const;
    
        // setNumber
        void setNumber(string newNumber);
    
        // getBalance
        double getBalance() const;
    
        // addOperation
        void addOperation(double value);
    
        // getIncomes
        double getIncomes() const;
    
        // getOutcomes
        double getOutcomes() const;
    
        // Indexing operator
        double operator[](int index) const;
    
        // Shift operator
        friend ostream &operator<<(ostream &out, const Account &acc);
};

#endif