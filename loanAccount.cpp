#include "loanAccount.h"

LoanAccount::LoanAccount() {}

LoanAccount::LoanAccount(std::string aN, Person aH, std::string bl, double interest, double loan, int time, double charge)
    : Account(aN, aH, bl)
{
    interestRate = interest;
    totalLoan = loan;
    timePeriod = time;
    chargeRate = charge;
}

LoanAccount::LoanAccount(const LoanAccount &other)
{
    interestRate = other.interestRate;
    accountHolder = other.accountHolder;
    accountNumber = other.accountNumber;
    balance = other.balance;
    totalLoan = other.totalLoan;
    timePeriod = other.timePeriod;
    chargeRate = other.chargeRate;
}

void LoanAccount::provideLoan(double amount)
{
    loanAmount = amount;
    std::cout << "Loan of $" << amount << " provided." << std::endl;
}

void LoanAccount::getLoanBack(double amount)
{
    loanAmount -= amount;
}

void LoanAccount::display()
{
    std::cout << "Loan Account: " << getAccountNumber() << "\n";
    getAccountHolder().display();
    std::cout << "Balance: " << getBalance() << "\n";
    std::cout << "Interest Rate: " << interestRate << "\n";
    std::cout << "Total Loan: " << totalLoan << "\n";
    std::cout << "Time Period: " << timePeriod << " months\n";
    std::cout << "Charge Rate: " << chargeRate << "\n";
}

bool LoanAccount::withdraw(const std::string &amount)
{
    std::cout << "Loan Account does not support direct withdrawals." << std::endl;
    return false;
}

void LoanAccount::deposit(const std::string &amount)
{
    double depositAmount = stringToDouble(amount);
    double currentBalance = stringToDouble(getBalance());
    currentBalance += depositAmount;
    setBalance(doubleToString(currentBalance));
    addTransaction(new Transaction(0, "", getAccountHolder().getId(), getAccountHolder().getFirstName(), depositAmount, Date()));
}

bool LoanAccount::transfer(Account &toAccount, const std::string &amount)
{
    std::cout << "Transfer functionality is not allowed for Loan account." << std::endl;
    return false;
}

double LoanAccount::calculateRepaymentAmount()
{
    double interest = totalLoan * (interestRate / 100) * (timePeriod / 12.0);
    double totalRepayment = totalLoan + interest;
    if (totalRepayment > 0)
    {
        totalRepayment += totalRepayment * (chargeRate / 100);
    }
    return totalRepayment;
}

std::istream &operator>>(std::istream &is, LoanAccount &account)
{
    std::string accountNumber, balance;
    double interestRate, totalLoan, chargeRate;
    int timePeriod;

    std::cout << "Enter Account Number: ";
    is >> accountNumber;

    std::cout << "Enter Balance: ";
    is >> balance;

    std::cout << "Enter Interest Rate: ";
    is >> interestRate;

    std::cout << "Enter Total Loan: ";
    is >> totalLoan;

    std::cout << "Enter Time Period (in months): ";
    is >> timePeriod;

    std::cout << "Enter Charge Rate: ";
    is >> chargeRate;

    std::cout << "Enter Account Holder Information: ";
    is >> account.accountHolder;

    account.accountNumber = accountNumber;
    account.setBalance(balance);
    account.interestRate = interestRate;
    account.totalLoan = totalLoan;
    account.timePeriod = timePeriod;
    account.chargeRate = chargeRate;

    return is;
}
