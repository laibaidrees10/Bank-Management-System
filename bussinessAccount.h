#ifndef BUSINESS_ACCOUNT_H
#define BUSINESS_ACCOUNT_H

#include <iostream>
#include <string>
#include "account.h"
#include "transaction.h"

using namespace std;

class BusinessAccount : public Account
{
private:
    double negativeBalance;

public:
    BusinessAccount();
    BusinessAccount(string aN, Person aH, string bL);
    
    void display() override;
    
    double stringToDouble(string str);
    string doubleToString(double value);
    
    bool withdraw(const string &amount) override;
    void deposit(const string &amount) override;
    bool transfer(Account &toAccount, const string &amount) override;

    friend istream &operator>>(istream &is, BusinessAccount &account);
};

#endif // BUSINESS_ACCOUNT_H
