#include "savingAccount.h"

SavingsAccount::SavingsAccount() : balance(0.0), interestRate(0.0), timePeriod(0) {}

SavingsAccount::SavingsAccount(string aN, Person aH, string bL, Date startDate, int time, double interest)
    : Account(aN, aH, bL), packageStartDate(startDate), timePeriod(time), interestRate(interest)
{
}

double SavingsAccount::calculateRepaymentAmount()
{
    return balance * interestRate;
}

void SavingsAccount::display()
{
    cout << "Savings Account: " << getAccountNumber() << "\n";
    getAccountHolder().display();
    cout << "Balance: " << getBalance() << "\n";
    cout << "Package Start Date: ";
    packageStartDate.display();
    cout << "Time Period: " << timePeriod << " months\n";
    cout << "Interest Rate: " << interestRate << "%\n";
}

bool SavingsAccount::withdraw(const string &amount)
{
    cout << "Withdrawal is not allowed until the time period is complete." << endl;
    return false;
}

void SavingsAccount::deposit(const string &amount)
{
    double depositAmount = stringToDouble(amount);
    double currentBalance = stringToDouble(getBalance());
    currentBalance += depositAmount;
    setBalance(doubleToString(currentBalance));
    Transaction *newTransaction = new Transaction(0, "", getAccountHolder().getId(), getAccountHolder().getFirstName(), depositAmount, Date());
    addTransaction(newTransaction);
}

bool SavingsAccount::transfer(Account &toAccount, const string &amount)
{
    cout << "Transfer functionality is not allowed for Savings account." << endl;
    return false;
}

istream &operator>>(istream &is, SavingsAccount &account)
{
    string accountNumber, balance;
    double interestRate;
    int timePeriod;
    Date packageStartDate;

    cout << "Enter Account Number: ";
    is >> account.accountNumber;

    cout << "Enter Balance: ";
    is >> balance;

    cout << "Enter Interest Rate: ";
    is >> interestRate;

    cout << "Enter Time Period (in months): ";
    is >> timePeriod;

    cout << "Enter Package Start Date (dd mm yyyy): ";
    is >> packageStartDate;

    Person accountHolder;
    cout << "Enter Account Holder Information: ";
    is >> accountHolder;

    account.setBalance(balance);
    account.interestRate = interestRate;
    account.timePeriod = timePeriod;
    account.packageStartDate = packageStartDate;
    account.accountHolder = accountHolder;

    return is;
}
