#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "transaction.h"

using namespace std;

class Account
{
protected:
    string accountNumber;
    Person accountHolder;
    char *balance;
    string cnic;
    vector<Transaction *> transactionHistory;

public:
    Account();
    Account(string &accountNumber, Person &accountHolder, string &balance);
    virtual ~Account();

    int getNumTransactions() const;
    const vector<Transaction *> &getTransactionHistory() const;
    void addTransactionToHistory(Transaction *transaction);
    void displayHistory() const;

    double stringToDouble(string str);
    string doubleToString(double value) const;

    string getCNIC() const;
    string getAccountNumber() const;
    Person getAccountHolder();
    void addTransaction(Transaction *transaction);
    void setBalance(const string &newBalance);
    string getBalance() const;

    void checkBalance() const;
    void viewTransactionHistory() const;

    virtual void display() = 0;
    virtual bool withdraw(const string &amount) = 0;
    virtual void deposit(const string &amount) = 0;
    virtual bool transfer(Account &toAccount, const string &amount) = 0;
};

#endif // ACCOUNT_H
