#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    sort(str.begin(), str.end());
    str.erase(unique(str.begin(), str.end()), str.end());

    cout << str << endl;
}