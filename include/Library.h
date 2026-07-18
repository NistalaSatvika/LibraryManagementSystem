#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <unordered_map>
#include <memory>
#include <fstream>
#include "Book.h"
#include "Member.h"
#include "Transaction.h"
#include "ConfigReader.h"

class Library {
private:
    std::unordered_map<std::string, std::shared_ptr<Book>> books;
    std::unordered_map<std::string, std::shared_ptr<Member>> members;
    std::vector<std::shared_ptr<Transaction>> transactions;
    ConfigReader config;

public:
    void addBook(std::shared_ptr<Book> book);
    void addMember(std::shared_ptr<Member> member);
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif