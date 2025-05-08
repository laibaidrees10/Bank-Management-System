#include "bussinessAccount.h"

BusinessAccount::BusinessAccount() : negativeBalance(0.0) {}

BusinessAccount::BusinessAccount(string aN, Person aH, string bL) : Account(aN, aH, bL), negativeBalance(0.0) {}

void BusinessAccount::display()
{
    cout << "Business Account: " << getAccountNumber() << "\n";
    getAccountHolder().display();
    cout << "Balance: " << getBalance() << "\n";
    cout << "Negative Balance: " << negativeBalance << "\n";
}

double BusinessAccount::stringToDouble(string str)
{
    double result = 0.0;
    int Index = str.find('.');
    for (int i = 0; i < str.size(); ++i)
    {
        if (isdigit(str[i]))
        {
            result = result * 10 + (str[i] - '0');
        }
        if (i == Index)
        {
            break;
        }
    }
    if (Index != -1)
    {
        double decimalPart = 0.0;
        double divisor = 1.0;
        for (int i = Index + 1; i < str.size(); ++i)
        {
            if (isdigit(str[i]))
            {
                decimalPart = decimalPart * 10 + (str[i] - '0');
                divisor *= 10;
            }
        }
        result += decimalPart / divisor;
    }
    return result;
}

string BusinessAccount::doubleToString(double value)
{
    string str;
    if (value < 0)
    {
        str.push_back('-');
        value = -value;
    }
    int integerPart = static_cast<int>(value);
    while (integerPart > 0)
    {
        str.insert(str.begin(), '0' + (integerPart % 10));
        integerPart /= 10;
    }
    str.push_back('.');
    double fractionalPart = value - static_cast<int>(value);
    for (int i = 0; i < 2; ++i)
    {
        fractionalPart *= 10;
        int digit = static_cast<int>(fractionalPart) % 10;
        str.push_back('0' + digit);
    }
    return str;
}

bool BusinessAccount::withdraw(const string &amount)
{
    double withdrawAmount = stringToDouble(amount);
    double currentBalance = stringToDouble(getBalance());
    if (withdrawAmount > currentBalance)
    {
        negativeBalance += (withdrawAmount - currentBalance);
    }
    else
    {
        currentBalance -= withdrawAmount;
        setBalance(doubleToString(currentBalance));
    }
    Transaction *newTransaction = new Transaction(getAccountHolder().getId(), getAccountHolder().getFirstName(), 0, "", withdrawAmount, Date());
    addTransaction(newTransaction);
    return true;
}

void BusinessAccount::deposit(const string &amount)
{
    double depositAmount = stringToDouble(amount);
    double currentBalance = stringToDouble(getBalance());
    currentBalance += depositAmount;
    setBalance(doubleToString(currentBalance));
    Transaction *newTransaction = new Transaction(0, "", getAccountHolder().getId(), getAccountHolder().getFirstName(), depositAmount, Date());
    addTransaction(newTransaction);
}

bool BusinessAccount::transfer(Account &toAccount, const string &amount)
{
    double transferAmount = stringToDouble(amount);
    if (withdraw(amount))
    {
        toAccount.deposit(amount);
        return true;
    }
    return false;
}

istream &operator>>(istream &is, BusinessAccount &account)
{
    string balance;
    cout << "Enter Account Number: ";
    is >> account.accountNumber;
    cout << "Enter Balance: ";
    is >> balance;

    Person accountHolder;
    cout << "Enter Account Holder Information: ";
    is >> accountHolder;

    account.accountHolder;
    account.setBalance(balance);
    account.negativeBalance = 0.0;

    return is;
}
