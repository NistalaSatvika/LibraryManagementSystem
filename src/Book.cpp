#include "Book.h"

// 1. Constructor
Book::Book(const std::string& isbn, const std::string& title, const std::string& author)
    : isbn(isbn), title(title), author(author), available(true) {}

// 2. Display
void Book::display() const {
    std::cout << "ISBN: " << isbn << " | Title: " << title << " | Author: " << author;
}

// 3. Serialize
void Book::serialize(std::ostream& os) const {
    size_t len = isbn.length(); os.write((char*)&len, sizeof(len)); os.write(isbn.c_str(), len);
    len = title.length(); os.write((char*)&len, sizeof(len)); os.write(title.c_str(), len);
    len = author.length(); os.write((char*)&len, sizeof(len)); os.write(author.c_str(), len);
    os.write((char*)&available, sizeof(available));
}

// 4. Deserialize
std::shared_ptr<Book> Book::deserialize(std::istream& is) {
    auto readStr = [&](std::istream& is) {
        size_t l; is.read((char*)&l, sizeof(l));
        std::string s(l, ' '); is.read(&s[0], l);
        return s;
    };
    std::string isbn = readStr(is);
    std::string title = readStr(is);
    std::string author = readStr(is);
    bool avail; is.read((char*)&avail, sizeof(avail));
    auto b = std::make_shared<Book>(isbn, title, author);
    b->setAvailable(avail);
    return b;
}