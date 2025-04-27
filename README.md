# Bank-Management-System

## Overview

This is a simple Bank Management System written in C++ that allows you to manage different types of bank accounts and perform various operations like deposits, withdrawals, transactions, and loan management.

## Features

- Create and manage different types of accounts (e.g., Loan, Credit, Student, Business).
- Deposit and withdraw money from accounts.
- Transfer money between accounts.
- View transaction history.
- Loan provision and repayment for loan accounts.

## Requirements

- A C++ compiler like **g++**.
- The project files (`.cpp` and `.h` files) need to be in the same folder.

## Installation and Running

1. Clone the repository or download the project files.
2. Open a terminal or command prompt and navigate to the project folder.
3. Compile the code using the following command:

   ```bash
   g++ -o bankApp main.cpp account.cpp studentAccount.cpp creditAccount.cpp loanAccount.cpp specialCitizenAccount.cpp bussinessAccount.cpp savingAccount.cpp bank.cpp

## Run the program:

 - On Linux/macOS:
  ./bankApp

  - On Windows:
  bankApp.exe
