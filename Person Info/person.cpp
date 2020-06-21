#include "person.h"
#include <iostream>
Person::Person(std::string initName, date d) : name(initName), d(d)
{

}
void Person::read()
{
    //std::cin.ignore();
    std::getline(std::cin, name);
    std::cin >> d;
}   
void Person::print() const
{
    std::cout << "Name: " << name << "\nBirthday: " << d << '\n';
}
date Person::GetBirthdayDate() const
{
    return d;
}
