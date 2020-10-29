#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Date
{
    int day, month, year;
};

bool is_earlier(const Date& a, const Date& b)
{
    if(a.year != b.year)
        return a.year < b.year;
    if(a.month != b.month)
        return a.month < b.month;
    return a.day < b.day;
}

struct Person
{
    string name, surname;
    Date bday;
};

int main()
{
    int n;
    cin >> n;
    vector<Person> v(n);

    for(int i = 0; i < n; ++i)
    {
        char dummy;
        cin >> v[i].name >> v[i].surname;
        cin >> v[i].bday.day >> dummy >> v[i].bday.month >> dummy >> v[i].bday.year;
    }

    sort(v.begin(), v.end(), [](const Person& p1, const Person& p2)
    {
        if(is_earlier(p1.bday, p2.bday) || is_earlier(p2.bday, p1.bday))
            return is_earlier(p1.bday, p2.bday);
        if(p1.surname != p2.surname)
            return p1.surname < p2.surname;
        return p1.name < p2.name;     
    });

    for(const auto&el : v)
    {
        cout << el.name << " " << el.surname << endl;
    }

}
