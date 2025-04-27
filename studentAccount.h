#ifndef STUDENT_ACCOUNT_H
#define STUDENT_ACCOUNT_H

#include <iostream>
#include <string>
#include "account.h"
#include "transaction.h"
#include "date.h" // Assuming Date class is defined in this file

using namespace std;

class StudentAccount : public Account
{
private:
    double depositLimit;
    double withdrawalLimit;
    double transferLimit;
    double withdrawalCharge;
    double transferCharge;
    int numOfTransactionsToday;

public:
    StudentAccount();
    StudentAccount(string accountNumber, Person accountHolder, string balance);

    void display() override;

    bool withdraw(const string &amount) override;
    void deposit(const string &amount) override;
    bool transfer(Account &toAccount, const string &amount) override;

    friend istream &operator>>(istream &is, StudentAccount &account);
};

#endif // STUDENT_ACCOUNT_H
