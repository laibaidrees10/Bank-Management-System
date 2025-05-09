#include <iostream>
#include <string>
#include "Bank.h"
using namespace std;

void displayMenu()
{
    cout << "1. Add Account" << endl;
    cout << "2. Display All Accounts" << endl;
    cout << "3. View Account by CNIC" << endl;
    cout << "4. Withdraw from Account" << endl;
    cout << "5. Deposit to Account" << endl;
    cout << "6. Perform Transaction" << endl;
    cout << "7. Display Account History" << endl;
    cout << "8. Provide Loan" << endl;
    cout << "9. Get Loan Back" << endl;
    cout << "10. Exit" << endl;
    cout << "Enter your choice: ";
}

void displayAccountTypes()
{
    cout << "Choose Account Type:" << endl;
    cout << "1. Student Account" << endl;
    cout << "2. Credit Account" << endl;
    cout << "3. Business Account" << endl;
    cout << "4. Savings Account" << endl;
    cout << "5. Loan Account" << endl;
    cout << "6. Special Citizen Account" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    string bankName;
    cout << "Enter Bank Name: ";
    getline(cin, bankName);
    Bank bank(bankName);

    int choice;
    do
    {
        displayMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            string accountNumber, cnic, balance;
            int accountType;
            displayAccountTypes();
            cin >> accountType;
            cin.ignore();

            cout << "Enter Account Number: ";
            getline(cin, accountNumber);
            cout << "Enter CNIC: ";
            getline(cin, cnic);
            cout << "Enter Initial Balance: ";
            getline(cin, balance);

            Person accountHolder;
            cin >> accountHolder;

            Account *account = nullptr;
            if (accountType == 1)
            {
                StudentAccount newAccount;
                cin >> newAccount;
                account = new StudentAccount(newAccount);
            }
            else if (accountType == 2)
            {
                CreditAccount newAccount;
                cin >> newAccount;
                account = new CreditAccount(newAccount);
            }
            else if (accountType == 3)
            {
                BusinessAccount newAccount;
                cin >> newAccount;
                account = new BusinessAccount(newAccount);
            }
            else if (accountType == 4)
            {
                SavingsAccount newAccount;
                cin >> newAccount;
                account = new SavingsAccount(newAccount);
            }
            else if (accountType == 5)
            {
                LoanAccount newAccount;
                cin >> newAccount;
                account = new LoanAccount(newAccount);
            }
            else if (accountType == 6)
            {
                SpecialCitizenAccount newAccount;
                cin >> newAccount;
                account = new SpecialCitizenAccount(newAccount);
            }
            else
            {
                cout << "Invalid account type selected." << endl;
            }

            if (account != nullptr)
            {
                bank.addAccount(account);
            }
        }
        else if (choice == 2)
        {
            bank.displayAllAccounts();
        }
        else if (choice == 3)
        {
            string cnic;
            cout << "Enter CNIC: ";
            getline(cin, cnic);
            bank.viewAccountsByCNIC(cnic);
        }
        else if (choice == 4)
        {
            string accountNumber;
            double amount;
            cout << "Enter Account Number: ";
            getline(cin, accountNumber);
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            bank.withdraw(accountNumber, amount);
        }
        else if (choice == 5)
        {
            string accountNumber;
            double amount;
            cout << "Enter Account Number: ";
            getline(cin, accountNumber);
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            bank.deposit(accountNumber, amount);
        }
        else if (choice == 6)
        {
            string fromAccount, toAccount, amount;
            cout << "Enter From Account Number: ";
            getline(cin, fromAccount);
            cout << "Enter To Account Number: ";
            getline(cin, toAccount);
            cout << "Enter Amount to Transfer: ";
            getline(cin, amount);
            bank.performTransaction(fromAccount, toAccount, amount);
        }
        else if (choice == 7)
        {
            string accountNumber;
            cout << "Enter Account Number: ";
            getline(cin, accountNumber);
            bank.displayAccountHistory(accountNumber);
        }
        else if (choice == 8)
        {
            string accountNumber;
            double amount;
            cout << "Enter Account Number: ";
            getline(cin, accountNumber);
            cout << "Enter Loan Amount: ";
            cin >> amount;
            bank.provideLoan(accountNumber, amount);
        }
        else if (choice == 9)
        {
            string accountNumber;
            double amount;
            cout << "Enter Account Number: ";
            getline(cin, accountNumber);
            cout << "Enter Loan Repayment Amount: ";
            cin >> amount;
            bank.getLoanBack(accountNumber, amount);
        }
        else if (choice == 10)
        {
            cout << "Exiting..." << endl;
        }
        else
        {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 10);

    return 0;
}
