#include "ConfigReader.h"
#include <fstream>
#include <sstream>

ConfigReader::ConfigReader(const std::string& filename) {
    // Populate with fallback defaults just in case the file is missing
    configData["BookFinePerDay"] = 5.0;
    configData["AudiobookFinePerDay"] = 10.0;
    
    loadConfig(filename);
}

void ConfigReader::loadConfig(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return; // Silent fail to defaults if file is not found (or we could throw FileNotFoundException)
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty() || line[0] == '#') continue; // Skip comments and empty lines
        
        std::istringstream is_line(line);
        std::string key;
        if (std::getline(is_line, key, '=')) {
            std::string valueStr;
            if (std::getline(is_line, valueStr)) {
                configData[key] = std::stod(valueStr);
            }
        }
    }
}

double ConfigReader::getFineRate(const std::string& bookType) const {
    std::string key = bookType + "FinePerDay";
    auto it = configData.find(key);
    if (it != configData.end()) {
        return it->second;
    }
    return 0.0;
}