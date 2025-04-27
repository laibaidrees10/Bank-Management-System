#include "transaction.h"

int Transaction::nextTransactionId = 1;

Transaction::Transaction(int sender, string name, int reciever, string rName, double amount, Date date)
{
    transactionId = nextTransactionId++;
    senderId = sender;
    senderName = name;
    receiverId = reciever;
    receiverName = rName;
    this->amount = amount;
    this->date = date;
}

int Transaction::getTransactionId()
{
    return transactionId;
}

int Transaction::getSenderId()
{
    return senderId;
}

string Transaction::getSenderName()
{
    return senderName;
}

int Transaction::getReceiverId()
{
    return receiverId;
}

string Transaction::getReceiverName()
{
    return receiverName;
}

double Transaction::getAmount()
{
    return amount;
}

Date Transaction::getDate()
{
    return date;
}

void Transaction::display()
{
    cout << "Transaction ID: " << transactionId << "\n"
         << "Sender: " << senderName << " (ID: " << senderId << ")\n"
         << "Receiver: " << receiverName << " (ID: " << receiverId << ")\n"
         << "Amount: " << amount << "\n"
         << "Date: ";
    date.display();
}
