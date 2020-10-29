#include <iostream>
#include <string>
#include <numeric>
using namespace std;
int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    cout << inner_product(s1.begin(), s1.end(), s2.begin(), 0, 
    [](char a, char b){return a + b;}, [](int a, int b){return a == b;}) << endl;
}   