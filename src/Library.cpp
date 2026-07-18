#include "Library.h"

void Library::addBook(std::shared_ptr<Book> book) {
    books[book->getISBN()] = book;
}

void Library::addMember(std::shared_ptr<Member> member) {
    members[member->getID()] = member;
}

void Library::saveToFile(const std::string& filename) const {
    std::ofstream ofs(filename, std::ios::binary);
    size_t count = books.size();
    ofs.write((char*)&count, sizeof(count));
    for (const auto& pair : books) {
        pair.second->serialize(ofs);
    }
}

void Library::loadFromFile(const std::string& filename) {
    std::ifstream ifs(filename, std::ios::binary);
    if (!ifs) return;
    size_t count;
    ifs.read((char*)&count, sizeof(count));
    for (size_t i = 0; i < count; ++i) {
        auto b = Book::deserialize(ifs);
        books[b->getISBN()] = b;
    }
}