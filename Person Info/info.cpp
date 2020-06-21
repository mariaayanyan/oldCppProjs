#include "info.h"
#include <iostream>
Info::Info(std::string initName, date d, std::string address, bool education) : Person(initName, d), address(address), education(education)
{
    
}
void Info::read()
{   
    Person::read();
    std::cin.ignore();
    std::getline(std::cin, address);
    std::cin >> education;
}
void Info::print()
{
    Person::print();
    std::cout << "Address: " << address << "\nEducation: " << (education ? "High" : "Secondary") << "\n";
}
bool Info::isHigh()
{
    return education;   
}
