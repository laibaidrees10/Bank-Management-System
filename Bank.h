#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
#include "account.h"
#include "studentAccount.h"
#include "creditAccount.h"
#include "loanAccount.h"
#include "specialCitizenAccount.h"
#include "bussinessAccount.h"
#include "savingAccount.h"

using namespace std;

class Bank
{
private:
    string bankName;
    int numAccounts;
    double totalBalance;
    double totalInterestToPay;
    double totalProfit;
    Account **accounts;
    int capacity;

    void resizeAccounts();

public:
    Bank(string name);
    ~Bank();

    string getName();
    void addAccount(Account *account);
    void displayAllAccounts();
    Account *findAccount(const string &accountNumber) const;
    void displayAccountHistory(const string &accountNumber) const;
    void viewAccountsByCNIC(const string &cnic);
    void withdraw(const string &accountNumber, double amount);
    void deposit(const string &accountNumber, double amount);
    void performTransaction(const string &fromAccount, const string &toAccount, const string &amountStr);
    void getAccountHistory(const string &accountNumber);
    void provideLoan(const string &accountNumber, double amount);
    void getLoanBack(const string &accountNumber, double amount);

private:
    Account *findAccount(const string &accountNumber);
    void rollbackTransaction(Account *sender, Account *receiver, double amount);
};

#endif
