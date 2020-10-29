#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
#include <utility>
using namespace std;
bool ok(char a)
{
    return a == 'R' || a == 'S' || a == 'P';
}

vector<pair<char, char> > win = {{'R', 'S'}, {'S', 'P'}, {'P', 'R'}};

int trans(char a, char b)
{
    bool A = ok(a), B = ok(b);
    if(a == b || (!A && !B))
        return 0;
    if(A && !B)
        return 1;
    if(!A && B)
        return 2;

    return (find(win.begin(), win.end(), make_pair(a, b)) == win.end()) + 1;    
}
int main()
{
    string a, b;
    vector<int> res;
    cin >> a >> b;
    
    transform(a.begin(), a.end(), b.begin(), back_inserter(res), trans);
    for(auto el : res)
    {
        if(el == 0)
        {
            cout << "Draw\n";
            continue;
        }
        cout << "Player " << el << " wins\n"; 
    }

    
}