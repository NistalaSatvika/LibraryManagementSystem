#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include "Book.h"

class Audiobook : public Book {
private:
    int durationMinutes;
    std::string narrator;

public:
    Audiobook(const std::string& isbn, const std::string& title, 
              const std::string& author, int duration, const std::string& narrator);

    // Override the base class display function
    void display() const override;
};

#endif // AUDIOBOOK_H