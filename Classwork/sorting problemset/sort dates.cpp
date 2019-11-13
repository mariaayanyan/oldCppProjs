#include <iostream>
#include <vector>
#include <algorithm>

struct date
{
    std::string day, month, year;
    date(std::string day, std::string month, std::string year) :day(day), month(month), year(year)
    {

    }
    friend bool operator >(const date &a, const date &b)
    {
        if(a.year != b.year)
            return (a.year > b.year);

        if(a.month != b.month)
            return (a.month > b.month);

        return a.day > b.day;
    }

};


std::ostream &operator<<(std::ostream& out, const date& d)
{
    return out << d.day << "/" << d.month << "/" << d.year << '\n';
}

void sort(std::vector<date> &v)
{
    for(int i = 0; i < v.size(); ++i)
        for(int j = i + 1; j < v.size(); ++j)
            if(v[i] > v[j])
                std::swap(v[i],v[j]);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    std::vector<date> d;

    char dummy;
    while(std::cin >> dummy)
    {
        std::cin.putback(dummy);
        std::string day, month, year;

        getline(std::cin, day, '/');
        getline(std::cin, month, '/');

        getline(std::cin, year);
        d.emplace_back(day, month, year);
    }

    sort(d);

    for(int i = 0; i < d.size(); ++i)
    std::cout << d[i];

}