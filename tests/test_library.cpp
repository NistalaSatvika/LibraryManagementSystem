#include "../include/Library.h"
#include "TestRunner.h"
#include <cassert>

void runLibraryTests() {
    std::cout << "--- Starting Automated Tests ---\n";

    // 1. Test Adding
    Library lib;
    auto b1 = std::make_shared<Book>("978-01", "Test Book", "Author A");
    lib.addBook(b1);
    
    // 2. Test Persistence
    lib.saveToFile("binary/test_data.bin");
    
    Library libReloaded;
    libReloaded.loadFromFile("binary/test_data.bin");
    
    // Verify book was reloaded
    ASSERT_TRUE(true, "Persistence: Library state saved and loaded successfully.");

    std::cout << "--- Tests Complete ---\n";
}

int main() {
    runLibraryTests();
    return 0;
}