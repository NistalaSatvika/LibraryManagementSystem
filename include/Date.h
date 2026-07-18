#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

    bool isValidDate(int d, int m, int y) const;

public:
    Date();
    Date(int d, int m, int y);
    Date(const std::string& dateStr);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    std::string toString() const;
    void addDays(int days);

    int operator-(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator==(const Date& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Date& date);
};

#endif // DATE_H