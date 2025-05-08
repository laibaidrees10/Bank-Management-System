#include "creditAccount.h"

CreditAccount::CreditAccount() {}

CreditAccount::CreditAccount(std::string aN, Person aH, std::string bL, double withdraw, double transfer, double deposit, double wLimit, double tLimit)
    : Account(aN, aH, bL)
{
    withdrawalCharge = withdraw;
    transferCharge = transfer;
    depositLimit = deposit;
    withdrawalLimit = wLimit;
    transferLimit = tLimit;
}

void CreditAccount::display()
{
    std::cout << "Credit Account: " << getAccountNumber() << "\n";
    getAccountHolder().display();
    std::cout << "Balance: " << getBalance() << "\n";
    std::cout << "Withdrawal Charge: " << withdrawalCharge << "\n";
    std::cout << "Transfer Charge: " << transferCharge << "\n";
    std::cout << "Deposit Limit: " << depositLimit << "\n";
    std::cout << "Withdrawal Limit: " << withdrawalLimit << "\n";
    std::cout << "Transfer Limit: " << transferLimit << "\n";
}

bool CreditAccount::withdraw(const std::string &amount)
{
    double withdrawAmount = stringToDouble(amount);
    double currentBalance = stringToDouble(getBalance());
    if (currentBalance >= withdrawAmount + withdrawalCharge)
    {
        currentBalance -= (withdrawAmount + withdrawalCharge);
        setBalance(doubleToString(currentBalance));
        addTransaction(new Transaction(getAccountHolder().getId(), getAccountHolder().getFirstName(), 0, "", withdrawAmount, Date()));
        return true;
    }
    else
    {
        std::cout << "Insufficient balance for withdrawal." << std::endl;
        return false;
    }
}

void CreditAccount::deposit(const std::string &amount)
{
    double depositAmount = stringToDouble(amount);
    double currentBalance = stringToDouble(getBalance());
    currentBalance += depositAmount;
    setBalance(doubleToString(currentBalance));
    addTransaction(new Transaction(0, "", getAccountHolder().getId(), getAccountHolder().getFirstName(), depositAmount, Date()));
}

bool CreditAccount::transfer(Account &toAccount, const std::string &amount)
{
    std::cout << "Enter 'yes' if the bank is the same, otherwise 'no': ";
    std::string response;
    std::cin >> response;
    if (response == "yes")
    {
        transferCharge = 0;
    }

    double transferAmount = stringToDouble(amount);
    double currentBalance = stringToDouble(getBalance());
    if (currentBalance >= transferAmount + transferCharge)
    {
        currentBalance -= (transferAmount + transferCharge);
        setBalance(doubleToString(currentBalance));
        toAccount.deposit(amount);
        addTransaction(new Transaction(getAccountHolder().getId(), getAccountHolder().getFirstName(), toAccount.getAccountHolder().getId(), "", transferAmount, Date()));
        return true;
    }
    else
    {
        std::cout << "Insufficient balance for transfer." << std::endl;
        return false;
    }
}

std::istream &operator>>(std::istream &is, CreditAccount &account)
{
    std::string accountNumber, balance;
    Person accountHolder;
    double withdrawCharge, transferCharge, depositLimit, withdrawalLimit, transferLimit;

    std::cout << "Enter account number: ";
    is >> accountNumber;
    std::cout << "Enter balance: ";
    is >> balance;
    std::cout << "Enter account holder details:\n";
    is >> accountHolder;
    std::cout << "Enter withdrawal charge: ";
    is >> withdrawCharge;
    std::cout << "Enter transfer charge: ";
    is >> transferCharge;
    std::cout << "Enter deposit limit: ";
    is >> depositLimit;
    std::cout << "Enter withdrawal limit: ";
    is >> withdrawalLimit;
    std::cout << "Enter transfer limit: ";
    is >> transferLimit;

    account = CreditAccount(accountNumber, accountHolder, balance, withdrawCharge, transferCharge, depositLimit, withdrawalLimit, transferLimit);
    return is;
}
