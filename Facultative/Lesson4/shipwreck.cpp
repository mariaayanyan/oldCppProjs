#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Passenger
{
    string name;
    int status;
};

int convert(string s)
{
    if(s == "rat")
        return 0;
    if(s == "woman" || s == "child")
        return 1;
    if(s == "man")
        return 2;
    return 3;   
}

int main()
{
    int n;
    cin >> n;

    vector<Passenger> v(n);
    for(int i = 0; i < n; ++i)
    {
        cin >> v[i].name;
        string status;
        cin >> status;
        v[i].status = convert(status);
    }

    sort(v.begin(), v.end(), [](const Passenger& p1, const Passenger& p2){return p1.status < p2.status;});

    for(const auto &el : v)
        cout << el.name << endl;
}
