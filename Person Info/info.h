#pragma once
#include "person.h"
class Info : public Person
{
    std::string address;
    bool education;
public:
    Info() = default;
    Info(std::string initName, date d, std::string address, bool education);
    void read();
    void print();
    bool isHigh();
};