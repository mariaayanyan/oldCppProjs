#include <iostream>
#include <numeric>
#include <vector>
#include <iomanip>
using namespace std;
int main()
{
    double s;
    int n;
    cin >> s >> n;

    vector<double> p(n);
    for(int i = 0; i < n; ++i)
        cin >> p[i];
    
    cout << fixed << setprecision(2) << accumulate(p.begin(), p.end(), s, [](double a, double b){return a + a*b/100;});
    
}
