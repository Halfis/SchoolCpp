# Banking Account Class

This repository contains a C++ implementation of a Banking Account class. The class includes features for managing account information, recording operations, and calculating balances.

## Table of Contents

1. [Class Overview](#class-overview)
2. [Folder Structure](#folder-structure)

## Class Overview

### Fields

- **Account Number:** A string representing the account number.
- **Balance:** A real number representing the account balance.
- **Operations:** An array/list of real numbers storing operations (positive for incomes, negative for outcomes).

### Public Methods

1. **Default Constructor:**
   - Accepts the account number (default value is an empty string).
   - Initializes the balance to 0.

2. **Copy-Constructor and Assignment Operator:**
   - Provides functionality for copying the account details.

3. **Destructor:**
   - Cleans up resources and prints relevant information.

4. **getNumber:**
   - Retrieves the account number.

5. **setNumber:**
   - Updates the account number.

6. **getBalance:**
   - Retrieves the account balance.

7. **addOperation:**
   - Adds a new operation to the account, updating the list of operations and the balance.

8. **getIncomes:**
   - Returns the sum of all incomes for the account.

9. **getOutcomes:**
   - Returns the sum of all outcomes for the account.

10. **Indexing Operator []:**
    - Returns the operation at the specified position.

11. **Shift Operator <<:**
    - Prints all the data of the account, including the list of operations.

## Folder Structure

- [README.md](https://github.com/Halfis/SchoolCpp/blob/main/Lab5/Account/README.md): Description of the project, requirements, and instructions.
- [main.cpp](https://github.com/Halfis/SchoolCpp/blob/main/Lab5/Account/main.cpp): Main program to test the Banking Account class.
- [banking.h](https://github.com/Halfis/SchoolCpp/blob/main/Lab5/Account/banking.h): Header file containing the class declaration.
- [banking.cpp](https://github.com/Halfis/SchoolCpp/blob/main/Lab5/Account/banking.cpp): Source file containing the class implementation.
