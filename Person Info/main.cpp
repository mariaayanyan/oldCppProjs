#include "info.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<Info> Citizenr(4);

    for(int i = 0; i < Citizenr.size(); ++i)
    {
        Citizenr[i].read();
        Citizenr[i].print();
    }   

    date d;
    std::cin >> d;

    int count = 0;
    for(int i = 0; i < Citizenr.size(); ++i)
    {
        if(Citizenr[i].isHigh() && Citizenr[i].GetBirthdayDate() < d)
        {
            ++count;
            Citizenr[i].print();
            std::cout << '\n';
        }
    }

    if(count == 0)
    {
        std::cout << "None found\n";
    }
}
//cd "/home/maria/Projects/Personal Training/Person Info/" && g++ info.cpp person.cpp main.cpp -o main && "/home/maria/Projects/Personal Training/Person Info/"main 
//name surname                                                                             
// 1/2/1999 
// street, building
// 1
// name1 12/3/2002 add 0
// name1 12/3/2002 add 0
// Maria Ayanyan 
// 14/12/2001 
// Kievyan 17
// 1
