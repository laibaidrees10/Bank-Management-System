#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

#include <iostream>
#include <string>
#include "account.h"
#include "transaction.h"
#include "date.h" // Assuming Date class is defined in this file

using namespace std;

class SavingsAccount : public Account
{
private:
    double balance;
    double interestRate;
    Date packageStartDate;
    int timePeriod;

public:
    SavingsAccount();
    SavingsAccount(string aN, Person aH, string bL, Date startDate, int time, double interest);

    double calculateRepaymentAmount();
    void display() override;

    bool withdraw(const string &amount) override;
    void deposit(const string &amount) override;
    bool transfer(Account &toAccount, const string &amount) override;

    friend istream &operator>>(istream &is, SavingsAccount &account);
};

#endif // SAVINGS_ACCOUNT_H
