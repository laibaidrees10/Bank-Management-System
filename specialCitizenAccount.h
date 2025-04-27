#ifndef SPECIAL_CITIZEN_ACCOUNT_H
#define SPECIAL_CITIZEN_ACCOUNT_H

#include <iostream>
#include <string>
#include "account.h"
#include "transaction.h"
#include "date.h" // Assuming Date class is defined in this file

using namespace std;

class SpecialCitizenAccount : public Account
{
private:
    string supporter;
    double fixedAmountPerMonth;
    double depositLimit;

public:
    SpecialCitizenAccount();
    SpecialCitizenAccount(string aN, Person aH, string bL, string support, double fixedAmount, double Limit);
    SpecialCitizenAccount(SpecialCitizenAccount &other);

    void display() override;

    bool withdraw(const string &amount) override;
    void deposit(const string &amount) override;
    bool transfer(Account &toAccount, const string &amount) override;

    friend istream &operator>>(istream &is, SpecialCitizenAccount &account);
};

#endif // SPECIAL_CITIZEN_ACCOUNT_H
