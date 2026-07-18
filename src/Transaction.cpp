#include "Transaction.h"
#include <iostream>

Transaction::Transaction(const std::string& tID, const std::string& mID, const std::string& bookISBN, const Date& issue, const Date& due)
    : transactionID(tID), memberID(mID), isbn(bookISBN), issueDate(issue), dueDate(due), returned(false), fineAmount(0.0) {}

std::string Transaction::getTransactionID() const { return transactionID; }
std::string Transaction::getMemberID() const { return memberID; }
std::string Transaction::getISBN() const { return isbn; }
Date Transaction::getIssueDate() const { return issueDate; }
Date Transaction::getDueDate() const { return dueDate; }
bool Transaction::isReturned() const { return returned; }
double Transaction::getFineAmount() const { return fineAmount; }

void Transaction::markReturned(const Date& retDate, double fineRate) {
    returnDate = retDate;
    returned = true;
    
    // Uses the overloaded operator- from our Date class
    int overdueDays = returnDate - dueDate;
    if (overdueDays > 0) {
        fineAmount = overdueDays * fineRate;
    } else {
        fineAmount = 0.0;
    }
}

void Transaction::display() const {
    std::cout << "Txn ID: " << transactionID 
              << " | Member: " << memberID 
              << " | ISBN: " << isbn 
              << "\n  Issued: " << issueDate.toString() 
              << " | Due: " << dueDate.toString();
              
    if (returned) {
        std::cout << " | Returned: " << returnDate.toString() 
                  << " | Fine: $" << fineAmount << "\n";
    } else {
        std::cout << " | Status: Active\n";
    }
}