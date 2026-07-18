#include <iostream>
#include "Library.h"

int main() {
    Library lib;
    
    // Test Adding
    lib.addBook(std::make_shared<Book>("123", "C++ Programming", "Stroustrup"));
    
    // Test Persistence
    lib.saveToFile("binary/data.bin");
    
    std::cout << "Library System initialized and state saved." << std::endl;
    return 0;
}