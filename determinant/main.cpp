#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    while(b)
    {
        a %= b;
        swap(a, b);
    }

    return a;
}

int lcm(int a, int b)
{
    return a/gcd(a, b)*b;
}

void gauss(vector < vector <int> > &matrix, int &sgn)
{
    sgn = 1;
    for(int r = 0; r < matrix.size(); ++r)
    {
        int temp = r;
        while(temp < matrix.size() && matrix[temp][r] == 0)
            ++temp;

        if(temp == matrix.size())
            continue;

        if(r != temp)
        {
            swap(matrix[r], matrix[temp]);
            sgn = -sgn;
        }

        for(int i = r + 1; i < matrix.size(); ++i)
        {
            if(matrix[i][r] == 0)
                continue;

            int LCM = lcm(matrix[r][r], matrix[i][r]);
            int r1 = LCM/matrix[r][r];
            int r2 = LCM/matrix[i][r];

            sgn *= r2;
            matrix[i][r] = 0;

            for(int j = r + 1; j < matrix.size(); ++j)
            {
                matrix[i][j] = r2*matrix[i][j] - matrix[r][j]*r1;
            }

            for(int i = 0; i < matrix.size(); ++i)
            {
                for(int j = 0; j < matrix.size(); ++j)
                    cout << matrix[i][j] << " ";
                cout << endl;
            }
            cout << endl;

        }
    }

}
long long det(vector< vector<int> > &matrix)
{
    long long ans = 1;
    int div;
    gauss(matrix, div);

    for(int i = 0; i < matrix.size(); ++i)
        ans *= matrix[i][i];

    return ans/div;
}

int main()
{
    int n;
    cin >> n;

    vector< vector <int> > matrix(n, vector<int>(n));

    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            cin >> matrix[i][j];

        cout << det(matrix) << endl;

}
