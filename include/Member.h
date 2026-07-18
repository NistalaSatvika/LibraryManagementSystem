#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>

class Member {
private:
    std::string memberID;
    std::string name;
    std::string email;
    int borrowLimit;
    std::vector<std::string> borrowedISBNs;

public:
    Member(const std::string& id, const std::string& name, const std::string& email, int limit = 5);

    // Getters
    std::string getID() const;
    std::string getName() const;
    std::string getEmail() const;
    int getBorrowLimit() const;
    int getBorrowedCount() const;
    const std::vector<std::string>& getBorrowedBooks() const;

    // Actions
    void borrowBook(const std::string& isbn);
    void returnBook(const std::string& isbn);
    void display() const;
};

#endif // MEMBER_H