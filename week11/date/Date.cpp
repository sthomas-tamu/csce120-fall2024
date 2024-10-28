#include "Date.h"

#include <stdexcept>
#include <iostream>
#include <sstream>

using std::runtime_error, std::cout, std::endl, std::invalid_argument;

Date::Date(int year, int month, int day): 
    year(year), month(month), day(day) {
        if (!validYear(this->year))
            throw std::invalid_argument("Invalid year");

        if (!validMonth(this->month))
            throw std::invalid_argument("Invalid month");

    	// check validDay last since it depends on having a correct month
        if (!validDay(this->day))
            throw std::invalid_argument("Invalid day");
  }


bool Date::validYear(int year) const {
    return (year >= 1 && year <= 3000);
}


bool Date::validMonth(int month) const {
    return (month >= 1 && month <= 12);
}
 

bool Date::validDay(int day) const {
    if (day < 1 || day > 31) {
        return false;
    }

    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return true;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            return (day <= 30);
            break;
        case 2:
            if ((year % 4) == 0) { //a leap year
                return (day <= 29);
            } else {
                return (day <= 28);
            }
            break;
        default:
            return false;
    }
}

 
std::string Date::to_string() const {
    std::ostringstream oss;
    oss << month << "/" << day << "/" << year;
    return oss.str();
}


void Date::setDay(int day) {
    if (!validDay(day)) {
        throw runtime_error("Invalid Day");
    }

    this->day = day;
}

void Date::setMonth(int month) {
    if (!validMonth(month)) {
        throw runtime_error("Invalid Month");
    }

    this->month = month;
}

void Date::setYear(int year) {
    if (!validYear(year)) {
        throw runtime_error("Invalid Year");
    }

    this->year = year;
}


// add == definition
bool Date::operator==(const Date& other) const {
    return ((this->year == other.year) && 
            (this->month == other.month) && 
            (this->day == other.day));
}

// add < defintion
bool Date::operator<(const Date& other) const {
    if (this->year < other.year) {
        return true;
    } else if (this->year == other.year) {
        if (this->month < other.month) {
            return true;
        } else if (this->month == other.month) {
            return (this->day < other.day);
        }
        return false;
    }
    return false;
}
