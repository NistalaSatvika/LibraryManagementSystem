#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class LibraryException : public std::runtime_error {
public:
    explicit LibraryException(const std::string& message) : std::runtime_error(message) {}
};

class DuplicateISBNException : public LibraryException {
public:
    explicit DuplicateISBNException(const std::string& isbn) 
        : LibraryException("Error: Book with ISBN " + isbn + " already exists.") {}
};

class DuplicateMemberException : public LibraryException {
public:
    explicit DuplicateMemberException(const std::string& id) 
        : LibraryException("Error: Member with ID " + id + " already exists.") {}
};

class BookUnavailableException : public LibraryException {
public:
    explicit BookUnavailableException(const std::string& title) 
        : LibraryException("Error: Book '" + title + "' is currently unavailable.") {}
};

class MemberNotFoundException : public LibraryException {
public:
    explicit MemberNotFoundException(const std::string& id) 
        : LibraryException("Error: Member with ID " + id + " not found.") {}
};

class LimitExceededException : public LibraryException {
public:
    explicit LimitExceededException(const std::string& memberName) 
        : LibraryException("Error: Borrow limit exceeded for member " + memberName + ".") {}
};

class InvalidInputException : public LibraryException {
public:
    explicit InvalidInputException(const std::string& message) 
        : LibraryException("Invalid Input: " + message) {}
};

class FileNotFoundException : public LibraryException {
public:
    explicit FileNotFoundException(const std::string& filename) 
        : LibraryException("File Error: Cannot open file " + filename) {}
};

#endif // EXCEPTIONS_H