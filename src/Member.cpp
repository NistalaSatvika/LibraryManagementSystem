#include "Member.h"
#include "Exceptions.h"
#include <iostream>
#include <algorithm>

Member::Member(const std::string& id, const std::string& name, const std::string& email, int limit)
    : memberID(id), name(name), email(email), borrowLimit(limit) {}

std::string Member::getID() const { return memberID; }
std::string Member::getName() const { return name; }
std::string Member::getEmail() const { return email; }
int Member::getBorrowLimit() const { return borrowLimit; }
int Member::getBorrowedCount() const { return borrowedISBNs.size(); }
const std::vector<std::string>& Member::getBorrowedBooks() const { return borrowedISBNs; }

void Member::borrowBook(const std::string& isbn) {
    if (borrowedISBNs.size() >= static_cast<size_t>(borrowLimit)) {
        throw LimitExceededException(name);
    }
    
    // Check if they already borrowed this exact book (duplicate check)
    if (std::find(borrowedISBNs.begin(), borrowedISBNs.end(), isbn) != borrowedISBNs.end()) {
        throw InvalidInputException("Member already borrowed book with ISBN: " + isbn);
    }

    borrowedISBNs.push_back(isbn);
}

void Member::returnBook(const std::string& isbn) {
    auto it = std::find(borrowedISBNs.begin(), borrowedISBNs.end(), isbn);
    if (it != borrowedISBNs.end()) {
        borrowedISBNs.erase(it);
    } else {
        throw InvalidInputException("Member does not have book with ISBN: " + isbn);
    }
}

void Member::display() const {
    std::cout << "ID: " << memberID << " | Name: " << name 
              << " | Email: " << email 
              << " | Books Borrowed: " << borrowedISBNs.size() << "/" << borrowLimit;
}
