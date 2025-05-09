#include "Bank.h"

Bank::Bank(string name)
{
    bankName = name;
    numAccounts = 0;
    totalBalance = 0.0;
    totalInterestToPay = 0.0;
    totalProfit = 0.0;
    capacity = 10;
    accounts = new Account *[capacity];
}

Bank::~Bank()
{
    for (int i = 0; i < numAccounts; ++i)
    {
        delete accounts[i];
    }
    delete[] accounts;
}

string Bank::getName()
{
    return bankName;
}

void Bank::addAccount(Account *account)
{
    if (numAccounts == capacity)
    {
        resizeAccounts();
    }
    accounts[numAccounts++] = account;
    totalBalance += account->stringToDouble(account->getBalance());
}

void Bank::resizeAccounts()
{
    capacity *= 2;
    Account **newAccounts = new Account *[capacity];
    for (int i = 0; i < numAccounts; ++i)
    {
        newAccounts[i] = accounts[i];
    }
    delete[] accounts;
    accounts = newAccounts;
}

void Bank::displayAllAccounts()
{
    for (int i = 0; i < numAccounts; ++i)
    {
        accounts[i]->display();
        cout << "--------------------------" << endl;
    }
}

Account *Bank::findAccount(const string &accountNumber) const
{
    for (size_t i = 0; i < numAccounts; ++i)
    {
        if (accounts[i]->getAccountNumber() == accountNumber)
        {
            return accounts[i];
        }
    }
    return nullptr;
}

void Bank::displayAccountHistory(const string &accountNumber) const
{
    Account *account = findAccount(accountNumber);
    if (account)
    {
        cout << "Transaction History for Account " << accountNumber << ":\n";
        account->displayHistory();
    }
    else
    {
        cerr << "Account not found." << endl;
    }
}

void Bank::viewAccountsByCNIC(const string &cnic)
{
    bool found = false;
    for (int i = 0; i < numAccounts; ++i)
    {
        if (accounts[i]->getCNIC() == cnic)
        {
            accounts[i]->display();
            cout << "--------------------------" << endl;
            found = true;
        }
    }
    if (!found)
    {
        cout << "No accounts found for the provided CNIC." << endl;
    }
}

void Bank::withdraw(const string &accountNumber, double amount)
{
    Account *account = findAccount(accountNumber);
    if (account)
    {
        string amountStr = account->doubleToString(amount);
        if (account->withdraw(amountStr))
        {
            totalBalance -= amount;
            cout << "Withdrawal successful." << endl;
        }
        else
        {
            cout << "Withdrawal failed." << endl;
        }
    }
    else
    {
        cout << "Account not found." << endl;
    }
}

void Bank::deposit(const string &accountNumber, double amount)
{
    Account *account = findAccount(accountNumber);
    if (account)
    {
        string amountStr = account->doubleToString(amount);
        account->deposit(amountStr);
        totalBalance += amount;
        cout << "Deposit successful." << endl;
    }
    else
    {
        cout << "Account not found." << endl;
    }
}

void Bank::performTransaction(const string &fromAccount, const string &toAccount, const string &amountStr)
{
    Account *sender = findAccount(fromAccount);
    Account *receiver = findAccount(toAccount);

    if (sender && receiver)
    {
        double amount = sender->stringToDouble(amountStr);
        if (amount < 0)
        {
            cout << "Invalid amount: " << amountStr << endl;
            return;
        }

        if (sender->withdraw(amountStr))
        {
            receiver->deposit(amountStr);
            cout << "Transaction successful." << endl;
        }
        else
        {
            rollbackTransaction(sender, receiver, amount);
            cout << "Transaction failed." << endl;
        }
    }
    else
    {
        cout << "One or both accounts not found." << endl;
    }
}

void Bank::getAccountHistory(const string &accountNumber)
{
    Account *account = findAccount(accountNumber);
    if (account)
    {
        account->displayHistory();
    }
    else
    {
        cout << "Account not found." << endl;
    }
}

void Bank::provideLoan(const string &accountNumber, double amount)
{
    Account *account = findAccount(accountNumber);
    if (account)
    {
        LoanAccount *loanAccount = dynamic_cast<LoanAccount *>(account);
        if (loanAccount)
        {
            loanAccount->provideLoan(amount);
            totalProfit += amount;
            cout << "Loan provided successfully." << endl;
        }
        else
        {
            cout << "Account is not a Loan Account." << endl;
        }
    }
    else
    {
        cout << "Account not found." << endl;
    }
}

void Bank::getLoanBack(const string &accountNumber, double amount)
{
    Account *account = findAccount(accountNumber);
    if (account)
    {
        LoanAccount *loanAccount = dynamic_cast<LoanAccount *>(account);
        if (loanAccount)
        {
            loanAccount->getLoanBack(amount);
            totalBalance -= amount;
            cout << "Loan repayment successful." << endl;
        }
        else
        {
            cout << "Account is not a Loan Account." << endl;
        }
    }
    else
    {
        cout << "Account not found." << endl;
    }
}

void Bank::rollbackTransaction(Account *sender, Account *receiver, double amount)
{
    string amountStr = sender->doubleToString(amount);
    if (sender)
        sender->deposit(amountStr);
    if (receiver)
        receiver->withdraw(amountStr);
}
