#include "account.h"

Account::Account() : balance(nullptr) {}

Account::Account(string &accountNumber, Person &accountHolder, string &balance)
{
    this->accountNumber = accountNumber;
    this->accountHolder = accountHolder;
    this->balance = new char[balance.length() + 1];
    for (size_t i = 0; i < balance.length(); ++i)
    {
        this->balance[i] = balance[i];
    }
    this->balance[balance.length()] = '\0';
}

Account::~Account()
{
    delete[] balance;
    for (Transaction *transaction : transactionHistory)
    {
        delete transaction;
    }
}

int Account::getNumTransactions() const
{
    return transactionHistory.size();
}

const vector<Transaction *> &Account::getTransactionHistory() const
{
    return transactionHistory;
}

void Account::addTransactionToHistory(Transaction *transaction)
{
    transactionHistory.push_back(transaction);
}

void Account::displayHistory() const
{
    cout << "Transaction History:" << endl;
    for (Transaction *transaction : transactionHistory)
    {
        transaction->display();
    }
}

double Account::stringToDouble(string str)
{
    double result = 0.0;
    int dotIndex = -1;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == '.')
        {
            dotIndex = i;
            break;
        }
        if (isdigit(str[i]))
        {
            result = result * 10 + (str[i] - '0');
        }
    }
    if (dotIndex != -1)
    {
        double decimalPart = 0.0;
        double divisor = 1.0;
        for (size_t i = dotIndex + 1; i < str.size(); ++i)
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

string Account::doubleToString(double value) const
{
    string str = to_string(value);
    size_t dotIndex = str.find('.');
    if (dotIndex != string::npos && dotIndex + 3 < str.length())
    {
        str = str.substr(0, dotIndex + 3);
    }
    return str;
}

string Account::getCNIC() const
{
    return cnic;
}

string Account::getAccountNumber() const
{
    return accountNumber;
}

Person Account::getAccountHolder()
{
    return accountHolder;
}

void Account::addTransaction(Transaction *transaction)
{
    addTransactionToHistory(transaction);
}

void Account::setBalance(const string &newBalance)
{
    delete[] balance;
    balance = new char[newBalance.length() + 1];
    copy(newBalance.begin(), newBalance.end(), balance);
    balance[newBalance.length()] = '\0';
}

string Account::getBalance() const
{
    return string(balance);
}

void Account::checkBalance() const
{
    cout << "Current Balance: " << getBalance() << endl;
}

void Account::viewTransactionHistory() const
{
    displayHistory();
}
