#include "Date.h"
#include "Exceptions.h"
#include <ctime>
#include <iomanip>
#include <sstream>

bool Date::isValidDate(int d, int m, int y) const {
    if (y < 1900 || m < 1 || m > 12 || d < 1 || d > 31) return false;
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return false;
    if (m == 2) {
        bool isLeap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if (d > (isLeap ? 29 : 28)) return false;
    }
    return true;
}

Date::Date() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    if (!isValidDate(d, m, y)) {
        throw InvalidInputException("Invalid date values provided.");
    }
}

Date::Date(const std::string& dateStr) {
    char delim1, delim2;
    std::stringstream ss(dateStr);
    ss >> day >> delim1 >> month >> delim2 >> year;
    
    if (ss.fail() || delim1 != '/' || delim2 != '/' || !isValidDate(day, month, year)) {
        throw InvalidInputException("Date format must be DD/MM/YYYY.");
    }
}

int Date::getDay() const { return day; }
int Date::getMonth() const { return month; }
int Date::getYear() const { return year; }

std::string Date::toString() const {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << day << "/"
       << std::setfill('0') << std::setw(2) << month << "/"
       << year;
    return ss.str();
}

void Date::addDays(int daysToAdd) {
    std::tm date_tm = {0, 0, 0, day, month - 1, year - 1900, 0, 0, 0};
    std::time_t time_val = std::mktime(&date_tm);
    time_val += daysToAdd * 24 * 60 * 60;
    std::tm* new_date = std::localtime(&time_val);
    
    day = new_date->tm_mday;
    month = new_date->tm_mon + 1;
    year = new_date->tm_year + 1900;
}

int Date::operator-(const Date& other) const {
    std::tm a = {0, 0, 0, day, month - 1, year - 1900, 0, 0, 0};
    std::tm b = {0, 0, 0, other.day, other.month - 1, other.year - 1900, 0, 0, 0};
    
    std::time_t x = std::mktime(&a);
    std::time_t y = std::mktime(&b);
    
    if (x != (std::time_t)(-1) && y != (std::time_t)(-1)) {
        return std::difftime(x, y) / (60 * 60 * 24);
    }
    return 0;
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os << date.toString();
    return os;
}