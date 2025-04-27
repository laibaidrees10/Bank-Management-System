#include "specialCitizenAccount.h"

SpecialCitizenAccount::SpecialCitizenAccount() : fixedAmountPerMonth(0.0), depositLimit(0.0) {}

SpecialCitizenAccount::SpecialCitizenAccount(string aN, Person aH, string bL, string support, double fixedAmount, double Limit)
    : Account(aN, aH, bL), supporter(support), fixedAmountPerMonth(fixedAmount), depositLimit(Limit) {}

SpecialCitizenAccount::SpecialCitizenAccount(SpecialCitizenAccount &other)
{
    accountNumber = other.accountNumber;
    accountHolder = other.accountHolder;
    balance = other.balance;
    supporter = other.supporter;
    fixedAmountPerMonth = other.fixedAmountPerMonth;
    depositLimit = other.depositLimit;
}

void SpecialCitizenAccount::display()
{
    cout << "Special Citizen Account: " << getAccountNumber() << "\n";
    getAccountHolder().display();
    cout << "Balance: " << getBalance() << "\n";
    cout << "Supporter: " << supporter << "\n";
    cout << "Fixed Amount Per Month: " << fixedAmountPerMonth << "\n";
    cout << "Deposit Limit: " << depositLimit << "\n";
}

bool SpecialCitizenAccount::withdraw(const string &amount)
{
    double withdrawAmount = stringToDouble(amount);
    double currentBalance = stringToDouble(getBalance());
    if (currentBalance >= withdrawAmount)
    {
        currentBalance -= withdrawAmount;
        setBalance(doubleToString(currentBalance));
        addTransaction(new Transaction(getAccountHolder().getId(), getAccountHolder().getFirstName(), 0, "", withdrawAmount, Date()));
        return true;
    }
    else
    {
        cout << "Insufficient balance for withdrawal." << endl;
        return false;
    }
}

void SpecialCitizenAccount::deposit(const string &amount)
{
    double depositAmount = stringToDouble(amount);
    if (depositAmount <= depositLimit)
    {
        double currentBalance = stringToDouble(getBalance());
        currentBalance += depositAmount;
        setBalance(doubleToString(currentBalance));
        addTransaction(new Transaction(0, "", getAccountHolder().getId(), getAccountHolder().getFirstName(), depositAmount, Date()));
    }
    else
    {
        cout << "Deposit amount exceeds the limit." << endl;
    }
}

bool SpecialCitizenAccount::transfer(Account &toAccount, const string &amount)
{
    cout << "Transfer functionality is not allowed for Special Citizen account." << endl;
    return false;
}

istream &operator>>(istream &is, SpecialCitizenAccount &account)
{
    string accountNumber, balance, supporter;
    double fixedAmountPerMonth, depositLimit;

    cout << "Enter Account Number: ";
    is >> accountNumber;

    cout << "Enter Balance: ";
    is >> balance;

    cout << "Enter Supporter: ";
    is >> supporter;

    cout << "Enter Fixed Amount Per Month: ";
    is >> fixedAmountPerMonth;

    cout << "Enter Deposit Limit: ";
    is >> depositLimit;

    cout << "Enter Account Holder Information: ";
    is >> account.accountHolder;

    account.accountNumber = accountNumber;
    account.setBalance(balance);
    account.supporter = supporter;
    account.fixedAmountPerMonth = fixedAmountPerMonth;
    account.depositLimit = depositLimit;

    return is;
}
