#ifndef LOAN_ACCOUNT_H
#define LOAN_ACCOUNT_H

#include <iostream>
#include <string>
#include "account.h"

class LoanAccount : public Account
{
private:
    double interestRate;
    double totalLoan;
    int timePeriod;
    double chargeRate;
    int loanTerm;
    double loanAmount;

public:
    LoanAccount();
    LoanAccount(std::string aN, Person aH, std::string bl, double interest, double loan, int time, double charge);
    LoanAccount(const LoanAccount &other);

    void provideLoan(double amount);
    void getLoanBack(double amount);
    void display() override;
    bool withdraw(const std::string &amount) override;
    void deposit(const std::string &amount) override;
    bool transfer(Account &toAccount, const std::string &amount) override;

    double calculateRepaymentAmount();

    friend std::istream &operator>>(std::istream &is, LoanAccount &account);
};

#endif // LOAN_ACCOUNT_H
