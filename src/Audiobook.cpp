#include "Audiobook.h"
#include <iostream>

Audiobook::Audiobook(const std::string& isbn, const std::string& title, 
                     const std::string& author, int duration, const std::string& narrator)
    : Book(isbn, title, author), durationMinutes(duration), narrator(narrator) {}

void Audiobook::display() const {
    Book::display(); // Call the base class logic first
    std::cout << " | Duration: " << durationMinutes << " mins"
              << " | Narrator: " << narrator;
}