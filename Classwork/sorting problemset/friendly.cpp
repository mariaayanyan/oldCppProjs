#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<char> bucketN(10), bucketM(10);

    while(n)
    {
        bucketN[n%10] = 1;
        n/=10;
    }

    while(m)
    {
        if(!bucketN[m%10])
        {
            cout << "No\n";
            return 0;
        }
        bucketM[m%10] = 1;
        m/=10;
    }

    cout << (bucketN == bucketM ? "Yes\n" : "No");

}