#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
  private:
    int year;
    int month;
    int day;
        
    bool validDay(int _day);
    bool validMonth(int _month);
    bool validYear(int _year);
    
  public:
    // Constructors
    Date() : year(2021), month(1), day(1) {}
    Date(int year, int month, int day);

    std::string to_string();

    // Getters and Setters
    int getDay() { return day; }
    void setDay(int day);

    int getMonth() { return month; }
    void setMonth(int month);

    int getYear() { return year; }
    void setYear(int year);

    // Operators
    // add == declaration
    
    // add < declaration
   
}; 
#endif
