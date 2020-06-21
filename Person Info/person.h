#pragma once
#include <string>
#include <iostream>
struct date
{
    int year, month, day;
    friend std::istream &operator>>(std::istream &input, date &d)
    {
        char dummy;
        input >> d.day >> dummy >> d.month >> dummy >> d.year;
        return input;
    }
    friend std::ostream &operator<<(std::ostream &output, const date &d)
    {
        output << d.day << "/" << d.month << "/" << d.year;
        return output;
    }
    bool operator<(const date& d)
    {
        if(d.year != this->year)
            return this->year < d.year;
        
        if(d.month != this->month)
            return this->month < d.month;

        return this->day < d.day;
    }
};
class Person
{
public:
    Person() = default;
    Person(std::string initName, date d); //constructor
    void read(); //input function
    void print() const; //prints the info
    date GetBirthdayDate() const; //returns the birthday date
    ~Person() = default;
protected:
    std::string name; //name, surname
    date d; //birthday
};
