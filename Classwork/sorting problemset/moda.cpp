#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> bucket(2000);

    for(int i = 0; i < n; ++i)
    {
        int tmp;
        cin >> tmp;

        ++bucket[tmp + 1000];
    }

    int mx = 0;

    for(int i = 1; i < 2000; ++i)
    {
        if(bucket[mx] <= bucket[i])
            mx = i;
    }

    cout << mx - 1000;

}