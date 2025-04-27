#include "studentAccount.h"

StudentAccount::StudentAccount()
{
    depositLimit = 50000;
    withdrawalLimit = 0;
    transferLimit = 0;
    withdrawalCharge = 25;
    transferCharge = 5;
    numOfTransactionsToday = 0;
}

StudentAccount::StudentAccount(string accountNumber, Person accountHolder, string balance)
    : Account(accountNumber, accountHolder, balance)
{
    depositLimit = 50000;
    withdrawalLimit = 0;
    transferLimit = 0;
    withdrawalCharge = 25;
    transferCharge = 5;
    numOfTransactionsToday = 0;
}

void StudentAccount::display()
{
    cout << "Student Account: " << getAccountNumber() << "\n";
    getAccountHolder().display();
    cout << "Balance: " << getBalance() << "\n";
    cout << "Deposit Limit: " << depositLimit << "\n";
    cout << "Withdrawal Limit: " << withdrawalLimit << "\n";
    cout << "Transfer Limit: " << transferLimit << "\n";
}

bool StudentAccount::withdraw(const string &amount)
{
    if (numOfTransactionsToday >= 1)
    {
        cout << "Maximum number of transactions reached for today." << endl;
        return false;
    }
    double withdrawAmount = stringToDouble(amount);
    if (withdrawAmount > depositLimit * 0.9)
    {
        cout << "Withdrawal amount exceeds 90% of the balance limit." << endl;
        return false;
    }
    double currentBalance = stringToDouble(getBalance());
    if (withdrawAmount + withdrawalCharge > currentBalance)
    {
        cout << "Insufficient balance for withdrawal." << endl;
        return false;
    }
    currentBalance -= (withdrawAmount + withdrawalCharge);
    setBalance(doubleToString(currentBalance));
    Transaction *newTransaction = new Transaction(getAccountHolder().getId(), getAccountHolder().getFirstName(), 0, "", withdrawAmount, Date());
    addTransaction(newTransaction);
    numOfTransactionsToday++;
    return true;
}

void StudentAccount::deposit(const string &amount)
{
    double depositAmount = stringToDouble(amount);
    double currentBalance = stringToDouble(getBalance());
    currentBalance += depositAmount;
    setBalance(doubleToString(currentBalance));
    Transaction *newTransaction = new Transaction(0, "", getAccountHolder().getId(), getAccountHolder().getFirstName(), depositAmount, Date());
    addTransaction(newTransaction);
}

bool StudentAccount::transfer(Account &toAccount, const string &amount)
{
    if (numOfTransactionsToday >= 1)
    {
        cout << "Maximum number of transactions reached for today." << endl;
        return false;
    }
    double transferAmount = stringToDouble(amount);
    if (transferAmount > transferLimit)
    {
        cout << "Transfer amount exceeds the limit." << endl;
        return false;
    }
    double currentBalance = stringToDouble(getBalance());
    if (transferAmount + transferCharge > currentBalance)
    {
        cout << "Insufficient balance for transfer." << endl;
        return false;
    }
    if (toAccount.getAccountNumber() == getAccountNumber())
    {
        cout << "Cannot transfer to the same account." << endl;
        return false;
    }
    currentBalance -= (transferAmount + transferCharge);
    setBalance(doubleToString(currentBalance));
    toAccount.deposit(amount);
    Transaction *newTransaction = new Transaction(getAccountHolder().getId(), getAccountHolder().getFirstName(),
                                                  toAccount.getAccountHolder().getId(), "", transferAmount, Date());
    addTransaction(newTransaction);
    numOfTransactionsToday++;
    return true;
}

istream &operator>>(istream &is, StudentAccount &account)
{
    string accountNumber, cnic, balance;
    cout << "Enter Account Number: ";
    is >> accountNumber;
    cout << "Enter CNIC: ";
    is >> cnic;
    cout << "Enter Initial Balance: ";
    is >> balance;

    Person accountHolder;
    cout << "Enter Account Holder Information: ";
    is >> accountHolder;

    account.accountNumber = accountNumber;
    account.accountHolder = accountHolder;
    account.depositLimit = 50000;
    account.withdrawalLimit = 0;
    account.transferLimit = 0;
    account.withdrawalCharge = 25;
    account.transferCharge = 5;
    account.numOfTransactionsToday = 0;

    return is;
}
