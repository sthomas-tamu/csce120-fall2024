#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
  private:
    int year;
    int month;
    int day;
        
    bool validDay(int _day) const;
    bool validMonth(int _month) const;
    bool validYear(int _year) const;
    
  public:
    // Constructors
    Date() : year(2021), month(1), day(1) {}
    Date(int year, int month, int day);

    std::string to_string() const;

    // Getters and Setters
    int getDay() const { return day; }
    void setDay(int day);

    int getMonth() const { return month; }
    void setMonth(int month);

    int getYear() const { return year; }
    void setYear(int year);

    // Operators
    // add == declaration
    bool operator==(const Date& other) const;
    
    // add < declaration
    bool operator<(const Date& other) const;
   
}; 
#endif
