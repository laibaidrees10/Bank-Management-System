#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>
#include "date.h"

using namespace std;

class Transaction
{
private:
    int transactionId;
    int senderId;
    string senderName;
    int receiverId;
    string receiverName;
    double amount;
    Date date;

public:
    static int nextTransactionId;

    Transaction(int sender, string name, int reciever, string rName, double amount, Date date);

    int getTransactionId();
    int getSenderId();
    string getSenderName();
    int getReceiverId();
    string getReceiverName();
    double getAmount();
    Date getDate();

    void display();
};

#endif // TRANSACTION_H
