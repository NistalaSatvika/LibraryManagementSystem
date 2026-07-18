#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
#include <memory>

class Book {
private:
    std::string isbn;
    std::string title;
    std::string author;
    bool available;

public:
    Book(const std::string& isbn, const std::string& title, const std::string& author);
    virtual ~Book() = default;

    std::string getISBN() const { return isbn; }
    std::string getTitle() const { return title; }
    std::string getAuthor() const { return author; }
    bool isAvailable() const { return available; }
    void setAvailable(bool status) { available = status; }

    virtual void display() const;
    void serialize(std::ostream& os) const;
    static std::shared_ptr<Book> deserialize(std::istream& is);
};

#endif