# Library Management System (C++)

A robust, object-oriented Library Management System designed to handle books, members, and transactions with file-based persistence.

## Features
- **OOP Design**: Utilizes inheritance, polymorphism, and encapsulation.
- **Efficient Management**: Uses STL containers (`unordered_map`) for $O(1)$ ISBN lookups.
- **Persistence**: Supports saving/loading via binary files for performance and text-based configuration.
- **Fine System**: Automated late-fee calculation using configurable rates.
- **Robustness**: Custom exception handling for errors (e.g., duplicate records, borrow limits).

## Project Structure
- `include/`: Header files (.h)
- `src/`: Implementation files (.cpp)
- `data/`: Configuration files (config.txt)
- `binary/`: Persistence storage (data.bin)
- `tests/`: Automated test suite

## How to Compile & Run
1. Ensure you have `g++` installed.
2. Compile all source files:
   `g++ -std=c++17 -Iinclude src/*.cpp -o library_system`
3. Run the executable:
   `./library_system`

## Future Improvements
- Multi-threaded file I/O for large datasets.
- GUI implementation using Qt or similar frameworks.