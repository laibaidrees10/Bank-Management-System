#ifndef CREDIT_ACCOUNT_H
#define CREDIT_ACCOUNT_H

#include <iostream>
#include <string>
#include "account.h"

class CreditAccount : public Account
{
private:
    double withdrawalCharge;
    double transferCharge;
    double depositLimit;
    double withdrawalLimit;
    double transferLimit;

public:
    CreditAccount();
    CreditAccount(std::string aN, Person aH, std::string bL, double withdraw, double transfer, double deposit, double wLimit, double tLimit);

    void display() override;
    bool withdraw(const std::string &amount) override;
    void deposit(const std::string &amount) override;
    bool transfer(Account &toAccount, const std::string &amount) override;

    friend std::istream &operator>>(std::istream &is, CreditAccount &account);
};

#endif // CREDIT_ACCOUNT_H
