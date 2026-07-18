#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Date.h"

class Transaction {
private:
    std::string transactionID;
    std::string memberID;
    std::string isbn;
    Date issueDate;
    Date dueDate;
    Date returnDate;
    bool returned;
    double fineAmount;

public:
    Transaction(const std::string& tID, const std::string& mID, const std::string& bookISBN, const Date& issue, const Date& due);

    // Getters
    std::string getTransactionID() const;
    std::string getMemberID() const;
    std::string getISBN() const;
    Date getIssueDate() const;
    Date getDueDate() const;
    bool isReturned() const;
    double getFineAmount() const;

    // Actions
    void markReturned(const Date& retDate, double fineRate);
    void display() const;
};

#endif // TRANSACTION_H