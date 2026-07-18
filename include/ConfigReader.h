#ifndef CONFIG_READER_H
#define CONFIG_READER_H

#include <string>
#include <unordered_map>

class ConfigReader {
private:
    std::unordered_map<std::string, double> configData;
    void loadConfig(const std::string& filename);

public:
    explicit ConfigReader(const std::string& filename = "data/config.txt");
    
    // Pass "Book" or "Audiobook" to get the respective rate
    double getFineRate(const std::string& bookType) const; 
};

#endif // CONFIG_READER_H