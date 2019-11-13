#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

int main()
{
    srand(time(0));

    int n, k;
    std::cin >> n >> k;

    int div = 0;
    for(int i = 0; i < k; ++i)
    {
        int a = rand()% (n/2) + 1, b = rand()% (n/2) + 1 + n/2;
        div += !(b%a);
    }

    std::cout << std::fixed << std::setprecision(8) << 1.0*div/k;

}