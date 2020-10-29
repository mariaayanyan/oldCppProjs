#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v;
    ifstream fin("input.txt");  
    istream_iterator<int> it(fin);

    copy(it, istream_iterator<int>(), back_inserter(v));

    for(int i = 0; i < v.size(); ++i)
        cout << v[i] << " ";
}